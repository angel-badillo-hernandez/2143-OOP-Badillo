#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BaseCharacter
{
protected:
    string name;
    string race;   // Does a character inherit from race? Or are they composed of a race?
    string gender; // Same for gender. Does race or gender offer any special properties that
                   // could be inherited by a character?
    string classification;
    double health;
    double stamina;
    double skill;
    //string weapon;    // Not sure if this belongs here or not. Do ALL characters carry a weapon?
    //double mana;      // This is a specialty for wizards! So, it doesn't belong here.

public:
    // constructors
    BaseCharacter() : name{""}, race{""}, gender{""}, health{100}, stamina{0}, skill{0} {}

    // basic stuff
    void takeDMG(double attack)
    {
        health -= attack;
    }
    
    double HP()
    {
        return health;
    }
    // pure virtual methods
    virtual double attack(BaseCharacter*) = 0;
    virtual double defend() = 0;
};

class Weapon
{
private:
    string name;
    double skillLevel;
    double powerLevel;
    double attack(); // generates attack value based on
};

struct Character
{
    string classification; // type is a reserved word
    string race;
    vector<Weapon> weapons;
    double health;
};

class CharacterGen
{
protected:
    string randRace()                    // randomly returns a race
    {
        if(rand()%100 > 100)
        {
            return "Human";
        }
        else
        {
            return "Elf";
        }
    }
    string randClass()                 // randomly returns a classification
    {
        if(rand()%100 > 100)
        {
            return "Wizard";
        }
        else
        {
            return "Archer";
        }
    }
    string randWeapon(string classification); // randomly assign a weapon based on character type
                                          // it could be a spell if the character is a wizard

    string randGender()
    {
        return "male";
    }
};

class Wizard : public BaseCharacter
{
private:
    double mana;

    double castSpell()
    {
        return rand() % 50;
    }

public:
    double attack(BaseCharacter*)
    {
        double rtn = 0.0;
        rtn = castSpell();

        return rtn;
    }

    double defend()
    {
        double rtn = 0.0;

        return rtn;
    }
};

class Archer : public BaseCharacter
{
private:
    double shootArrow()
    {
        return rand() % 50;
    }
public:
    double attack(BaseCharacter* enemy)
    {
        double rtn = 0.0;
        rtn = shootArrow();

        enemy->takeDMG(rtn);

        return rtn;
    }
    double defend()
    {
        double rtn = 0.0;
        return rtn;
    }
};