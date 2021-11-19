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

const json fighterData = readJSON(FIGHTER_DATA_JSON);

class BaseFighter
{
protected:
    string name;    // Name of fighter
    Weapon *weapon; // Weapon for fighter (e.g sword, bow, spell, etc.)
    int health;     // Health points for fighter
    int regenRate;  // Regeneration rate

public:

    BaseFighter() : name{randName(fighterData)}, weapon{nullptr}, health{100}, regenRate{1} {}

    void setName(string n) { name = n; }

    void setWeapon(Weapon w) { *weapon = w; }

    void setHp(int hp) { health = hp; }

    void setRR(int rr) { regenRate = rr; }

    void attack(BaseFighter *other) {other->takeDamage(weapon->use());}

    void takeDamage(int x) { health -= x; }

    void regen() { health += regenRate; }

    bool alive() { return health > 0; }

    int getHp() { return health; }

    friend ostream &operator<<(ostream &os, const BaseFighter &f)
    {
        return os << "[" << f.name << " , " << *f.weapon << "]";
    }
};



class Warrior : public BaseFighter
{
public:
    Warrior()
    {
        weapon = new Weapon(randWeaponType(weaponData, "Melee"));
        health += rand() % 10;
        regenRate += 0;
    }
};

class Wizard : public BaseFighter
{
public:
    Wizard()
    {
        weapon = new Weapon(randWeaponType(weaponData, "Spell"));
        health -= rand() % 20;
        regenRate += 1;
    }
};

class Archer : public BaseFighter
{
public:
    Archer()
    {
        weapon = new Weapon(randWeaponType(weaponData, "Ranged"));
        health -= rand() % 20;
        regenRate += 1;
    }
};

class Elf : public BaseFighter
{
public:
    Elf()
    {
        int choice = rand() % 2;
        if (choice == 0)
            weapon = new Weapon(randWeaponType(weaponData, "Spell"));
        else
            weapon = new Weapon(randWeaponType(weaponData, "Melee"));
        health -= rand() % 5;
        regenRate += 0;
    }
};

class DragonBorn : public BaseFighter
{
public:
    DragonBorn()
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
    }
};