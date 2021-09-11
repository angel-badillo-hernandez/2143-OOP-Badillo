#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

/**
 * @brief brief description
 * 
 *
 * 
 * 
 * 
 */
class Node 
{
public:
    int data;  // data value (could be a lot more values)
    int index;
    Node* prev;
    Node* next;  // we always need a "link" in a linked list

    Node(int data, Node* prev = nullptr, Node* next = nullptr);
};

class MyVector
{
private:
    Node* head;
    Node* tail;
    int size;
    const int INTMAX = std::numeric_limits<int>::max();

public:
    MyVector();                    //Default constructor
    
    MyVector(int* A, int size);    //Array constructor
    
    MyVector(string fileName);     //Input constructor

    ~MyVector();                   // Deletes

    void pushFront(int x);         // Pushes
    void pushFront(MyVector& V2);

    void pushRear(int x);          // Pushes
    void pushRear(MyVector& V2);

    void pushAt(int i, int x);

    int popFront();
    
    int popRear();

    int popAt(int loc);

    int find(int val);

    int getSize();
    
    void print();
};