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

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include "fighter.hpp"
// #include "json.hpp"
// #include <cstdlib>
// #include <chrono>
// #include <thread>
#include "helpers.hpp"
#include "weapon.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp" //https://github.com/nlohmann/json

using namespace std;
using json = nlohmann::json;

json getRandomWeapon(json Weapons){
    int r = rand() % Weapons.size();
    return Weapons[r];
}

json getRandomWeaponType(json Weapons,string wtype){
  json tempWeapons = json::array();

  for(int i=0;i<Weapons.size();i++){
    if(Weapons[i]["Type"] == wtype){
      tempWeapons.push_back(Weapons[i]);
    }
  }
  return getRandomWeapon(tempWeapons);
}

int main(){
    srand(time(0));
    json jsonWeapons;
    int Size;
    string FileName;

    // read a JSON file
    ifstream input("weapons.json");
    input >> jsonWeapons;  // 
    input.close();

    Weapon s(getRandomWeaponType(jsonWeapons, "Melee"));
    
  return 0;
}