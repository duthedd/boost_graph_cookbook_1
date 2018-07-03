#include "set_my_bundled_vertex.h"
#include "set_my_bundled_vertex_demo.impl"

#include "add_bundled_vertex.h"
#include "create_empty_undirected_bundled_vertices_graph.h"
#include "find_first_bundled_vertex_with_my_vertex.h"
#include "get_my_bundled_vertex.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(set_my_bundled_vertex_thorough)
{
  {
    auto g = create_empty_undirected_bundled_vertices_graph();
    const my_bundled_vertex old_name{ "Dex" };
    add_bundled_vertex(old_name, g);
    const auto vd = find_first_bundled_vertex_with_my_vertex(old_name, g);
    BOOST_CHECK(get_my_bundled_vertex(vd, g) == old_name);
    const my_bundled_vertex new_name{ "Diggy" };
    set_my_bundled_vertex(new_name, vd, g);
    BOOST_CHECK(get_my_bundled_vertex(vd, g) == new_name);
  }
}
