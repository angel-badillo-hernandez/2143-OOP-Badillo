/*
 *
 *  Author:           Angel Badillo
 *  Email:            badilloa022402@gmail.com
 *  Label:            P03B
 *  Title:            BoliNverse Fight Club
 *  Course:           CMPS 2143
 *  Semester:         Fall 2021
 *
 *   This program is the randomized "battle simulation" where a number of attackers are fighting a small group of defenders (1 defender of each type per 100 attackers).
 *   E.g: 1000 attackers vs. 10 defenders. The program is fairly balanced so neither side wins too frequently. The point of this program is to demonstrate run-time 
 *   polymorphism using BaseFighter points that point to an instance of any of BaseFighter's subclasses.
 *
 * Files
*
*|   #   | File                                 | Description                                                                                     |
*| :---: | ------------------------------------ | ----------------------------------------------------------------------------------------------- |
*|   1   | [main.cpp](main.cpp)                 | Main driver for program                                                                         |
*|   2   | [fighter.hpp](fighter.hpp)           | Header for fighter classes                                                                      |
*|   3   | [fighterData.json](fighterData.json) | Data to be used with fighter classes                                                            |
*|   4   | [weapon.hpp](weapon.hpp)             | Header for weapon class                                                                         |
*|   5   | [weapons.json](weapons.json)         | Data to be used with  weapon class                                                              |
*|   6   | [helpers.hpp](helpers.hpp)           | Helper functions for dice and randomization of data                                             |
*|   7   | [dice.hpp](dice.hpp)                 | Header for die and dice classes                                                                 |
*|   8   | [json.hpp](json.hpp)                 | Header for using JSON in C++, credit to the creator(s) (https://github.com/nlohmann/json)       |
*|   9   | [attackers.txt](attackers.txt)       | Data file used for generating specified amount of attackers                                     |
*|  10   | [banner.txt](banner.txt)             | Banner for this Program                                                                         |
*
* Instructions
*
* - Just compile and run the program.
*
* - Example Command:
*  - g++ main.cpp -o main
*  - ./main
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

#pragma once

/**
 * @brief Splits a string into parts based on a delimiter
 *
 *      For example the string: "2.d.12" would be turned into
 *      a vector => ["2","d","12"] and returned
 *
 * @param s
 * @param delimiter
 * @return vector<string>
 */
vector<string> tokenize(string s, string delimiter)
{
  size_t pos = 0;
  vector<string> tokens;
  while ((pos = s.find(delimiter)) != string::npos)
  {
    tokens.push_back(s.substr(0, pos));
    s.erase(0, pos + delimiter.length());
  }
  tokens.push_back(s);
  return tokens;
}

/**
 * @brief Returns a random json object (of weapon data) out of an array of
 *        json objects (of weapon data).
 *
 * @param obj A json object of the format:
 *            { "Name" : "", "Damage" : "", "Type" : ""}
 * @return json object containing weapon data.
 */
json randWeapon(json obj)
{
  int r = rand() % obj.size();
  return obj[r];
}

/**
 * @brief Returns a random json object (of weapon data) for a specfic type of weapon.
 * 
 * @param obj A json object of the format:
 *            { "Name" : "", "Damage" : "", "Type" : ""}
 * @param wtype A string, containing the name of the type of weapon.
 * @return json object containing weapon data. 
 */
json randWeaponType(json obj, string wtype)
{
  json tempWeapons = json::array();

  for (int i = 0; i < obj.size(); i++)
  {
    if (obj[i]["Type"] == wtype)
    {
      tempWeapons.push_back(obj[i]);
    }
  }
  return randWeapon(tempWeapons);
}

/**
 * @brief Returns a random name out of a json object (array of names).
 * 
 * @param obj A json object of format:
 *        { "Name" : ""}
 * @return string containing name.
 */
string randName(json obj)
{
  int r = rand() % obj.size();
  return obj[r]["Name"];
}

/**
 * @brief Reads in data from a .json file to a json object
 * 
 * @param filePath 
 * @return json 
 */
json readJSON(string filePath)
{
  ifstream input;
  json obj;
  input.open(filePath);
  input >> obj;
  input.close();

  return obj;
}