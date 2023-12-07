#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <vector>
#include "SpellAndAbility.h"

using namespace std;

class Vertex{
  private:
    SpellAndAbility data;
    vector<SpellAndAbility> dataAdj;
    bool visited;

  public:
    Vertex(SpellAndAbility data);
    void addEdge(SpellAndAbility data);
    SpellAndAbility getData();
    vector<SpellAndAbility> getAdj();
    void print();
    void setVisited(bool visited);
    bool getVisited();


};



#endif