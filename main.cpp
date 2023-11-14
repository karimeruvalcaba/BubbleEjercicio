#include "Monster.h"
#include "Map.h"
#include "LinkedList.h"
#include "Spell.h"
#include "Ability.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


void LoadMonsters(const string& filename, LinkedList<Monster>& list) {
  /*Carga datos del archivo Monsters_patched.csv en list*/
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, type, size, align;
        double cr;
        int ac, hp;

        getline(ss, name, ',');
        ss >> cr;
        ss.ignore(); 
        getline(ss, type, ',');
        getline(ss, size, ',');
        ss >> ac;
        ss.ignore(); 
        ss >> hp;
        ss.ignore(); 
        getline(ss, align);
        Monster* m = new Monster(name, cr, type, size, ac, hp, align);
        list.addNode(*m);
    }

    file.close();
}

void ShowMonsters(LinkedList<Monster>& list, int QuantityMonsters) {
    cout << "Monsters: " << endl;
    list.print(); 
}

void LoadSpells(const string& filename, LinkedList<Spell>& SpellBook) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, description;
        int atk, def;

        getline(ss, name, ',');
        getline(ss, description, ',');
        ss >> atk;
        ss.ignore();
        ss >> def;

       
        Spell* s= new Spell(name, description, atk, def);
        SpellBook.addNode(*s);
    }

    file.close();
}

void ShowSpells(LinkedList<Spell>& SpellBook, int quantitySpell) {
    cout << "Spells:" << endl;
    SpellBook.print(); 
}

void LoadAbility(const string& filename, LinkedList<Ability>& AbilityBook) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, description;
        int atk, def;

        
        getline(ss, name, ',');
        getline(ss, description, ',');
        ss >> atk;
        ss.ignore(); 
        ss >> def;

        
        Ability* a= new Ability(name, description, atk, def);
        AbilityBook.addNode(*a);
    }

    file.close();
}

void ShowAbility(LinkedList<Ability>& AbilityBook, int quantityAbility) {
    cout << "Abilities:" << endl;
    AbilityBook.print();
}


int main() {
    
   /* int QuantityMonsters = 0; // Initialize to 0 since you're loading the monsters from a file
    LinkedList<Monster> list;
    LoadMonsters("monsters_patched.csv", list);
    cout<<QuantityMonsters<<endl;
    ShowMonsters(list, QuantityMonsters);*/
    
    /*
    int quantitySpells=0;
    LinkedList<Spell> SpellBook;
    int quantityAbilities=0;
    LinkedList<Ability> AbilityBook;

    int choice=0;
    cout<<"Elige si quieres spell(1) or ability(2): ";
    cin>>choice;

    if (choice==1){
      LoadSpells("Spell.csv", SpellBook);
      ShowSpells(SpellBook, quantitySpells);
    }else if (choice==2){
      LoadAbility("Ability.csv", AbilityBook);
      ShowAbility(AbilityBook, quantityAbilities);
    }
    */

    /*
    Monster m1;
    Dungeon("pepe",m1);

    LinkedList<Dungeon> prueba;
    LinkedList<Monster>prueba2;
  
    prueba.addNode(Dungeon("pepe",m1));
    prueba2.addNode(m1);
  
    prueba.print();

    int pruebano=3;

    Map map(pruebano);
    map.initializeMap(prueba2);
    cout << "------" <<endl;
    map.displayMap();
    cout << "-------" << endl;
    //*/
  
    
    ///*
    LinkedList<Monster> monsterList;
    LoadMonsters("monsters_mini.csv", monsterList);
    
    int maxDungeons = 3;
    Map map(maxDungeons);
    cout << "maxDungeons: " << maxDungeons << endl;
    cout << "Monsters number: " << monsterList.getSize() << endl;
    cout << "Monsters: " << endl;
    map.initializeMap(monsterList);
    cout << "1" << endl;
    
    //*/
    /*map.initializeMap(monsterList);
    cout<<"------"<<endl;
    cout<<"Hello"<<endl;
    map.displayMap();
    cout<<"Hi"<<endl;*/
    
    
  
    return 0;
}