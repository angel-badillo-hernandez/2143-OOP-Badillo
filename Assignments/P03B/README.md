## PO3 - BolNiverse Fight Club
### Angel Badillo
### Description:

This program is the randomized "battle simulation" where a number of attackers are fighting a small group of defenders (1 defender of each type per 100 attackers).
E.g: 1000 attackers vs. 10 defenders. The program is fairly balanced so neither side wins too frequently. The point of this program is to demonstrate run-time polymorphism using BaseFighter points that point to an instance of any of BaseFighter's subclasses.

### Files

|   #   | File                                 | Description                                                                                     |
| :---: | ------------------------------------ | ----------------------------------------------------------------------------------------------- |
|   1   | [main.cpp](main.cpp)                 | Main driver for program                                                                         |
|   2   | [fighter.hpp](fighter.hpp)           | Header for fighter classes                                                                      |
|   3   | [fighterData.json](fighterData.json) | Data to be used with fighter classes                                                            |
|   4   | [weapon.hpp](weapon.hpp)             | Header for weapon class                                                                         |
|   5   | [weapons.json](weapons.json)         | Data to be used with  weapon class                                                              |
|   6   | [helpers.hpp](helpers.hpp)           | Helper functions for dice and randomization of data                                             |
|   7   | [dice.hpp](dice.hpp)                 | Header for die and dice classes                                                                 |
|   8   | [json.hpp](json.hpp)                 | Header for using JSON in C++, credit to the creator(s) [here](https://github.com/nlohmann/json) |
|   9   | [attackers.txt](attackers.txt)       | Data file used for generating specified amount of attackers                                     |
|  10   | [banner.txt](banner.txt)             | Banner for this Program                                                                         |
|  11   | [P03B.txt](P03B.txt)                 | Output for my test run                                                                          |



### Instructions

- Just compile and run the program.
- Note: fighterData.json and weapons.json must be present in the folder as is. attackers.txt must also be present, but contents can be altered, as long as it follows the same format (i.e contains the name of a kind of Fighter per line).
- Example Command:
  - g++ main.cpp -o main
  - ./main
