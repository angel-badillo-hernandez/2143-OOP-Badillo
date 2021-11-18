#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"
#include "dice.hpp"
#include "helpers.hpp"

using namespace std;
using json = nlohmann::json;
#pragma once

class Weapon {
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    string type;
    Dice*  die;

public:
    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    Weapon() {
        name = "";
        damage = "";
        type = "";
        die = nullptr;
    }
    Weapon(json weapon)
    {
      name = weapon["name"];
      damage = weapon["damage"];
      type = weapon["type"];
      
    }

    double use() {
        return die->roll();
    }

    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << "[" << w.name << " , " << w.damage << "]";
    }
};