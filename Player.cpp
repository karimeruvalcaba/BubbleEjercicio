#include "Player.h"

Player::Player(string name, string type, int lp, int hp) {
  this->name = name;
  this->type = type;
  this->lp = lp;
  this->hp = hp;
}

Player::Player() {
  this->name = "";
  this->type = "";
  this->lp = 100;
  this->hp = 10;
}
string Player::getName() { return name; }

string Player::getType() { return type; }

int Player::getLp() { return lp; }

int Player::getHp() { 
  return hp; 
}

Player *Player::getNext() const { return next; }

void Player::setName(string name) { this->name = name; }

void Player::setType(string type) { this->type = type; }

void Player::setLp(int lp) {
    if (lp <= 0) {
        this->lp = 0; 
    } else if (lp > 999) {
        this->lp = 999; 
    } else {
        this->lp = lp; 
    }
}


void Player::setHp(int hp) { 
   if (hp <= 0) {
      this->hp = 0;
    } else {
      this->hp = hp;
    }
  }

void Player::setNext(Player *next) { this->next = next; }