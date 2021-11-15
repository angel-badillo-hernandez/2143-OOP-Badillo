#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

class BaseFighter{
protected:
  int hp;
public:
  BaseFighter():hp{(rand()%20)+10}{}
  virtual int attack() = 0;
  //virtual int defend() = 0;
  void takeDamage(int x){
    hp -= x;
  }
  bool alive(){
    return hp > 0;
  }
  int getHp(){
    return hp;
  }
};

class Wizard: public BaseFighter{
protected:
  int dice;
public:
  Wizard(){
    dice = 8;
    hp += rand() % 5;
  }
  int attack(){
    cout<<"Wiz attack: ";
    int r = rand() % dice +1;
    cout<<r<<endl;
    return r;
  }

  void attack(BaseFighter* &other){
    int r = rand() % dice +1;
    other->takeDamage(r);
  }
};

class Warrior: public BaseFighter{
protected:
  int dice;
public:
  Warrior(){
    dice = 8;
    hp += rand() % 8;
  }
  int attack(){
    cout<<"War attack: ";
    int r = rand() % dice +1;
    cout<<r<<endl;
    return r;
  }
};

int main() {
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