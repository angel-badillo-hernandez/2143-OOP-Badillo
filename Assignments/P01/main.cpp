/*****************************************************************************
*                    
*  Author:           Angel Badillo
*  Email:            badilloa022402@gmail.com
*  Label:            P01
*  Title:            MyVector Class
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
#include <string>
#include <fstream>
#include "MyVector.hpp"
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("test.out");

    outfile << "Angel Badillo\n"
            << "09/10/2021\n"
            << "Fall 2143\n\n";

    int x = 0;

    MyVector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    v1.print(outfile);
    // [25, 20, 18, 18, 20, 25]

    int A[] = {11, 25, 33, 47, 51};
    MyVector v2(A, 5);
    v2.print();
    v2.print(outfile);

    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    //v2.inOrderPush(27);
    v2.pushRear(63);
    v2.print();
    v2.print(outfile);
    // [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);
    v1.print();
    v1.print(outfile);
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    v1.print(outfile);
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
    cout << x << endl;
    // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    v1.print(outfile);
    // [18, 20, 25, 9, 11, 25, 27, 33]
    cout << x << endl;
    // 47

    x = v2.popAt(3);
    v2.print();
    v2.print(outfile);
    // [9, 11, 25, 47, 51, 63]
    cout << x << endl;
    outfile << x << endl;
    // 33

    x = v2.find(51);
    cout << x << endl;
    outfile << x << endl;
    // 4

    x = v2.find(99);
    cout << x << endl;
    outfile << x << endl;
    // -1

    MyVector v3(v1);
    v3.print();
    v3.print(outfile);
    // [18, 20, 25, 9, 11, 25, 33]

    v3.pushFront(v2);
    v3.print();
    v3.print(outfile);
    //[9, 11, 25, 47, 51, 63, 18, 20, 25, 9, 11, 25, 33]

    MyVector v4("input.dat");
    v4.pushRear(v3);
    v4.print();
    v4.print(outfile);
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    outfile.close();
    return 0;
}