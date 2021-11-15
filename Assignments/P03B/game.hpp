#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "weapon.hpp"
#include "helpers.hpp"
#include "fighter.hpp"
#include "dice.hpp"

using namespace std;

#pragma once

class Game
{
private:
    vector<BaseFighter*> attackers;
    vector<BaseFighter*> defenders;
};

int main(){
    srand(time(0));
  vector<BaseFighter*> Attackers;
  vector<BaseFighter*> Defenders;

  BaseFighter* CaptAttacker;
  BaseFighter* CaptDefender;

  for(int i=0;i<100;i++){
    if(rand()%2 == 0){
      Attackers.push_back(new Wizard());
    }else{
      Attackers.push_back(new Warrior());
    }
    if(rand()%2 == 0){
      Defenders.push_back(new Wizard());
    }else{
      Defenders.push_back(new Warrior());
    }
  }

  // GAME LOOP
  while(Attackers.size() && Defenders.size()){
    // defenders.heal();
    CaptAttacker  =  Attackers.back();
    CaptDefender  =  Defenders.back();

    //sub game loop
    while(CaptAttacker->alive() && CaptDefender->alive()){
      this_thread::sleep_for(chrono::milliseconds(10));
      system("clear");
      cout<<Attackers.size()<<" v "<<Defenders.size()<<endl;
      CaptDefender->takeDamage(CaptAttacker->attack());
      CaptAttacker->takeDamage(CaptDefender->attack());
    }
    if(!Attackers.back()->alive()){
      Attackers.pop_back();
    }
    if(!Defenders.back()->alive()){
      Defenders.pop_back();
    }
  }

  cout<<Defenders.size()<<endl;
  cout<<Attackers.size()<<endl;
} 