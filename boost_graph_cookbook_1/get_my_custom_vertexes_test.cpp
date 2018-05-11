#include "get_my_custom_vertexes.h"
#include "get_my_custom_vertexes_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_custom_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(get_my_custom_vertexes_thorough)
{
  {
    const auto g = create_custom_vertices_k2_graph();
    const std::vector<my_custom_vertex> expected_my_custom_vertexes{
      my_custom_vertex("A","source",0.0,0.0),
      my_custom_vertex("B","target",3.14,3.14)
    };
    const std::vector<my_custom_vertex> vertexes{
      get_my_custom_vertexes(g)
    };
    BOOST_CHECK(expected_my_custom_vertexes == vertexes);
  }
}
