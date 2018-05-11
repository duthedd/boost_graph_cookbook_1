#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
#include "load_directed_custom_edges_and_vertices_graph_from_dot.h"
#include "load_directed_custom_edges_and_vertices_graph_from_dot_demo.impl"

#include <set>
#include <boost/test/unit_test.hpp>
#include "add_custom_edge.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_custom_edges_and_vertices_markov_chain.h"
#include "create_nasty_directed_custom_edges_and_vertices_graph.h"
#include "get_sorted_custom_edge_my_edges.h"
#include "file_to_vector.h"
#include "is_regular_file.h"
#include "install_vertex_custom_type.h"
#include "my_custom_vertex.h"
#include "save_custom_edges_and_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(load_directed_custom_edges_and_vertices_graph_from_dot_thorough)
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_custom_edges_and_vertices_graph();
    const std::string filename{
      "load_directed_custom_edges_and_vertices_graph_from_dot_test.dot"
    };
    save_custom_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_my_custom_edges(g) == get_my_custom_edges(h));
  }
  //Basic tests: nasty graph
  {
    auto g = create_nasty_directed_custom_edges_and_vertices_graph();
    const std::string filename{
      "load_directed_custom_edges_and_vertices_graph_from_dot_test.dot"
    };
    save_custom_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    //get_my_custom_edges returns the unsorted edge,
    //to compare the my_custom_edges before and after, its results must be sorted
    const auto a = get_sorted_custom_edge_my_edges(g);
    const auto b = get_sorted_custom_edge_my_edges(h);
    BOOST_CHECK(a == b);
  }
  //Create the picture 'load_directed_custom_edges_and_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_custom_edges_and_vertices_markov_chain();
    const std::string base_filename{"create_custom_edges_and_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = file_to_vector(dot_filename);
    const auto h = load_directed_custom_edges_and_vertices_graph_from_dot(dot_filename);
    save_custom_edges_and_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = file_to_vector(dot_filename);
    BOOST_CHECK(old_text == new_text);
    convert_dot_to_svg(dot_filename, svg_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  
}

BOOST_AUTO_TEST_CASE(load_directed_custom_edges_and_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_directed_custom_edges_and_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_directed_custom_edges_and_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
