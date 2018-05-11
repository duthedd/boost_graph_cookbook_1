#include "create_all_direct_neighbour_named_vertices_subgraphs.h"
#include "create_all_direct_neighbour_named_vertices_subgraphs_demo.impl"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_k3_graph.h"
#include "create_named_vertices_path_graph.h"
#include "create_named_vertices_petersen_graph.h"
#include "save_named_vertices_graph_to_dot.h"
#include "has_vertex_with_name.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_named_vertices_subgraphs_thorough)
{
  //K2
  {
    const auto v = create_all_direct_neighbour_named_vertices_subgraphs(
      create_named_vertices_k2_graph()
    );
    BOOST_CHECK(v.size() == 2);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 2);
      BOOST_CHECK(boost::num_edges(g) == 1);
      const std::string va("Me");
      const std::string vb("My computer");
      BOOST_CHECK(has_vertex_with_name(va, g));
      BOOST_CHECK(has_vertex_with_name(vb, g));
    }
  }
  //K3
  {
    const auto v = create_all_direct_neighbour_named_vertices_subgraphs(
      create_named_vertices_k3_graph()
    );
    BOOST_CHECK(v.size() == 3);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 3);
      BOOST_CHECK(boost::num_edges(g) == 3);
      const std::string va("Karen");
      const std::string vb("Kristel");
      const std::string vc("Kathleen");
      BOOST_CHECK(has_vertex_with_name(va, g));
      BOOST_CHECK(has_vertex_with_name(vb, g));
      BOOST_CHECK(has_vertex_with_name(vc, g));
    }
  }
  //Path
  {
    const auto v = create_all_direct_neighbour_named_vertices_subgraphs(
      create_named_vertices_path_graph( {"A","B","C"} )
    );
    const int sz{3};
    BOOST_CHECK(sz == static_cast<int>(v.size()));
    #ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
    for (int i=0; i!=sz; ++i)
    {
      const auto g = v[i];
      const std::string base_filename{"create_all_direct_neighbour_named_vertices_subgraphs_" + std::to_string(i)};
      const std::string dot_filename{base_filename + ".dot"};
      const std::string svg_filename{base_filename + ".svg"};
      save_named_vertices_graph_to_dot(g, dot_filename);
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
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_named_vertices_subgraphs(create_named_vertices_petersen_graph());
    BOOST_CHECK(v.size() == 10);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 4);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
}
