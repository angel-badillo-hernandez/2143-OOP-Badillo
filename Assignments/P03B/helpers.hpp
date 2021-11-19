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
vector<string> tokenize(string s,string delimiter){
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = s.find(delimiter)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}

json randWeapon(json obj){
    int r = rand() % obj.size();
    return obj[r];
}

json randWeapon(json obj,string wtype){
  json tempWeapons = json::array();

  for(int i=0;i<obj.size();i++){
    if(obj[i]["Type"] == wtype){
      tempWeapons.push_back(obj[i]);
    }
  }
  return randWeapon(tempWeapons);
}

string randName(json obj)
{
  int r = rand() % obj.size();
  return obj[r];
}

json fileToJSON(string filePath)
{
  ifstream input;
  json obj;
  input.open(filePath);
  input >> obj;
  input.close();

  return obj;
}