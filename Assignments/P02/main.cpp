/*****************************************************************************
*                    
*  Author:           Angel Badillo
*  Email:            badilloa022402@gmail.com
*  Label:            P02
*  Title:            MyVector Class 2
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This program implements a class called MyVector that is essentially
*        a double linked list with overloaded constuctors that can append
*        or prepend a double linked list to another double linked list.
*        It can also add items to a specific location, search for an item
*        and return the index, and remove an item at a specific location.
*        
*  Usage:
*       - g++ main.cpp -o main && ./main
*       - You just compile and run it.
* 
*  Files:     
*       main.cpp        : driver program
*       MyVector.hpp    : header file with definition and implementation
*       input.dat       : input file
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "MyVector.hpp"

int main()
{
  int a[5] = {1,1,2,3,4};

  MyVector v1(a, 5);
  MyVector v2 = v1;
  v2.pushRear(6);

  cout << v1 << '\n';
  cout << v2 << '\n';

  MyVector v3 = v1 + v2;

  cout << v3;

  


  return 0;
}