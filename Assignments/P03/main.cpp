#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Bolinverse.hpp"

using namespace std;

int main()
{
    BaseCharacter* jojo = new Archer;
    BaseCharacter* dio = new Wizard;

    cout << "\nO\n";

    jojo->attack(dio);

    cout << "*oof*\n";

    cout << "Dio has " << dio->HP() << " hp.\n";
}