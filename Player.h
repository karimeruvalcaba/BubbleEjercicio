#ifndef PLAYER_H
#define PLAYER_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
  string name;
  string type; // Es la raza
  int lp;
  int hp;
  Player *next;

public:
  Player(string name, string type, int lp, int hp);
  Player();
  // GETTERS
  string getName();
  string getType();
  int getLp();
  int getHp();
  Player *getNext() const;
  // SETTERS
  void setName(string name);
  void setType(string type);
  void setLp(int lp);
  void setHp(int hp);
  void setNext(Player *);

  friend ostream &operator<<(ostream &os, const Player &m) {
    os << "  Name: " << m.name << ", Type: " << m.type << ", Lp: " << m.lp
       << ", Hp: " << m.hp << endl;
    return os;
  }

  int operator>(Player m) {
    if (this->name != m.name) {
      return this->type > m.type;
    } else {
      return this->type > m.type;
    }
  }
  int operator<(Player m) {
    if (this->name != m.name) {
      return this->name < m.name;
    } else {
      return this->type > m.type;
    }
  }
  bool operator==(Player m) {
    return (this->name == m.name) && (this->type > m.type);
  }
};

#endif
