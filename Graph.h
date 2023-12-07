#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Graph {
private:
  vector<Vertex> vertices;

public:
  Graph();
  void addVertex(SpellAndAbility data);
  void addEdge(SpellAndAbility vertex1, SpellAndAbility vertex2);
  void print();
};

#endif