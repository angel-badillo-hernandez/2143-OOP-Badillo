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

// .json file containing weapon data
const json weaponData = readJSON(WEAPONS_JSON);

class Weapon
{
private:
    string name;   // name of weapon
    string damage; // damage per roll or "use"
    string type;   // type of weapon (e.g melee, ranged, spell)
    Dice *die;     // Dice rolls for weapon

public:

    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    Weapon(): name{""}, damage{""}, type{""}, die{nullptr}{}

    Weapon(json data)
        : name{data["Name"]},
          damage{data["Damage"]},
          type{data["Type"]},
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
