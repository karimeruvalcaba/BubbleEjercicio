#include "Vertex.h"

Vertex::Vertex(SpellAndAbility data):data(data){
    this->data = data;
    this->visited = false;
}
void Vertex::addEdge(SpellAndAbility data){
    dataAdj.push_back(data);
}
SpellAndAbility Vertex::getData(){
    return data;
}
vector<SpellAndAbility> Vertex::getAdj(){
    return dataAdj;
}
void Vertex::print(){
    cout << "Vertex: " << data << endl;
    cout << "Adjacency List: ";
    for(int i = 0; i < dataAdj.size(); i++){
        cout << dataAdj[i] << " ";
    }
    cout << endl;
}

void Vertex::setVisited(bool visited){
    this->visited = visited;
}
bool Vertex::getVisited(){
    return visited;
}