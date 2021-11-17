/*****************************************************************************
*                    
*  Author:           Angel Badillo
*  Email:            badilloa022402@gmail.com
*  Label:            P03B
*  Title:            BoliNverse Fight Club
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This program
*        
*  Usage:
*       - g++ main.cpp -o main && ./main
*       - You just compile and run it.
* 
*  Files:     
*       main.cpp      : driver program
*       FightClub.hpp : header file with definition and implementation of "game"
*       output.txt    : output of program
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fighter.hpp"
#include "json.hpp"
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    BaseFighter* jojo;
    BaseFighter* dio;
    jojo = new Wizard;
    dio = new Warrior;
    jojo->attack(dio);
    
    

}