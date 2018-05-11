#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
#include "save_named_vertices_graph_to_dot.h"
#include "save_named_vertices_graph_to_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include <sstream>
#include "save_named_vertices_graph_to_dot_using_lambda.impl"
#include "copy_file.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_markov_chain.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_nasty_directed_named_vertices_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "set_vertex_names.h"
#include "file_to_vector.h"


BOOST_AUTO_TEST_CASE(save_named_vertices_graph_to_dot_thorough)
{
  //Create figure of named K2 graph
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{"create_named_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
  }
  //Create figure of named Markov chain graph
  {
    const auto g = create_named_vertices_markov_chain();
    const std::string base_filename{"create_named_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
  //Show it does store the vertex names
  {
    const auto g = create_named_vertices_k2_graph();

    const std::string base_filename{"save_named_vertices_graph_to_dot_test_named_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      file_to_vector(dot_filename)
    };
    BOOST_CHECK(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=Me];",
      "1[label=\"My computer\"];",
      "0--1 ;",
      "}"
    };
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
  //Show it does not store the edges' names
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::string base_filename{"save_named_vertices_graph_to_dot_test_named_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      file_to_vector(dot_filename)
    };
    BOOST_CHECK(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=top];",
      "1[label=right];",
      "2[label=left];",
      "0--1 ;",
      "1--2 ;",
      "2--0 ;",
      "}"
    };
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
  //Will it break if the vertices have named with spaces
  {
    //See load_directed_named_vertices_graph_from_dot_test
    //for nasty tests
  }
  //Compare ways of save_named_vertices_graph_to_dot to be equivalent:
  // - use boost::make_label_writes
  // - use lambda in C++11
  {
    const std::string g1_dot_filename{"g1.dot"};
    const std::string g2_dot_filename{"g2.dot"};
    const std::string h1_dot_filename{"h1.dot"};
    const std::string h2_dot_filename{"h2.dot"};
    const auto g = create_named_vertices_k2_graph();
    const auto h = create_named_vertices_markov_chain();
    save_named_vertices_graph_to_dot(g,g1_dot_filename);
    save_named_vertices_graph_to_dot_using_lambda(g,g2_dot_filename);
    save_named_vertices_graph_to_dot(h,h1_dot_filename);
    save_named_vertices_graph_to_dot_using_lambda(h,h2_dot_filename);
    BOOST_CHECK(file_to_vector(g1_dot_filename) == file_to_vector(g2_dot_filename));
    BOOST_CHECK(file_to_vector(h1_dot_filename) == file_to_vector(h2_dot_filename));
    BOOST_CHECK(file_to_vector(g1_dot_filename) != file_to_vector(h2_dot_filename));
    std::remove(g1_dot_filename.c_str());
    std::remove(g2_dot_filename.c_str());
    std::remove(h1_dot_filename.c_str());
    std::remove(h2_dot_filename.c_str());
  }
  
}

#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
