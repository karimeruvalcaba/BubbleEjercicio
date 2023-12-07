#ifndef MAP_H
#define MAP_H
#include "Dungeon.h"
#include "LinkedList.h"
#include "Monster.h"
#include <vector>
using namespace std;

class Map {
private:
  LinkedList<Dungeon> dungeonsList;
  int maxDungeons;

public:
  Map(int maxDungeons);
  void initializeMap(LinkedList<Monster> monsterList, int playerPosition);
  void displayMap();
  Dungeon getNextDungeon(int dungeonIndex);
};

#endif
