#include "create_custom_and_selectable_vertices_path_graph.h"
#include "create_custom_and_selectable_vertices_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_path_graph_no_vertices)
{
  const auto g = create_custom_and_selectable_vertices_path_graph( {}, {} );
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
}

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_path_graph_one_vertex)
{
  const std::vector<my_custom_vertex> my_custom_vertexes {
    my_custom_vertex("X")
  };
  const auto g = create_custom_and_selectable_vertices_path_graph(my_custom_vertexes, { true });
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
}

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_path_graph_one_edge)
{
  const std::vector<my_custom_vertex> my_custom_vertexes {
    my_custom_vertex("X"),
    my_custom_vertex("Y")
  };
  const auto g = create_custom_and_selectable_vertices_path_graph(my_custom_vertexes, { true, false });
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
}

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_path_graph_one_vertex_too_few)
{
  const std::vector<my_custom_vertex> my_custom_vertexes {
    my_custom_vertex("Y") //One too few
  };
  const std::vector<bool> my_selectednesses = { true, false };

  BOOST_CHECK_THROW(
    create_custom_and_selectable_vertices_path_graph(
      my_custom_vertexes,
      my_selectednesses
    ),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_path_graph_two_edges)
{
  const std::vector<my_custom_vertex> my_custom_vertexes {
    my_custom_vertex("X"),
    my_custom_vertex("Y"),
    my_custom_vertex("Z")
  };
  const auto g = create_custom_and_selectable_vertices_path_graph(my_custom_vertexes, { false, true, false });
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
}

#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_path_graph_create_pictures)
{
//Create the .dot and .svg of the 'create_custom_and_selectable_vertices_path_graph' chapter
//for (const int n: {3,4, 5} )
  const std::vector<my_custom_vertex> my_custom_vertexes {
    my_custom_vertex("A"),
    my_custom_vertex("B"),
    my_custom_vertex("C"),
    my_custom_vertex("D")
  };
  const auto g = create_custom_and_selectable_vertices_path_graph(
    my_custom_vertexes,
    { false, true, false, false }
  );
  const std::string base_filename{"create_custom_and_selectable_vertices_path_graph_4"};
  const std::string dot_filename{base_filename + ".dot"};
  const std::string svg_filename{base_filename + ".svg"};
  save_graph_to_dot(g,dot_filename);
  BOOST_CHECK(is_regular_file(dot_filename));
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
