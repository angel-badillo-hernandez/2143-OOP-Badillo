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
#include <random>
#include <string>
#include <vector>
#include "weapon.hpp"
#include "helpers.hpp"
#include "dice.hpp"

using namespace std;
using json = nlohmann::json;

#pragma once

// Input file containing fighter data (names of fighters).
#define FIGHTER_DATA_JSON "fighterData.json"
// Boosts for the defenders so they can stand a chance.
#define DHPBoost 3000 // +3000 HP
#define DRRBoost 15   // +15 regeneration
// JSON object containing fighterData from .json
const json fighterData = readJSON(FIGHTER_DATA_JSON);

/**
 * BaseFighter
 * 
 * Description:
 *      Used for creating the basis of the fighters. Has the general things
 *      every type of fighter needs.
 * 
 * Public Methods:
 *      - BaseFighter()
 *      - void setName(string n)
 *      - void setWeapon(Weapon w)
 *      - void setHp(int hp)
 *      - void setRR(int rr)
 *      - void attack(BaseFighter* other)
 *      - void takeDamage(int x)
 *      - void regen()
 *      - bool alive()
 *      - int getHp()
 *      - ostream& operator<<(ostream& os, BaseFighter &f)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */

class BaseFighter
{
protected:
    string name;    // Name of fighter
    Weapon *weapon; // Weapon for fighter (e.g sword, bow, spell, etc.)
    int health;     // Health points for fighter
    int regenRate;  // Regeneration rate

public:

    /**
     * @brief Construct a new Base Fighter object with default values.
     * 
     */
    BaseFighter() : name{randName(fighterData)}, weapon{nullptr}, health{100}, regenRate{1} {}

    /**
     * @brief Set the Name object
     * 
     * @param n A string, name of fighter.
     */
    void setName(string n) { name = n; }

    /**
     * @brief Set the Weapon object
     * 
     * @param w A Weapon object, weapon for the fighter.
     */
    void setWeapon(Weapon w) { *weapon = w; }

    /**
     * @brief Set the Hp object
     * 
     * @param hp An integer, number of hitpoints / health.
     */
    void setHp(int hp) { health = hp; }

    /**
     * @brief Set the regeneration rate.
     * 
     * @param rr An integer, regeneration rate per round.
     */
    void setRR(int rr) { regenRate = rr; }

    /**
     * @brief "Attacks" an opposing fighter.
     * 
     * @param other A pointer to another BaseFighter.
     */
    void attack(BaseFighter *other) {other->takeDamage(weapon->use());}

    /**
     * @brief Takes damage recieved from opposing attack.
     * 
     * @param x An integer, health lost.
     */
    void takeDamage(int x) { health -= x; }

    /**
     * @brief "Heals" the fighter with the set regenRate
     * 
     */
    void regen() { health += regenRate; }

    /**
     * @brief Determines whether or not a fighter is alive.
     * 
     * @return true if hp > 0
     * @return false otherwise
     */
    bool alive() { return health > 0; }

    /**
     * @brief Get the Hp object, i.e returns a fighter's current hp.
     * 
     * @return int , the hp the fighter has left.
     */
    int getHp() { return health; }

    /**
     * @brief Used to test if BaseFighter is constructed correctly or not.
     * 
     * @param os An ostream by reference.
     * @param f A BaseFighter object by reference.
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const BaseFighter &f)
    {
        return os << "[" << f.name << " , " << *f.weapon << "]";
    }
};


/**
 * Warrior
 * 
 * Description:
 *      Subclass of BaseFighter. Constructs a Warrior with a random melee weapon.
 * 
 * Public Methods:
 *      - Warrior(string team)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      - Warrior Joe("defender"); // Warrior with defender properties
 *      - BaseFighter* Captain = new Warrior("attacker");
 */
class Warrior : public BaseFighter
{
public:
    /**
     * @brief Construct a new Warrior object, with either attacker or defender properties.
     * 
     * @param team A string, the name of the team the fighter is on, attacker or defender. 
     */
    Warrior(string team)
    {
        weapon = new Weapon(randWeaponType(weaponData, "Melee"));
        health += rand() % 10;
        regenRate += 0;

        if(team == "defender")
        {
            health += DHPBoost;
            regenRate += DRRBoost;
        }
    }

};

/**
 * Wizard
 * 
 * Description:
 *      Subclass of BaseFighter. Constructs a Wizard with a random spell weapon.
 * 
 * Public Methods:
 *      - Wizard(string team)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      - Wizard Joe("defender"); // Wizard with defender properties
 *      - BaseFighter* Captain = new Wizard("attacker");
 */
class Wizard : public BaseFighter
{
public:
    /**
     * @brief Construct a new Wizard object, with either attacker or defender properties.
     * 
     * @param team A string, the name of the team the fighter is on, attacker or defender. 
     */
    Wizard(string team)
    {
        weapon = new Weapon(randWeaponType(weaponData, "Spell"));
        health -= rand() % 20;
        regenRate += 1;

        if(team == "defender")
        {
            health += DHPBoost;
            regenRate += DRRBoost;
        }
    }
};

/**
 * Archer
 * 
 * Description:
 *      Subclass of BaseFighter. Constructs a Archer with a random ranged weapon.
 * 
 * Public Methods:
 *      - Archer(string team)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      - Archer Joe("defender"); // Warrior with defender properties
 *      - BaseFighter* Captain = new Archer("attacker");
 */
class Archer : public BaseFighter
{
public:
    /**
     * @brief Construct a new Archer object, with either attacker or defender properties.
     * 
     * @param team A string, the name of the team the fighter is on, attacker or defender. 
     */
    Archer(string team)
    {
        weapon = new Weapon(randWeaponType(weaponData, "Ranged"));
        health -= rand() % 20;
        regenRate += 1;

        if(team == "defender")
        {
            health += DHPBoost;
            regenRate += DRRBoost;
        }
    }
};

/**
 * Elf
 * 
 * Description:
 *      Subclass of BaseFighter. Constructs an Elf with a random spell or melee weapon.
 * 
 * Public Methods:
 *      - Elf(string team)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      - Elf Joe("defender"); // Warrior with defender properties
 *      - BaseFighter* Captain = new Elf("attacker");
 */
class Elf : public BaseFighter
{
public:
    /**
     * @brief Construct a new Elf object, with either attacker or defender properties.
     * 
     * @param team A string, the name of the team the fighter is on, attacker or defender. 
     */
    Elf(string team)
    {
        int choice = rand() % 2;
        if (choice == 0)
            weapon = new Weapon(randWeaponType(weaponData, "Spell"));
        else
            weapon = new Weapon(randWeaponType(weaponData, "Melee"));
        health -= rand() % 5;
        regenRate += 0;

        if(team == "defender")
        {
            health += DHPBoost;
            regenRate += DRRBoost;
        }
    }
};

/**
 * Warrior
 * 
 * Description:
 *      Subclass of BaseFighter. Constructs a DragonBorn with a random weapon of any kind.
 * 
 * Public Methods:
 *      - DragonBorn(string team)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      - DragonBorn Joe("defender"); // Warrior with defender properties
 *      - BaseFighter* Captain = new DragonBorn("attacker");
 */
class DragonBorn : public BaseFighter
{
public:
    /**
     * @brief Construct a new DragonBorn object, with either attacker or defender properties.
     * 
     * @param team A string, the name of the team the fighter is on, attacker or defender. 
     */
    DragonBorn(string team)
    {
        int choice = rand() % 3;
        if (choice == 0)
            weapon = new Weapon(randWeaponType(weaponData, "Spell"));
        else if (choice == 1)
            weapon = new Weapon(randWeaponType(weaponData, "Ranged"));
        else
            weapon = new Weapon(randWeaponType(weaponData, "Melee"));
        health += rand() % 20;
        regenRate += 0;

        if(team == "defender")
        {
            health += DHPBoost;
            regenRate += DRRBoost;
        }
    }
};