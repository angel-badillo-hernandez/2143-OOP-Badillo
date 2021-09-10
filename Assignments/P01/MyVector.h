#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Load array with values from a file
 * 
 * @param string filename 
 * @param int*& arr 
 * @param int& size 
 */
void loadArr(string filename, int*& arr, int& size) {
    ifstream fin;         // stream reference
                          //
    fin.open(filename);   // open the file
                          //
    fin >> size;          // get first value which contains
                          // number of remaining values in file
                          //
    arr = new int[size];  // allocate new array of correct size
                          //
    int i = 0;            // need an array index for our while loop
                          //
    // Can also use for loop since we know the exact count in file.
    // eof = end of file flag
    // `!fin.eof()` evaulates to true when we hit end of file.
    while (!fin.eof()) {
        fin >> arr[i];  // read file value straight into array
                        // at index i
        i++;            // increment array index
    }
}

/**
 * @brief Prints an array
 * 
 * @param int arr 
 * @param int size
 * 
 * @returns void
 */
void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "]";
    }
    cout << "\n";
}

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

class myVector
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    myVector();
    
    myVector(int* A, int size);
    
    myVector(string fileName);

    void pushFront(int x);

    void pushRear(int x);

    void pushAt(int i, int x);

    int popFront();
    
    int popRear();

    void print();
};
