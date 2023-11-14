#ifndef ABILITY_H
#define ABILITY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Ability{
    private: 
    string name;
    string description;
    int atk;
    int def;
    Ability* next;
    public:
        Ability(string name, string description, int atk, int def);
        Ability();
        //GETTERS
        string getName();
        string getDescription();
        int getAtk();
        int getDef();
        Ability* getNext() const;
        //SETTERS
        void setName(string name);
        void setDescription(string description);
        void setAtk(int cr);
        void setDef(int Def);
        void setNext(Ability* );

        friend ostream& operator<<(ostream& os, const Ability& m){
            os<<"  Name: "<<m.name<<", Description: "<<m.description<<", Atk: "<<m.atk<<", Def: "<<m.def<<endl;
            return os;
        }

        int operator >(Ability m){
          if (this->name!=m.name){
            return this->name>m.name; 
          }else {
            return this->atk>m.atk;
          }
        }
        int operator <(Ability m){
          if (this->name!=m.name){
            return this->name<m.name; 
          }else {
            return this->atk<m.atk;
          }
        }
        bool operator ==(Ability m){
          return (this->name == m.name) && (this->atk == m.atk);
        }



};



#endif

