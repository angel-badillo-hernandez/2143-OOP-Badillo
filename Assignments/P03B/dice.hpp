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
#include <vector>
#include <string>
#include "helpers.hpp"

using namespace std;

#pragma once

/**
 * Die
 *
 * Description:
 *      This class is meant to be a component of Dice class. It is meant
 *      to be used for "dice rolling".
 *
 * Public Methods:
 *      - Die()
 *      - Die(int sides)
 *      - int roll(int rolls = 1)
 *      - ostream& operator<<(ostream &os, const Die& d)
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *      - Note meant to be used alone, but rather to be a component of
 *      - a Dice class used for Weapon damages.
 *      Die d(6);
 *      d.roll(); // Rolls a single 6-sided die.
 */
class Die
{
    int sides;

public:
    Die() : sides{6} {}
    Die(int sides) : sides{sides} {}
    int roll(int rolls = 1)
    {
        int sum = 0;
        while (rolls--)
        {
            sum += (rand() % sides) + 1;
        }
        return sum;
    };
    friend ostream &operator<<(ostream &os, const Die &d)
    {
        return os << "[" << d.sides << "]";
    }
};

/**
 * Dice
 *
 * Description:
 *      Used for "calculating" damage per attack with a weapon with "dice rolls".
 *
 * Public Methods:
 *      - Dice()
 *      - Dice(int n, int s)
 *      - Dice(string d)
 *      - void init(int n, int s)
 *      - int roll(int rolls = 1)
 *      - ostream& operator<<(ostream &os, Dice &d)
 *
 * Private Methods:
 *      - A list of
 *      - each private method
 *      - with return types
 *
 * Usage:
 *
 *      - examples of how
 *      - to use your class
 *
 */
class Dice
{
private:
    vector<Die> dice;
    bool average;
    bool best;
    bool constant;

public:

    /**
     * @brief Construct a new Dice object.
     * 
     */
    Dice()
    {
        init(1, 6);
    }

    /**
     * @brief Construct a new Dice object with parameters.
     * 
     * @param n An integer, number of dice.
     * @param s An integer, numbers of sides per die.
     */
    Dice(int n, int s)
    {
        init(n, s);
    }

    /**
     * @brief Construct a new Dice object with a string representing "damage".
     * 
     * @param d A string that represents the damage for a weapon.
     */
    Dice(string d)
    {
        vector<string> parts = tokenize(d, ".");

        int n = stoi(parts[0]);
        int s = stoi(parts[2]);

        init(n, s);
    }

    /**
     * @brief Intializes dice given these parameters.
     * 
     * @param n An integer, number of dice.
     * @param s An integer, number of sides per die.
     */
    void init(int n, int s)
    {
        while (n--)
        {
            dice.push_back(Die(s));
        }
    }

    /**
     * @brief Roll the dice
     *
     * @param rolls
     * @return int
     */
    int roll(int rolls = 1)
    {
        int sum = 0;
        while (rolls--)
        {
            for (int i = 0; i < dice.size(); i++)
            {
                sum += dice[i].roll();
            }
        }
        return sum;
    }

    /**
     * @brief Overloaded ostream to test if the Dice are constructed correctly.
     *
     * @param os An ostream by reference.
     * @param d  A Dice object by reference.
     * @return ostream&
     */
    friend ostream &operator<<(ostream &os, const Dice &d)
    {
        for (int i = 0; i < d.dice.size(); i++)
        {
            os << d.dice[i];
        }
        return os;
    }
};