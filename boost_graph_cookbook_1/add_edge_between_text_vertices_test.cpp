#include "add_edge_between_text_vertices.h"
#include "add_edge_between_text_vertices_demo.impl"
#include "add_text_vertex.h"
#include "create_empty_undirected_text_vertices_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(add_edge_between_text_vertices_once)
{
  auto g = create_empty_undirected_text_vertices_graph();
  const std::string name1{ "Bert" };
  const std::string name2{ "Ernie" };
  add_text_vertex(name1, g);
  add_text_vertex(name2, g);
  add_edge_between_text_vertices(name1, name2, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}
