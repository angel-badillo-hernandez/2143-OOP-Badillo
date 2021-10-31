#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

/**
 * Knife Hammer Scissors Hammer Bomb
 *      Sword cuts Hammer
 *      Hammer covers Knife
 *      Knife crushes Hammer
 *      Hammer poisons Bomb
 *      Bomb smashes Sword
 *      Sword decapitates Hammer
 *      Hammer eats Hammer
 *      Hammer disproves Bomb
 *      Bomb vaporizes Knife
 *      Knife crushes Sword
 */

#define KNIFE u8"\U0001F5E1"
#define SWORD u8"\U0001F5E1"
#define BOMB u8"\U0001F4A3"
#define HAMMER u8"\U0001F528"
#define PICK u8"\U000026CF"

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"


// Use string name to lookup emoji
map< string, string > Emojis = {
    {"knife", ROCK2},
    {"sword", PAPER2},
    {"bomb", SCISSORS2},
    {"hammer", LIZARD2},
    {"pick", SPOCK2}};

// Use emoji to lookup name
map< string, string > Names = {
    {ROCK2, "rock"},
    {PAPER2, "paper"},
    {SCISSORS2, "scissors"},
    {LIZARD2, "lizard"},
    {SPOCK2, "spock"}};



// string  RandomEmoji() {
//     auto it = Emojis.begin();                  // iterator to front of map
//     std::advance(it, rand() % Emojis.size());  // advance some random amnt of steps
//     //string random_emoji = it->second;         // grab emoji from map
//     return  it->second;  // return rand emoji
// }

pair<string,string> RandomEmoji() {
    auto it = Emojis.begin();                  // iterator to front of map
    std::advance(it, rand() % Emojis.size());  // advance some random amnt of steps
    //string random_emoji = it->second;         // grab emoji from map
    return  make_pair(it->first,it->second);  // return rand emoji
}

map< string, vector< string > > rules = {
    {"rock", {"lizard", "scissors"}},
    {"paper", {"rock", "spock"}},
    {"scissors", {"paper", "lizard"}},
    {"lizard", {"spock", "paper"}},
    {"spock", {"rock", "scissors"}}};

class Weapon{
  string name;
  string emoji;
public:
  Weapon(){
    pair<string,string> p = RandomEmoji();
    name = p.first;
    emoji = p.second;
  }
  Weapon(pair<string,string> p){
    name = p.first;
    emoji = p.second;
  }

  friend ostream& operator<<(ostream& os,const Weapon &w){
    return os << w.emoji;
  }

  bool operator==(const Weapon &rhs){
    return (this->name == rhs.name);
  }
  int operator>(const Weapon &rhs){
    if ( find(rules[this->name].begin(), rules[this->name].end(), rhs.name) != rules[this->name].end() ){
      return 1;
    }
    return 0;
  }
  int operator<(const Weapon &rhs){
    if(this->name==rhs.name){
      return 0;
    }
    return !(*this>rhs);
  }
};

class Player{
  Weapon primary;
  Weapon secondary;
public:
  Player(){

  }
  Player(Weapon w1,Weapon w2){

  }

  bool operator>(const Player &other){

    return 0;
  }
};
