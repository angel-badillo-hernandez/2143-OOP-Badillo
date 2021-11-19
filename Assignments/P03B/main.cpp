/*****************************************************************************
 *
 *  Author:           Angel Badillo
 *  Email:            badilloa022402@gmail.com
 *  Label:            P03B
 *  Title:            BoliNverse Fight Club
 *  Course:           CMPS 2143
 *  Semester:         Fall 2021
 *
 *  Description:
 *        This program
 *
 *  Usage:
 *       - g++ main.cpp -o main && ./main
 *       - You just compile and run it.
 *
 *  Files:
 *       main.cpp      : driver program
 *       FightClub.hpp : header file with definition and implementation of "game"
 *       output.txt    : output of program
 *****************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "helpers.hpp"
#include "weapon.hpp"
#include "fighter.hpp"
#include "json.hpp" //https://github.com/nlohmann/json

using namespace std;
using json = nlohmann::json;

int main()
{

  ifstream infile;
  infile.open("attackers.txt");

  int numAttackers;
  infile >> numAttackers;

  int warriorCount = 0;
  int wizardCount = 0;
  int archerCount = 0;
  int elfCount = 0;
  int dragonbornCount = 0;
  int roundCount = 0;

  for (int i = 0; i < numAttackers; i++)
  {
    string fighterType;
    infile >> fighterType;

    if (fighterType == "warrior")
    {
      warriorCount++;
    }
    else if (fighterType == "wizard")
    {
      wizardCount++;
    }
    else if (fighterType == "archer")
    {
      archerCount++;
    }
    else if (fighterType == "elf")
    {
      elfCount++;
    }
    else
    {
      dragonbornCount++;
    }
  }

  srand(time(0));
  vector<BaseFighter *> Attackers;
  vector<BaseFighter *> Defenders;

  BaseFighter *CaptAttacker;
  BaseFighter *CaptDefender;

  for (int i = 0; i < warriorCount; i++)
    Attackers.push_back(new Warrior("attacker"));

  for (int i = 0; i < wizardCount; i++)
    Attackers.push_back(new Wizard("attacker"));

  for (int i = 0; i < archerCount; i++)
    Attackers.push_back(new Archer("attacker"));

  for (int i = 0; i < elfCount; i++)
    Attackers.push_back(new Elf("attacker"));

  for (int i = 0; i < dragonbornCount; i++)
    Attackers.push_back(new DragonBorn("attacker"));

  for (int i = 0; i < Attackers.size() / 100; i++)
  {
      if((numAttackers / 100) % 5 == 0)
      {
        Defenders.push_back(new Warrior("defender"));
      }
      else if((numAttackers / 100) % 5 == 1)
      {
        Defenders.push_back(new Wizard("defender"));
      }
      else if((numAttackers / 100) % 5 == 2)
      {
        Defenders.push_back(new Archer("defender"));
      }
      else if((numAttackers / 100) % 5 == 3)
      {
        Defenders.push_back(new Elf("defender"));
      }
      else if((numAttackers / 100) % 5 == 4)
      {
        Defenders.push_back(new DragonBorn("defender"));
      }
  }

  // GAME LOOP
  while (Attackers.size() && Defenders.size())
  {

    for (int i = 0; i < Defenders.size(); i++)
      Defenders[i]->regen();
    CaptAttacker = Attackers.back();
    CaptDefender = Defenders.back();

    // sub game loop
    while (CaptAttacker->alive() && CaptDefender->alive())
    {
      //this_thread::sleep_for(chrono::milliseconds(1));
      system("clear");
      cout << Attackers.size() << " v " << Defenders.size() << endl;
      CaptAttacker->attack(CaptDefender);
      CaptDefender->attack(CaptAttacker);
    }
    if (!Attackers.back()->alive())
    {
      Attackers.pop_back();
    }
    if (!Defenders.back()->alive())
    {
      Defenders.pop_back();
    }
  }

  cout << Defenders.size() << endl;
  cout << Attackers.size() << endl;
}