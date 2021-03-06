#include "add_text_vertex.h"
#include "add_text_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_text_vertices_graph.h"

#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_texts.h"

BOOST_AUTO_TEST_CASE(add_text_vertex_add_one)
{
  auto g = create_empty_undirected_text_vertices_graph();
  BOOST_CHECK(get_vertex_descriptors(g).size() == 0);
  BOOST_CHECK(get_edge_descriptors(g).size() == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string vertex_name{ "X" };
  add_text_vertex(vertex_name, g);
  BOOST_CHECK(get_vertex_descriptors(g).size() == 1);
  BOOST_CHECK(get_edge_descriptors(g).size() == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<std::string> vertex_texts{ get_vertex_texts(g) };
  const std::vector<std::string> expected_texts{ vertex_name };
  BOOST_CHECK(vertex_texts == expected_texts);
}

BOOST_AUTO_TEST_CASE(add_text_vertex_add_two)
{
  auto g = create_empty_undirected_text_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string vertex_name_1{ "A" };
  const std::string vertex_name_2{ "B" };
  add_text_vertex(vertex_name_1, g);
  add_text_vertex(vertex_name_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<std::string> vertex_texts{ get_vertex_texts(g) };
  const std::vector<std::string> expected_texts{ vertex_name_1, vertex_name_2 };
  BOOST_CHECK(vertex_texts == expected_texts);
}
