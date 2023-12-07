#ifndef DICE_H
#define DICE_H
#include <iostream>

using namespace std;

class Dice{

  private:
    int faces;

  public:
    Dice(int faces);
    int roll();
  
};


#endif