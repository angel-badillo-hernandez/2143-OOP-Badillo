#include <fstream>
#include <iostream>
#include <string>

// Node for our linked list
struct node {
    int data;  // data value (could be a lot more values)

    node* next;  // we always need a "link" in a linked list

    node(int x) {  // cunstructor to make adding values easy
        data = x;
        next = NULL;
    }
};

class MyVector
{
private:
    /* data */
public:
    MyVector(/* args */);
    ~MyVector();
};

MyVector::MyVector()
{
}

MyVector::~MyVector()
{
}
