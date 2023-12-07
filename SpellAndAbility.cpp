#include "SpellAndAbility.h"

SpellAndAbility::SpellAndAbility(string name, string description, int def){
  this->name=name;
  this->description=description;
  this->def=def;
}


SpellAndAbility::SpellAndAbility(){
  this->name="";
  this->description="";
  this->def=0;
}
string SpellAndAbility::getName(){
    return name;
}

string SpellAndAbility::getDescription(){
    return description;
}

int SpellAndAbility::getDef(){
    return def;
}

SpellAndAbility* SpellAndAbility::getNext() const {
  return next;
}

void SpellAndAbility::setName(string name){
    this->name=name;
}

void SpellAndAbility::setDescription(string description){
    this->description=description;
}

void SpellAndAbility::setDef(int def){
    this->def=def;
}

void SpellAndAbility::setNext(SpellAndAbility* next) {
  this->next=next;
}