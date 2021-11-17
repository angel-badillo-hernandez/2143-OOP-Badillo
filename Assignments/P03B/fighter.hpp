#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "weapon.hpp"
#include "helpers.hpp"
#include "dice.hpp"
using namespace std;

#pragma once

class BaseFighter
{
protected:
    string name;
    Weapon *weapon1;
    int hp;
    double rr;

public:
    BaseFighter() : name{"None"}, weapon1{nullptr} {}

    void setName(string n) { name = n; }

    void setWeapon(Weapon w) { *weapon1 = w; }

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
    Weapon *sword;

public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    void attack(BaseFighter *&other) { other->takeDamage(sword->use()); }
};

class Wizard : public BaseFighter
{
private:
    Weapon *magic;

public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    void attack(BaseFighter *&other) { other->takeDamage(magic->use()); }
};

class Archer : public BaseFighter
{
private:
    Weapon *bow;

public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    void attack(BaseFighter *&other) { other->takeDamage(bow->use()); }
};

class Elf : public BaseFighter
{
private:
    Weapon *magicSword;

public:

    /**
     * @brief Uses an attack, and damages the enemy fighter.
     * 
     * @param other BaseFighter pointer of enemy
     */
    void attack(BaseFighter *&other)
    {
        other->takeDamage(magicSword->use());
    };
};

    class DragonBorn : public BaseFighter
    {
    private:
        Weapon *magic;
        Weapon *fireWeapon;

    public:
        void attack(BaseFighter *&other)
        {
            if (rand() % 2)
            {
                other->takeDamage(magic->use());
            }
            else
            {
                other->takeDamage(fireWeapon->use());
            }
        }
    };