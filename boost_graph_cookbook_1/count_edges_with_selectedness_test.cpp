#include "count_edges_with_selectedness.h"
#include "count_edges_with_selectedness_demo.impl"


#include <boost/test/unit_test.hpp>


#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "add_custom_and_selectable_edge.h"

BOOST_AUTO_TEST_CASE(count_edges_with_selectedness_thorough)
{
  auto g = create_empty_directed_custom_and_selectable_edges_and_vertices_graph();
  add_custom_and_selectable_edge(
    my_custom_edge("AB"), true, g
  );
  add_custom_and_selectable_edge(
    my_custom_edge("AA"), false, g
  );
  BOOST_CHECK(count_edges_with_selectedness( true, g) == 1);
  BOOST_CHECK(count_edges_with_selectedness(false, g) == 1);
}
