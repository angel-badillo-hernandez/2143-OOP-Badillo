#include <iostream>
#include <queue>

using namespace std;

class CharacterGen
{
    string randRace();                    // randomly returns a race
    string randClass();                   // randomly returns a classification
    string weapon(string classification); // randomly assign a weapon based on character type
                                          // it could be a spell if the character is a wizard
};

class BaseCharacter
{
    string name;
    string race;   // Does a character inherit from race? Or are they composed of a race?
    string gender; // Same for gender. Does race or gender offer any special properties that
                   //      could be inherited by a character?
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

class Wizard : public BaseCharacter
{
private:
    double mana;
    double castSpell()
    {
        return rand() % 100;
    }

public:
    double attack()
    {
        double rtn = 0.0;
        rtn = castSpell();
        cout << "Wizard attack\n";
        return rtn;
    }

    double defend()
    {
        double rtn = 0.0;

        return rtn;
    }
};

class Warrior : public BaseCharacter
{
private:
    double hitPoints;
    double slash()
    {
        return rand() % 100;
    }

public:
    double attack()
    {
        double rtn = 0.0;
        rtn = slash();
        cout << "Warrior attack\n";
        return rtn;
    }

    double defend()
    {
        double rtn = 0.0;

        return rtn;
    }
};

int main()
{
    BaseCharacter *BC1 = new Wizard;
    BC1 = new Wizard;
    BaseCharacter* BC2 = BC1;
    BC1->attack();

    BC1 = new Warrior;
    BC1->attack();
}