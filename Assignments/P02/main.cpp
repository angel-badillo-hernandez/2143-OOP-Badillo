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
*        In this second program, the [] bracket operator, equal-to operator,
*        the not equal-to operator, the compound assignment operators and 
*        arithmetic are implemented, so you can treat the vector as an array,
*        check for equality, use compound assignment, and add, subtract,
*        multiply, and divide.
*        
*  Usage:
*       - g++ main.cpp -o main && ./main
*       - You just compile and run it.
* 
*  Files:     
*       main.cpp        : driver program
*       MyVector.hpp    : header file with definition and implementation
*       output.txt      : output of program
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "MyVector.hpp"

int main()
{

  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  MyVector v1(a1, 5);
  MyVector v2(a2, 3);

  ofstream fout;
  fout.open("output.txt");

  cout << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.

  fout << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  // writes out [11,22,33,4,9] to console.

  v3 = v1 - v2;
  cout << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  // writes out [9,18,27,4,9] to console.

  v3 = v2 * v1;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 * v2;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 / v2;
  cout << v3 << endl;
  // writes out [0,0,0,4,9] to console.

  v3 = v2 / v1;
  cout << v3 << endl;
  // writes out [10,10,10,4,9] to console.

  cout << (v2 == v1) << endl;
  // writes 0 to console (false) .

  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  // writes 1 to console (true) .

  fout.close();
  return 0;
}