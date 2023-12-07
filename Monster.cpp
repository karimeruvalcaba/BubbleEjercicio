#include "Monster.h"

Monster::Monster(string name, double cr, string type, string size, int ac, int hp, string align){
  this->name=name;
  this->cr=cr;
  this->type=type;
  this->size=size;
  this->ac=ac;
  this->hp=hp;
  this->align=align;
  
}
Monster::Monster(){
  this->name="";
  this->cr=0;
  this->type="";
  this->size="";
  this->ac=0;
  this->hp=0;
  this->align="";

}
string Monster::getName(){
    return name;
}

double Monster::getCr(){
    return cr;
}

string Monster::getType(){
    return type;
}

string Monster::getSize(){
    return size;
}

int Monster::getAc(){
    return ac;
}

int Monster::getHp(){
    return hp;
}

string Monster::getAlign(){
    return align;
}

Monster* Monster::getNext() const {
  return next;
}

void Monster::setName(string name){
    this->name=name;
}
void Monster::setCr(double cr){
    this->cr=cr;
}

void Monster::setType(string type){
    this->type=type;
}

void Monster::setSize(string size){
    this->size=size;
}

void Monster::setAc(int ac){
    this->ac=ac;
}

void Monster::setHp(int hp){
   if (hp <= 0) {
      this->hp = 0;
    } else {
      this->hp = hp;
    }
  }


void Monster::setAlign(string align){
    this->align=align;
}

void Monster::setNext(Monster* next) {
  this->next=next;
}