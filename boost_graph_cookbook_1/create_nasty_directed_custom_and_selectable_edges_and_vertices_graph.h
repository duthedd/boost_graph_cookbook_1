#ifndef CREATE_NASTY_DIRECTED_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_NASTY_DIRECTED_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_GRAPH_H

#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<
      boost::vertex_is_selected_t, bool
    >
  >,
  boost::property<
    boost::edge_custom_type_t, my_custom_edge,
    boost::property<
      boost::edge_is_selected_t, bool
    >
  >
>
create_nasty_directed_custom_and_selectable_edges_and_vertices_graph();

#endif // CREATE_NASTY_DIRECTED_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_GRAPH_H
