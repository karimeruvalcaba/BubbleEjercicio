#include "Dice.h"
#include "Graph.h"
#include "LinkedList.h"
#include "Map.h"
#include "Monster.h"
#include "Player.h"
#include "SpellAndAbility.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

void LoadMonsters(const string &filename, LinkedList<Monster> &list) {
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
    Monster *m = new Monster(name, cr, type, size, ac, hp, align);
    list.addNode(*m);
  }

  file.close();
}

void ShowMonsters(LinkedList<Monster> &list, int QuantityMonsters) {
    cout << "Monsters:" << endl;
    for (int i = 0; i < list.getSize(); i++) {
      cout << i << list.getData(i);
    }
  }

void LoadSpellsAndAbility(const string &filename,
                          LinkedList<SpellAndAbility> &SpellAndAbilityBook) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Could not open the file " << filename << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string name, description;
    int def;

    getline(ss, name, ',');
    getline(ss, description, ',');
    ss >> def;

    SpellAndAbility *sa = new SpellAndAbility(name, description, def);
    SpellAndAbilityBook.addNode(*sa);
  }

  file.close();
}

void ShowSpellsAndAbility(LinkedList<SpellAndAbility> &SAndABook,
                          int quantitySA) {
  cout << "Spells And Abilities:" << endl;
  for (int i = 0; i < SAndABook.getSize(); i++) {
    cout << "p" << i << SAndABook.getData(i);
  }
}

int performMagicAction(const std::string &MagicChoice, std::unordered_map<std::string, SpellAndAbility> &spellMap, Player& player1) {
  if (MagicChoice == "s") {
    std::string userInput;
    std::cout << "Ingresa la clave del spell: ";
    std::cin >> userInput;
    SpellAndAbility chosenSpell = spellMap[userInput];

    LinkedList<SpellAndAbility> magicListFiltered;
    magicListFiltered.addNode(chosenSpell);

    player1.setLp(player1.getLp() + chosenSpell.getDef());

    std::cout << "Tu vida es: " << player1.getLp() << "\n";
  } else if (MagicChoice == "n") {
    std::cout << "Intento guardado para mas tarde" << std::endl;
  } else {
    std::cout << "Invalid MagicChoice\n";
  }
  return player1.getLp();
}

string CheckRace(const string &race) {
    string validRace = race;

    while (validRace != "elf" && validRace != "human" && validRace != "dwarf") {
        cout << "Inserta elf, human o dwarf" << endl;
        cout << "Ingresa tu raza: elf, human o dwarf: ";
        cin >> validRace;
    }

    return validRace;
}

int main() {

  cout << "Hola! Bienvenido a D&D, prepárate para jugar" << endl;
  string nameOfPlayer;
  string typeOfPlayer;
  cout << "Ingresa tu nombre: ";
  cin >> nameOfPlayer;
  cout << "Ingresa tu raza: elf, human o dwarf: ";
  cin >> typeOfPlayer;
  string validRace=CheckRace(typeOfPlayer);
  cout<<"Raza valida:"<<validRace<<endl;
  int counterDungeons=0;


  Player player1;
  player1.setName(nameOfPlayer);
  player1.setType(validRace);
  cout << player1 << endl;

  LinkedList<Monster> FilteredMonsters;
  // 1. Carga el códice de criaturas.
  LinkedList<Monster> MonsterBook;
  LoadMonsters("monsters_patched.csv", MonsterBook);
  // 2. Carga el mapa de calabozos, asignando un monstruo aleatorio en cada
  // calabozo.

  // 3. Cargar tu lista de mínimo 15 hechizos y habilidades.
  LinkedList<SpellAndAbility> SpellAndAbilityBook;
  LoadSpellsAndAbility("SpellsAndAbilities.csv", SpellAndAbilityBook);
  int magicBook = 0;
  ShowSpellsAndAbility(SpellAndAbilityBook, magicBook);
  Graph g;
  SpellAndAbility p0 = SpellAndAbilityBook.getData(0);
  SpellAndAbility p1 = SpellAndAbilityBook.getData(1);
  SpellAndAbility p2 = SpellAndAbilityBook.getData(2);
  SpellAndAbility p3 = SpellAndAbilityBook.getData(3);
  SpellAndAbility p4 = SpellAndAbilityBook.getData(4);
  SpellAndAbility p5 = SpellAndAbilityBook.getData(5);
  SpellAndAbility p6 = SpellAndAbilityBook.getData(6);
  SpellAndAbility p7 = SpellAndAbilityBook.getData(7);
  SpellAndAbility p8 = SpellAndAbilityBook.getData(8);
  SpellAndAbility p9 = SpellAndAbilityBook.getData(9);
  SpellAndAbility p10 = SpellAndAbilityBook.getData(10);
  SpellAndAbility p11 = SpellAndAbilityBook.getData(11);
  SpellAndAbility p12 = SpellAndAbilityBook.getData(12);
  SpellAndAbility p13 = SpellAndAbilityBook.getData(13);
  SpellAndAbility p14 = SpellAndAbilityBook.getData(14);

  g.addVertex(p0);
  g.addVertex(p1);
  g.addVertex(p2);
  g.addVertex(p3);
  g.addVertex(p4);
  g.addVertex(p5);
  g.addVertex(p6);
  g.addVertex(p7);
  g.addVertex(p8);
  g.addVertex(p9);
  g.addVertex(p10);
  g.addVertex(p11);
  g.addVertex(p12);
  g.addVertex(p13);
  g.addVertex(p14);

  g.addEdge(p0, p1);
  g.addEdge(p1, p2);
  g.addEdge(p3, p4);
  g.addEdge(p5, p6);
  g.addEdge(p7, p8);
  g.addEdge(p9, p10);
  g.addEdge(p11, p12);
  g.addEdge(p13, p14);

  // Para poder convertir de string a SpellAndAbility
  unordered_map<string, SpellAndAbility> spellMap;

  // Llenamos con los objects de la clase
  spellMap["p0"] = p0;
  spellMap["p1"] = p1;
  spellMap["p2"] = p2;
  spellMap["p3"] = p3;
  spellMap["p4"] = p4;
  spellMap["p5"] = p5;
  spellMap["p6"] = p6;
  spellMap["p7"] = p7;
  spellMap["p8"] = p8;
  spellMap["p9"] = p9;
  spellMap["p10"] = p10;
  spellMap["p11"] = p11;
  spellMap["p12"] = p12;
  spellMap["p13"] = p13;
  spellMap["p14"] = p14;

  //1.Lanzar un dado de 20 caras para llegar a un calabozo.
  Dice d(20);
  int dungeonIndex = d.roll();
  int maxDungeons = 20;
  Map map(maxDungeons);
  map.initializeMap(MonsterBook, dungeonIndex);
  cout << "Has entrado en los calabozos!" << endl;
  //5. El algoritmo a seguir es:
  //1.Mientras el jugador tenga vida:
  while (player1.getLp() > 0) {
    // map.displayMap();
    Dungeon currentDungeon = map.getNextDungeon(dungeonIndex);
    Monster currentMonster = currentDungeon.getMonsterInDungeon();
    if (dungeonIndex == 19) {
      player1.setLp(0);
    } else {
      cout << "-----------------ENTRASTE AL CALABOZO: " << currentDungeon.getName() <<"-----------------"<< endl;
      counterDungeons++;
      //2. Sí la criatura del calabozo está muerta (según su hp), vuelve a tirar el dado
      if (currentMonster.getHp() <= 0) {
        cout << "Monstruo Petado, vamos al siguiente calabozo" << endl;
        dungeonIndex=d.roll();
        //3. Sino, si la criatura se encuentra viva, entrarás en combate.
      } else {
        cout << "Te encuentras con un atemorizante: "
             << currentMonster.getType();
        cout << currentMonster.getName() << endl;
        bool usedSpell=false;
        //1. Mientras el jugador o la criatura sigan vivos:
        while (player1.getLp() > 0 && currentMonster.getHp() > 0) {
          //2. Ataca el monstruo, tira un dado de 10 caras para ver cuánto daño te hace.
          Dice diceMonster(10);
          int dmgMonster = diceMonster.roll();
          player1.setLp(player1.getLp() - dmgMonster);
          cout << "El " << currentMonster.getName() << " te hizo " << dmgMonster << " puntos de daño.";
          cout << " Tus Puntos de vida restantes: " << player1.getLp() << "\n";
          string MagicChoice;
          if (usedSpell==false){
            cout << "Quieres usar un hechizo Responde (s/n)" << endl;
            cin >> MagicChoice;
            //4. El jugador tiene 100 puntos que se pueden ir descontando con el ataque de una criatura y se puede incrementar con una magia 
            //específica
            performMagicAction(MagicChoice, spellMap,player1);
            if (MagicChoice=="s"){
              usedSpell=true;
            }else if (MagicChoice=="n"){
              usedSpell=false;
            }
          }
          if (player1.getLp() <= 0) {
            cout << "Moriste.Game Over" << endl;
            break;
          } else {
            Dice dicePlayer(10);
            int dmgPlayer = dicePlayer.roll();
            currentMonster.setHp(currentMonster.getHp() - dmgPlayer);
            //2.El jugador ataca, tira un dato de 10 caras para simular cuánto daño le haces.
            cout<<"----------YOUR TURN------------------"<<endl;
            cout << "Has hecho " << dmgPlayer << " puntos de daño al "
                 << currentMonster.getName();
            cout << ". Puntos de vida restantes del "
                 << currentMonster.getType() << ": ";
            cout << currentMonster.getHp() << "\n";

            if (currentMonster.getHp() <= 0) {
              //2. Si el jugador sale vivo, guarda al monstruo que ha derrotado.
              FilteredMonsters.addNode(currentMonster);
              cout << "Has vencido a " << currentMonster.getName() << endl;
              //3. El jugador puede lanzar un dado de 8 caras para recuperar su life points (lf).
              Dice recoveryDice(8);
              int recoveryPlayer = recoveryDice.roll();
              player1.setLp(player1.getLp() + recoveryPlayer);
              cout << "Recuperaste " << recoveryPlayer << endl;

            }
          }
        }
        dungeonIndex++;
      }
    }
  }
  //3.Al terminar debe mostrar una lista ordenada, por nombre, de los monstruos que derrotó. Su nombre, raza y cuantos calabozos conquistó
  
  cout<<player1<<endl;
  cout<<"Dungeons visitados: "<<counterDungeons<<endl;
  FilteredMonsters.bubbleSort();
  FilteredMonsters.print();
  
  return 0;
}