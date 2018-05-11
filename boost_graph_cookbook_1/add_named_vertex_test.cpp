#include "add_named_vertex.h"
#include "add_named_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_named_vertices_graph.h"


#include "get_vertex_names.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"

BOOST_AUTO_TEST_CASE(add_named_vertex_add_one)
{
  auto g = create_empty_undirected_named_vertices_graph();
  BOOST_CHECK(get_vertex_descriptors(g).size() == 0);
  BOOST_CHECK(get_edge_descriptors(g).size() == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string vertex_name{"X"};
  add_named_vertex(vertex_name, g);
  BOOST_CHECK(get_vertex_descriptors(g).size() == 1);
  BOOST_CHECK(get_edge_descriptors(g).size() == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<std::string> vertex_names{get_vertex_names(g)};
  const std::vector<std::string> expected_names{vertex_name};
  BOOST_CHECK(vertex_names == expected_names);
}

BOOST_AUTO_TEST_CASE(add_named_vertex_add_two)
{
  auto g = create_empty_undirected_named_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string vertex_name_1{"A"};
  const std::string vertex_name_2{"B"};
  add_named_vertex(vertex_name_1, g);
  add_named_vertex(vertex_name_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<std::string> vertex_names{get_vertex_names(g)};
  const std::vector<std::string> expected_names{vertex_name_1,vertex_name_2};
  BOOST_CHECK(vertex_names == expected_names);
}

BOOST_AUTO_TEST_CASE(add_named_vertex_add_another_type)
{
  using another_vertex_name = double;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_name_t, std::string
    >
  >;
  another_graph g;
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const another_vertex_name vertex_name_1{123.456};
  const another_vertex_name vertex_name_2{3.14};
  add_named_vertex(vertex_name_1, g);
  add_named_vertex(vertex_name_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
