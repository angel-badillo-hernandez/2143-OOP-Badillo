#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BaseCharacter
{
    string name;
    string race;   // Does a character inherit from race? Or are they composed of a race?
    string gender; // Same for gender. Does race or gender offer any special properties that
                   // could be inherited by a character?
    double health;
    double stamina;
    double skill;
    //string weapon;    // Not sure if this belongs here or not. Do ALL characters carry a weapon?
    //double mana;      // This is a specialty for wizards! So, it doesn't belong here.

public:
    // constructors

    // pure virtual methods
    virtual double attack() = 0;
    virtual double defend() = 0;
};


class Weapon
{
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
    vector<string> races;
    vector<string> classification;
    string randRace();                    // randomly returns a race
    string randClass();                   // randomly returns a classification
    string weapon(string classification); // randomly assign a weapon based on character type
                                          // it could be a spell if the character is a wizard
};
