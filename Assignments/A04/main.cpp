/*****************************************************************************
*                    
*  Author:           Angel Badillo
*  Email:            badilloa022402@gmail.com
*  Label:            A04
*  Title:            Basic Project Organization
*  Course:           CMPS 2143
*  Semester:         Fall MWF 12:00 - 12:50
* 
*  Description:
*        This program demonstrates how a circular array queue functions.
* 
*  Usage:
*        Just compile and execute it. Prints out items (integers) from a queue.
* 
*  Files:            main.cpp
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      It is a circular array queue of integers.
 * 
 * Public Methods:
 *      - CircularArrayQue()
 *      - CircularyArrayQue(int size)
 *      - void Push(int item)
 *      - int Pop()
 *      - friend ostream &operator<<(ostream &os, const CircularArrayQue &other)
 * 
 * Private Methods:
 *      - void init(int size = 0)
 *      - bool Full()
 * 
 * Usage: 
 * 
 *      - call the constructor and the argument should
 *      - be an integer of the desired size of the queue.
 *      - push data of type int to store it
 *      - pop to return data of type int
 */
class CircularArrayQue {
private:
    int *Container;  // pointer to allocate array for the queue
    int Front;       // front of the queue
    int Rear;        // rear of the queue
    int QueSize;     // size of the queue
    int CurrentSize; // number of items in the queue

    /**
     * Private: init
     * 
     * Description:
     *      initializes counter and index variables to 0
     * 
     * Params:
     *      - int size
     *      - used to initilize Quesize
     * 
     * Returns:
     *      - returns nothing
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private: Full
     * 
     * Description:
     *      checks if the queue is full, returns true if full
     * 
     * Params:
     *      - none
     * 
     * Returns:
     *      - returns true (bool) if the Queue is full
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    
    /**
     * Public: CircularArrayQue (overloaded)
     * 
     * Description:
     *      Constructor for CircularArrayQue object. Creates a queue of size 10 by default,
     *      or of any size if argument is provided
     * Params:
     *      - CircularArrayQue() has none
     *      - CircularArrayQue(int size) has int size, which is the size of the queue to be created
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public: Push
     * 
     * Description:
     *      Pushes an item of type int to the queue
     * 
     * Params:
     *      - int item
     *      - the item to be pushed into the queue
     * 
     * Returns:
     *      - nothing
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    
    /**
     * Public: Pop
     * 
     * Description:
     *      Pops the first item in the queue
     * 
     * Params:
     *      - none
     * 
     * Returns:
     *      - returns the first item (int) in the queue
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    /**
    * Public: &operator<<
    * 
    * Description:
    *      Inserts the queue to the ostream so it can be printed as a whole.
    * 
    * Params:
    *      - ostream &os
    *      - output stream object by reference  
    *      - const CircularArrayQue &other
    *      - circular array queue object by reference
    * 
    * Returns:
    *      - Returns ostream os, an output stream object that contains the data of a circular array queue
    */
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}