#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Character {
public:
    virtual void attack();
    virtual void defend();
    virtual ~Character();
};

void Character::attack() {
    cout << "attack with fists!!" << endl;
}

void Character::defend() {
    cout << "defend with running away!!" << endl;
}

class Archer : public Character {
public:
    void attack() override;
};

class Mage : public Character {
public:
    void attack() override;

};

void Archer::attack() {
    cout << "Shoot arrows!!" << endl;
}

void Mage::attack() {
    cout << "Conjure magic!!" << endl;
}