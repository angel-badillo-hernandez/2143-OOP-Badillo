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
    BaseFighter()
    {
        name = "None";
        weapon1 = new Weapon;
    }

    virtual double attack()
    {
        return weapon1->use();
    }

    void takeDamage(int x)
    {
        hp -= x;
    }

    bool alive()
    {
        return hp > 0;
    }
    int getHp()
    {
        return hp;
    }

    friend ostream &operator<<(ostream &os, const BaseFighter &f)
    {
        return os << "[" << f.name << " , " << *f.weapon1 << "]";
    }
};

class Warrior : public BaseFighter
{
private:
    Weapon *weapon2;

public:
    void attack(BaseFighter *&other)
    {
        int r = weapon2->use();
        other->takeDamage(r);
    }
};

class Wizard : public BaseFighter
{
private:
    Weapon* weapon2;
public:
    void attack(BaseFighter *&other)
    {
        int r = weapon2->use();
        other->takeDamage(r);
    }
};

class Archer : public BaseFighter
{
private:
    Weapon* weapon2;
public:
    void attack(BaseFighter *&other)
    {
        int r = weapon2->use();
        other->takeDamage(r);
    }
};

class Elf : public BaseFighter
{
private:
    Weapon* weapon2;
public:
    void attack(BaseFighter *&other)
    {
        int r = weapon2->use();
        other->takeDamage(r);
    }
};

class DragonBorn : public BaseFighter
{
private:
    Weapon* weapon2;
public:
    void attack(BaseFighter *&other)
    {
        int r = weapon2->use();
        other->takeDamage(r);
    }
};