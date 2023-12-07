#include "Graph.h"
#include "SpellAndAbility.h"
Graph::Graph() {}
void Graph::addVertex(SpellAndAbility data) {
  Vertex v(data);
  vertices.push_back(v);
}
void Graph::addEdge(SpellAndAbility vertex1, SpellAndAbility vertex2) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].getData() == vertex1) {
      vertices[i].addEdge(vertex2);
    }
    if (vertices[i].getData() == vertex2) {
      vertices[i].addEdge(vertex1);
    }
  }
}

void Graph::print() {
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].print();
  }
}


