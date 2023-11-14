#ifndef MAP_H
#define MAP_H
#include "Dungeon.h"
#include "Monster.h"
#include "LinkedList.h"
#include <vector>
using namespace std;

class Map {
private:
    LinkedList<Dungeon> dungeonsList;
    int maxDungeons;

public:
    Map(int maxDungeons);
    void initializeMap(LinkedList<Monster> monsterList);
    void displayMap();

 };


#endif
