#include "Spell.h"

Spell::Spell(string name, string description, int atk, int def){
  this->name=name;
  this->description=description;
  this->atk=atk;
  this->def=def;
}


Spell::Spell(){
  this->name="";
  this->description="";
  this->atk=0;
  this->def=0;
}
string Spell::getName(){
    return name;
}

string Spell::getDescription(){
    return description;
}

int Spell::getAtk(){
    return atk;
}

int Spell::getDef(){
    return def;
}

Spell* Spell::getNext() const {
  return next;
}

void Spell::setName(string name){
    this->name=name;
}

void Spell::setDescription(string description){
    this->description=description;
}

void Spell::setAtk(int atk){
    this->atk=atk;
}

void Spell::setDef(int def){
    this->def=def;
}

void Spell::setNext(Spell* next) {
  this->next=next;
}