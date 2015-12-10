#include "get_edge_descriptors.h"

#include "get_edge_descriptors_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "get_n_vertices.h"
#include "is_self_loop.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_edge_descriptors_test() noexcept
{
  //Empty directed graph
  {
    const auto g = create_empty_directed_graph();
    const auto eds = get_edge_descriptors(g);
    assert(eds.empty());
  }
  //Empty undirected graph
  {
    const auto g = create_empty_undirected_graph();
    const auto eds = get_edge_descriptors(g);
    assert(eds.empty());
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 1);
    assert(!is_self_loop(eds[0], g));
  }
  //Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 3);
    assert(!is_self_loop(eds[0], g));
    assert(!is_self_loop(eds[1], g));
    assert(!is_self_loop(eds[2], g));
    //assert(target(eds[0], g) == source(eds[1], g));
  }
  get_edge_descriptors_demo();
  std::cout << __func__ << ": OK" << '\n';
}