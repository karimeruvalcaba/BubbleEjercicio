#ifndef SPELL_H
#define SPELL_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Spell{
    private: 
    string name;
    string description;
    int atk;
    int def;
    Spell* next;
    public:
        Spell(string name, string description, int atk, int def);
        Spell();
        //GETTERS
        string getName();
        string getDescription();
        int getAtk();
        int getDef();
        Spell* getNext() const;
        //SETTERS
        void setName(string name);
        void setDescription(string description);
        void setAtk(int cr);
        void setDef(int Def);
        void setNext(Spell* );

        friend ostream& operator<<(ostream& os, const Spell& m){
            os<<"  Name: "<<m.name<<", Description: "<<m.description<<", Atk: "<<m.atk<<", Def: "<<m.def<<endl;
            return os;
        }

        int operator >(Spell m){
          if (this->name!=m.name){
            return this->name>m.name; 
          }else {
            return this->atk>m.atk;
          }
        }
        int operator <(Spell m){
          if (this->name!=m.name){
            return this->name<m.name; 
          }else {
            return this->atk<m.atk;
          }
        }
        bool operator ==(Spell m){
          return (this->name == m.name) && (this->atk == m.atk);
        }



};



#endif

