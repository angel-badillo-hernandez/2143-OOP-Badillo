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
    Node* next;  // we always need a "link" in a linked list

    Node(int data, int index, Node* next = nullptr)
    {
        this->data = data;
        this->index = index;
        this->next = next;
    }
};

class myVector {
private:
    Node* head;  // base pointer of list
    Node* tail;  // end pointer of list
    int size;
public:
    /**
     * @brief Default Constructor 
     * 
     * Creates a new Linked List object.
     * 
     * @param void
     * @return void
     */
    myVector() {
        head = tail = nullptr;
        size = 0;
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * Creates a new Linked List object from 
     * an array of values.
     * 
     * @param int* A - array of values
     * @param int size - size of array
     * 
     * @return void
     */
    myVector(int* A, int size) {
        head = tail = nullptr;
        this->size = size;

        for (int i = 0; i < size; i++) {
            Push(A[i]);
        }
    }

    void Push(int x) {
        Node* tempPtr = new Node(x, 1);  // create a new node and
                                      // add data to it

        if (!head) {  // `!head` implies empty list
                      // So does `head == NULL`

            head = tempPtr;  // `head = tempPtr` places addrress of
                             // tempPtr in head (points head to tempPtr)

        } else {                   // list not empty
            tempPtr->next = head;  // point tempPtr's next to what head points to
            head = tempPtr;        // now point head to tempPtr
        }
    }

    void print() {
        Node* temp = head;  // temp pointer copies head

        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            cout << temp->data;  // print data from node
            if (temp->next) {
                cout << "->";
            }
            temp = temp->next;  // move to next node
        }
        cout << endl;
    }

    ~myVector() {
    }
};