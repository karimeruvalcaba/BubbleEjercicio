#ifndef DUNGEON_H
#define DUNGEON_H
#include "Monster.h"
#include <iostream>
using namespace std;

class Dungeon{
  private:
    string name;
    Monster MonsterInDungeon;
    Dungeon *next;
  public:
    Dungeon(string name, Monster MonsterInDungeon);
    Dungeon();
    string getName();
    Monster getMonsterInDungeon();
    Dungeon* getNext() const;
    void setName(string name);
    void setMonsterInDungeon(Monster MonsterInDungeon);
    void setNext(Dungeon*);


    
        friend ostream& operator<<(ostream& os, const Dungeon& m){
            os<<"  Name: "<<m.name<<", Monster inside this dungeon: "<<m.MonsterInDungeon<<endl;
            return os;
        }

        int operator >(Dungeon m){
          if (this->name!=m.name){
            return this->name>m.name; 
          }else {
            return this->MonsterInDungeon>m.MonsterInDungeon;
          }
        }
        int operator <(Dungeon m){
          if (this->name!=m.name){
            return this->name<m.name; 
          }else {
            return this->MonsterInDungeon<m.MonsterInDungeon;
          }
        }
        bool operator ==(Dungeon m){
          return (this->name == m.name) && (this->MonsterInDungeon == m.MonsterInDungeon);
        }



};

#endif 