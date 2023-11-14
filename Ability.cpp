#include "Ability.h"

Ability::Ability(string name, string description, int atk, int def){
  this->name=name;
  this->description=description;
  this->atk=atk;
  this->def=def;
}


Ability::Ability(){
  this->name="";
  this->description="";
  this->atk=0;
  this->def=0;
}
string Ability::getName(){
    return name;
}

string Ability::getDescription(){
    return description;
}

int Ability::getAtk(){
    return atk;
}

int Ability::getDef(){
    return def;
}

Ability* Ability::getNext() const {
  return next;
}

void Ability::setName(string name){
    this->name=name;
}

void Ability::setDescription(string description){
    this->description=description;
}

void Ability::setAtk(int atk){
    this->atk=atk;
}

void Ability::setDef(int def){
    this->def=def;
}

void Ability::setNext(Ability* next) {
  this->next=next;
}