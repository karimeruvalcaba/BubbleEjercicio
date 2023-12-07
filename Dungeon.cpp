#include "Dungeon.h"

Dungeon::Dungeon(string name, Monster MonsterInDungeon) {
  this->name = name;
  this->MonsterInDungeon = MonsterInDungeon;
}

Dungeon::Dungeon() {
  this->name = "";
  // this->MonsterInDungeon=MonsterInDungeon;
}

string Dungeon::getName() { return name; }

Monster Dungeon::getMonsterInDungeon() { return MonsterInDungeon; }

Dungeon *Dungeon::getNext() const { return next; }

void Dungeon::setName(string name) { this->name = name; }

void Dungeon::setMonsterInDungeon(Monster MonsterInDungeon) {
  this->MonsterInDungeon = MonsterInDungeon;
}

void Dungeon::setNext(Dungeon *next) { this->next = next; }

