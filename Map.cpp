#include "Map.h"
#include "LinkedList.h"
#include <cstdlib>
#include <ctime>

Map::Map(int maxDungeons) : maxDungeons(maxDungeons) { srand(time(0)); }

void Map::initializeMap(LinkedList<Monster> monsterList, int playerPosition) {

  for (int i = 0; i < maxDungeons; i++) {
    int randomIndex = rand() % monsterList.getSize();
    Monster randomMonster = monsterList.getAtPos(randomIndex);
    Dungeon dungeon("Dungeon " + std::to_string(i + 1), randomMonster);

    dungeonsList.addNode(dungeon);
  }
}

Dungeon Map::getNextDungeon(int dungeonIndex) {
  return dungeonsList.getAtPos(dungeonIndex);
}

void Map::displayMap() { dungeonsList.print(); }
