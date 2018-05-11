
#include "add_edge_between_custom_vertices.h"
#include "add_edge_between_custom_vertices_demo.impl"

#include <boost/test/unit_test.hpp>


#include "create_empty_undirected_custom_vertices_graph.h"
#include "add_custom_vertex.h"

BOOST_AUTO_TEST_CASE(add_edge_between_custom_vertices_add_one_edge)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_custom_vertex va("Bert");
  const my_custom_vertex vb("Ernie");
  add_custom_vertex(va, g);
  add_custom_vertex(vb, g);
  add_edge_between_custom_vertices(va, vb, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

BOOST_AUTO_TEST_CASE(add_edge_between_custom_vertices_where_first_does_not_exist)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_custom_vertex va("Bert");
  const my_custom_vertex vb("Ernie");
  const my_custom_vertex vc("I do not exist");
  add_custom_vertex(va, g);
  add_custom_vertex(vb, g);
  BOOST_CHECK_THROW(
    add_edge_between_custom_vertices(vc, vb, g),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(add_edge_between_custom_vertices_where_second_does_not_exist)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_custom_vertex va("Bert");
  const my_custom_vertex vb("Ernie");
  const my_custom_vertex vc("I do not exist");
  add_custom_vertex(va, g);
  add_custom_vertex(vb, g);
  BOOST_CHECK_THROW(
    add_edge_between_custom_vertices(va, vc, g),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(add_edge_between_custom_vertices_where_edge_already_exists)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_custom_vertex va("Bert");
  const my_custom_vertex vb("Ernie");
  add_custom_vertex(va, g);
  add_custom_vertex(vb, g);
  add_edge_between_custom_vertices(va, vb, g);
  BOOST_CHECK_THROW(
    add_edge_between_custom_vertices(va, vb, g),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(add_edge_between_custom_vertices_add_another_edge)
{
  using another_vertex = std::string;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_custom_type_t, another_vertex
    >
  >;
  another_graph g;
  const another_vertex va("Bert");
  const another_vertex vb("Ernie");
  add_custom_vertex(va, g);
  add_custom_vertex(vb, g);
  add_edge_between_custom_vertices(va, vb, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}
