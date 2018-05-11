#include "create_named_vertices_path_graph.h"
#include "create_named_vertices_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "load_undirected_named_vertices_graph_from_dot.h"
#include "save_named_vertices_graph_to_dot.h"
#include "get_vertex_names.h"

BOOST_AUTO_TEST_CASE(create_named_vertices_path_graph_thorough)
{
  //Basic tests
  {
    const auto g = create_named_vertices_path_graph( {} );
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 0);
  }
  {
    const std::vector<std::string> names = {"X"};
    const auto g = create_named_vertices_path_graph(names);
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 1);
    BOOST_CHECK(get_vertex_names(g) == names);
  }
  {
    const std::vector<std::string> names = {"X", "Y"};
    const auto g = create_named_vertices_path_graph(names);
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(get_vertex_names(g) == names);
  }
  {
    const std::vector<std::string> names = {"X", "Y", "Z"};
    const auto g = create_named_vertices_path_graph(names);
    BOOST_CHECK(boost::num_edges(g) == 2);
    BOOST_CHECK(boost::num_vertices(g) == 3);
    BOOST_CHECK(get_vertex_names(g) == names);
  }
  #ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
  //Create the .dot and .svg of the 'create_named_vertices_path_graph' chapter
  //for (const int n: {3,4, 5} )
  {
    const std::vector<std::string> names = {"A", "B", "C", "D"};
    const auto g = create_named_vertices_path_graph(names);
    const std::string base_filename{"create_named_vertices_path_graph_4"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    const auto h = load_undirected_named_vertices_graph_from_dot(dot_filename);
    BOOST_CHECK(get_vertex_names(g) == get_vertex_names(h)); //Maybe sort first?

    convert_dot_to_svg(dot_filename,svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
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
  #endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

}
