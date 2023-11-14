#include "Map.h"
#include "LinkedList.h"
#include <cstdlib>
#include <ctime>

Map::Map(int maxDungeons) : maxDungeons(maxDungeons) {
    srand(time(0));
}

void Map::initializeMap(LinkedList<Monster> monsterList) {
  
    for (int i = 0; i < maxDungeons; i++) {
      cout << "Prueba 1" << endl;
        int randomIndex = rand() % monsterList.getSize();
        Monster randomMonster = monsterList.getAtPos(randomIndex);
      cout << "Prueba 2" << endl;
        Dungeon dungeon("Dungeon " + std::to_string(i + 1), randomMonster);
      cout << "Prueba 3" << endl;
      
        dungeonsList.addNode(dungeon);
    }
}

void Map::displayMap() {
    dungeonsList.print();
}
