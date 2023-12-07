#include "Dice.h"
#include <cstdlib>

Dice::Dice(int faces) : faces(faces){
  
}

int Dice::roll(){
  return rand() % faces +1;
}
