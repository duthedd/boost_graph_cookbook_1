include(any_normal.pri)

# Equivalent to:
# include(boost_graph_tutorial.pri)

include(boost_graph_tutorial_bundled_edges_and_vertices.pri)
include(boost_graph_tutorial_bundled_vertices.pri)
include(boost_graph_tutorial_custom_and_selectable_edges_and_vertices.pri)
include(boost_graph_tutorial_custom_and_selectable_vertices.pri)
include(boost_graph_tutorial_custom_edges_and_vertices.pri)
include(boost_graph_tutorial_custom_vertices.pri)
include(boost_graph_tutorial_helper.pri)
include(boost_graph_tutorial_misc.pri)
include(boost_graph_tutorial_named_and_selectable_vertices.pri)
include(boost_graph_tutorial_named_edges_and_vertices.pri)
include(boost_graph_tutorial_named_graph.pri)
include(boost_graph_tutorial_named_vertices.pri)
include(boost_graph_tutorial_no_properties.pri)
include(boost_graph_tutorial_tutorial.pri)

SOURCES += main.cpp

# USe Graphviz
LIBS += -lboost_graph
