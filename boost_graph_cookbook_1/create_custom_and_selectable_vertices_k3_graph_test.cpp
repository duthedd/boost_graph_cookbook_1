#include "create_custom_and_selectable_vertices_k3_graph.h"
#include "create_custom_and_selectable_vertices_k3_graph_demo.impl"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "has_custom_vertex_with_my_vertex.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_vertices_k3_graph_thorough)
{
  //Basic tests
  {
    const auto g = create_custom_and_selectable_vertices_k3_graph();
    BOOST_CHECK(boost::num_edges(g) == 3);
    BOOST_CHECK(boost::num_vertices(g) == 3);
    const my_custom_vertex a("Karen","red",1.1,2.2);
    const my_custom_vertex b("Kristel","black",3.3,4.4);
    const my_custom_vertex c("Kathleen","blond",5.5,6.6);
    BOOST_CHECK(has_custom_vertex_with_my_vertex(a, g));
    BOOST_CHECK(has_custom_vertex_with_my_vertex(b, g));
    BOOST_CHECK(has_custom_vertex_with_my_vertex(c, g));
  }
  #ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
  //Create the .dot and .svg of the 'create_custom_and_selectable_vertices_k3_graph' chapter
  {
    const auto g = create_custom_and_selectable_vertices_k3_graph();
    const std::string base_filename{"create_custom_and_selectable_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_and_selectable_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
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
