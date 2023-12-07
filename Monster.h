#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
  
  class Monster{
      private: 
      string name;
      double cr;
      string type;
      string size;
      int ac;
      int hp;
      string align;
      Monster* next;
      public:
          Monster(string name, double cr, string type, string size, int ac, int hp, string align);
          Monster();
          //GETTERS
          string getName();
          double getCr();
          string getType();
          string getSize();
          int getAc();
          int getHp();
          string getAlign();
          Monster* getNext() const;
          //SETTERS
          void setName(string name);
          void setCr(double cr);
          void setType(string type);
          void setSize(string size);
          void setAc(int Ac);
          void setHp(int Hp);
          void setAlign(string align);
          void setNext(Monster* );
  
          friend ostream& operator<<(ostream& os, const Monster& m){
              os<<"  Name: "<<m.name<<", CR: "<<m.cr<<", Type: "<<m.type<<", Size: "<<m.size<<", Ac: "<<m.ac<<", Hp: "<<m.hp<<", Align: "<<m.align<<" "<<endl;
              return os;
          }
  
          int operator >(Monster m){
            if (this->name!=m.name){
              return this->name>m.name; 
            }else {
              return this->cr>m.cr;
            }
          }
          int operator <(Monster m){
            if (this->name!=m.name){
              return this->name<m.name; 
            }else {
              return this->cr<m.cr;
            }
          }
          bool operator ==(Monster m){
            return (this->name == m.name) && (this->cr == m.cr);
          }
  
          
  
  };
  
  
  
#endif

