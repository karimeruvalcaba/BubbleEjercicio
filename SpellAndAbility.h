#ifndef SPELLANDABILITY_H
#define SPELLANDABILITY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SpellAndAbility{
    private: 
    string name;
    string description;
    int def;
    SpellAndAbility* next;
    public:
        SpellAndAbility(string name, string description, int def);
        SpellAndAbility();
        //GETTERS
        string getName();
        string getDescription();
        int getDef();
        SpellAndAbility* getNext() const;
        //SETTERS
        void setName(string name);
        void setDescription(string description);
        void setDef(int Def);
        void setNext(SpellAndAbility* );

        friend ostream& operator<<(ostream& os, const SpellAndAbility& m){
            os<<"  Name: "<<m.name<<", Description: "<<m.description<<", Def: "<<m.def<<endl;
            return os;
        }

        int operator >(SpellAndAbility m){
          if (this->name!=m.name){
            return this->name>m.name; 
          }else {
            return this->def>m.def;
          }
        }
        int operator <(SpellAndAbility m){
          if (this->name!=m.name){
            return this->name<m.name; 
          }else {
            return this->def<m.def;
          }
        }
        bool operator ==(SpellAndAbility m){
          return (this->name == m.name) && (this->def == m.def);
        }



};



#endif

