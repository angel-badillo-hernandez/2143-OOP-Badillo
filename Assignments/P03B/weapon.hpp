#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"
#include "dice.hpp"
#include "helpers.hpp"

using namespace std;
using json = nlohmann::json;
#pragma once

// To easily change files
#define WEAPONS_JSON "weapons.json"

class Weapon
{
private:
    string name;   // name of weapon
    string damage; // damage per roll or "use"
    string type;   // type of weapon (e.g melee, ranged, spell)
    Dice *die;

public:

    static json weaponData;

    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    Weapon(): name{""}, damage{""}, type{""}, die{nullptr}{}

    Weapon(json data)
        : name{data["name"]},
          damage{data["damage"]},
          type{data["type"]},
          die{new Dice(damage)} {}

    double use()
    {
        return die->roll();
    }

    friend ostream &operator<<(ostream &os, const Weapon &w)
    {
        return os << "[" << w.name << " , " << w.damage << "]";
    }
};

json Weapon::weaponData{fileToJSON(WEAPONS_JSON)};