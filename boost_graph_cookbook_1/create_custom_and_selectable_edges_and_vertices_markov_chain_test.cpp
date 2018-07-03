#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "create_custom_and_selectable_edges_and_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_my_custom_vertexes.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "get_vertex_names.h"
#include "get_vertex_selectednesses.h"

BOOST_AUTO_TEST_CASE(
  create_custom_and_selectable_edges_and_vertices_markov_chain_use)
{
  const auto g = create_custom_and_selectable_edges_and_vertices_markov_chain();
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 4);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 4);
  const auto vip = get_vertex_iterators(g);
  BOOST_CHECK(vip.first != vip.second);
  const auto vds = get_vertex_descriptors(g);
  BOOST_CHECK(vds.size() == 2);
  const auto eip = get_edge_iterators(g);
  BOOST_CHECK(eip.first != eip.second);
  const auto eds = get_edge_descriptors(g);
  BOOST_CHECK(eds.size() == 4);
  // Can get the my_custom_vertex objects
  const std::vector<my_custom_vertex> vertex_my_custom_vertexes{
    get_my_custom_vertexes(g)
  };
  const std::vector<my_custom_vertex> expected_my_custom_vertexes{
    my_custom_vertex("Sunny", "Yellow thing", 1.0, 2.0),
    my_custom_vertex("Rainy", "Grey things", 3.0, 4.0)
  };
  BOOST_CHECK(expected_my_custom_vertexes == vertex_my_custom_vertexes);
  // Can get the selectednesses
  const std::vector<bool> expected_selectednesses{ true, false };
  const std::vector<bool> vertex_selectednesses{ get_vertex_selectednesses(g) };
  BOOST_CHECK(expected_selectednesses == vertex_selectednesses);
}
