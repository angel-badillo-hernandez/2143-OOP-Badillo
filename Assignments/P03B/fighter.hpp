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

class BaseFighter
{
protected:
    string name;
    Weapon *weapon;
    int hp;
    double rr;

public:
    BaseFighter() : name{"None"}, weapon1{nullptr} {}

    void setName(string n) { name = n; }

    virtual void setWeapon(Weapon w) = 0;

    virtual void attack(BaseFighter *other) = 0;

    void takeDamage(int x) { hp -= x; }

    bool alive() { return hp > 0; }

    int getHp() { return hp; }

    friend ostream &operator<<(ostream &os, const BaseFighter &f)
    {
        return os << "[" << f.name << " , " << *f.weapon1 << "]";
    }
};

class Warrior : public BaseFighter
{
private:

public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    virtual void attack(BaseFighter *&other) { other->takeDamage(weapon->use()); }

};

class Wizard : public BaseFighter
{
public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    virtual void attack(BaseFighter *&other) { other->takeDamage(weapon->use()); }
};

class Archer : public BaseFighter
{
public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    virtual void attack(BaseFighter *&other) { other->takeDamage(weapon->use()); }
};

class Elf : public BaseFighter
{
public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    virtual void attack(BaseFighter *&other) { other->takeDamage(weapon->use()); }
};

class DragonBorn : public BaseFighter
{
public:
    virtual void attack(BaseFighter *&other) { other->takeDamage(weapon->use()); }
};