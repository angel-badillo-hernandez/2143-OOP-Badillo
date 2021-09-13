#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const int INTMAX = numeric_limits<int>::max(); // Max value of int, used for errors

/**
 * Node
 * 
 * Description:
 *      Creates a Node that can stored data, and has pointers meant for
 *      the previous Node and next Node. Meant to be used in double linked list
 * 
 * Public Methods:
 *                Node(int _data, Node *_prev = nullptr, Node *_next = nullptr)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      Node(val, nullptr, head);   // Creates an instance of Node
 *                                  // stores val in Node.data
 *                                  // sets Node.prev to nullptr
 *                                  // sets Node.next to Node* head
 *       
 */
class Node
{
public:
    int data;   // Data value
    int index;  // Index of item
    Node *prev; // Points to previous node on list
    Node *next; // Points to next node on list

    /**
     * Public: Node
     * 
     * Description:
     *      Constructs an instance of Node
     * 
     * Params:
     *      int     : data of Node
     *      Node*   : pointer to previous Node
     *      Node*   : pointer to next Node
     * 
     */
    Node(int _data, Node *_prev = nullptr, Node *_next = nullptr)
    {
        data = _data;
        prev = _prev;
        next = _next;
    }
};

/**
 * MyVector
 * 
 * Description:
 *      Creates a vector. The vector is based off of a double linked list.
 *      It's size changes dynamically and vectors can be appended/prepended
 *      to other vectors.
 * 
 * Public Methods:
 *              MyVector()
 *              MyVector(MyVector& V2)
 *              MyVector(int* A, int size)
 *              MyVector(string fileName)
 *              ~MyVector()
 *      void    pushFront(int val)
 *      void    pushFront(MyVector& V2)
 *      void    pushRear(int val)
 *      void    pushRear(MyVector& V2)
 *      void    pushAt(int loc, int val)
 *      int     popFront()
 *      int     popRear()
 *      int     popAt(int loc)
 *      int     find(int val)
 *      void    print()
 *      void    print(ofstream& infile)
 *      int     getSize()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      MyVector v1;                // Create instance of MyVector
 *      v1.pushFront(2);            // prepends 2 to vector
 *      v1.pushRear(val);           // appends val to vector
 *      int x = v1.popFront();      // pops front
 *      int y = v1.popRear();       // pops rear
 *      int p = v1.popAt(1);        // pops at index
 *      int z = v1.find();          // finds index of an item
 *      v1.print();                 // prints to stdout
 *      v1.print(outfile);          // prints to output file 
 *      int size = v1.getSize();    // returns size of vector   
 *      
 */
class MyVector
{
private:
    Node *head; // Head of the vector
    Node *tail; // Tail of the vector
    int size;   // Size of vector

public:
    /**
     * Public: MyVector
     * 
     * Description:
     *      Creates an empty instance of MyVector
     * 
     * Params:
     *      - None
     */
    MyVector() //Default constructor
    {
        head = tail = nullptr;
        size = 0;
    }

    /**
     * Public: MyVector
     * 
     * Description:
     *      Creates an vector by coping another vector
     * 
     * Params:
     *      MyVector& : vector to be copied
     */
    MyVector(MyVector &V2)
    {
        head = tail = nullptr;
        size = 0;

        Node *temp = V2.head;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    /**
     * Public: MyVector
     * 
     * Description:
     *      Creates an instance of MyVector by copying an array
     * 
     * Params:
     *      int*    : array of integers
     *      int     : size of array
     */
    MyVector(int *A, int _size) //Array constructor
    {
        head = tail = nullptr;
        size = 0;

        for (int i = 0; i < _size; i++)
        {
            pushRear(A[i]);
        }
    }

    /**
     * Public: MyVector
     * 
     * Description:
     *      Creates an instance of MyVector by reading in values from an input file
     * 
     * Params:
     *      string  : file name of input file
     */
    MyVector(string fileName) //Input file constructor
    {
        ifstream infile;
        infile.open(fileName);

        head = tail = nullptr;
        size = 0;

        int val;
        while (!infile.eof())
        {
            infile >> val;
            pushRear(val);
            size++;
        }
        infile.close();
    }

    /**
     * Public: ~MyVector
     * 
     * Description:
     *      Deletes the vector
     * 
     * Params:
     *      - None
     */
    ~MyVector()
    {
        while (head)
        {
            popFront();
        }
    }

    /**
     * Public: pushFront
     * 
     * Description:
     *      Prepends an item to the vector
     * 
     * Params:
     *      int : item to be prepended
     * 
     * Returns:
     *      void
     */
    void pushFront(int val)
    {
        if (!head) // If empty vector
        {
            head = tail = new Node(val); // 1 item, so head & tail are same
        }
        else if (head == tail) // If one item
        {
            head = new Node(val, nullptr, head); // New head->next points to old head
            tail->prev = head;                   // tail->prev points to new head
        }
        else
        {
            head = new Node(val, nullptr, head); // New head->next points to old head
            head->next->prev = head;             // Old head->prev points to new head
        }
        size++;
    }

    /**
     * Public: pushFront
     * 
     * Description:
     *      Prepends an entire other vector to a vector
     * 
     * Params:
     *      MyVector&   : vector object by reference
     * 
     * Returns:
     *      void
     */
    void pushFront(MyVector &V2)
    {
        Node *temp = V2.tail;

        while (temp)
        {
            pushFront(temp->data); // Pushes vector to the front right to left
            temp = temp->prev;
        }
    }

    /**
     * Public: pushRear
     * 
     * Description:
     *      Appends an item to the vector
     * 
     * Params:
     *      int : item to be appended
     * 
     * Returns:
     *      void
     */
    void pushRear(int val) // Pushes
    {
        if (!head)
        {
            head = tail = new Node(val); // 1 item, so head & tail are same
        }
        else if (head == tail)
        {
            tail = new Node(val, tail); // New tail->prev points to old tail
            head->next = tail;          // head->next points to new tail
        }
        else
        {
            tail = new Node(val, tail); // New tail->prev points to old tail
            tail->prev->next = tail;    // Old tail->next points to new tail
        }
        size++;
    }

    /**
     * Public: pushRear
     * 
     * Description:
     *      Appends an entire other vector to a vector
     * 
     * Params:
     *      MyVector&   : vector object by reference
     * 
     * Returns:
     *      void
     */
    void pushRear(MyVector &V2)
    {
        Node *temp = V2.head;

        while (temp)
        {
            pushRear(temp->data); // Pushes vector to the back left to right
            temp = temp->next;
        }
    }

    /**
     * Public: pushAt
     * 
     * Description:
     *      Pushes an item to a specific location in the vector
     * 
     * Params:
     *      int : location in vector
     *      int : item to be pushed
     * 
     * Returns:
     *      void
     */
    void pushAt(int loc, int val)
    {
        if (loc >= 0 && loc < size)
        {
            Node *temp = head;

            for (int i = 0; i > loc; i++)
            {
                temp = temp->next;
            }

            temp->data = val;
        }
        else
        {
            cout << "\n<ERROR: Cannot access out of bounds.>\n";
        }
    }

    /**
     * Public: popFront
     * 
     * Description:
     *      Pops front item in vector
     * 
     * Params:
     *      - None
     * 
     * Returns:
     *      int : item that was popped from vector
     */
    int popFront()
    {
        if (!head)
        {
            cout << "\n<ERROR: Cannot pop from empty vector.>\n";
            return INTMAX;
        }
        else if (head == tail)
        {
            int returnMe = head->data;
            delete head;
            head = tail = nullptr;
            size--;
            return returnMe;
        }
        else
        {
            int returnMe = head->data; // Save data for return
            Node *deleteMe = head;     // Save pointer for deletion
            head = head->next;         // Move head down
            head->prev = nullptr;

            delete deleteMe;
            size--;
            return returnMe;
        }
    }

    /**
     * Public: popRear
     * 
     * Description:
     *      Pops rear item from the vector
     * 
     * Params:
     *      - None
     * 
     * Returns:
     *      int : item that was popped from vector
     */
    int popRear()
    {
        if (!tail)
        {
            cout << "\n<ERROR: Cannot pop from empty vector.>\n";
            return INTMAX;
        }
        else if (head == tail) // When only one item in vector
        {
            int returnMe = tail->data;
            delete tail;
            head = tail = nullptr;
            size--;
            return returnMe;
        }
        else
        {
            int returnMe = tail->data; // Save data for return
            Node *deleteMe = tail;     // Save pointer for deletion
            tail = tail->prev;         // Move tail up
            tail->next = nullptr;      // Double linked list ends in nullptr

            delete deleteMe;
            size--;
            return returnMe;
        }
    }

    /**
     * Public: popAt
     * 
     * Description:
     *      Pops an item from the vector at a given index
     * 
     * Params:
     *      int : location (index) of item to be popped
     * 
     * Returns:
     *      int : item that was removed from vector
     */
    int popAt(int loc)
    {
        if (!head) // If vector is empty
        {
            cout << "\n<ERROR: Cannot pop from empty vector.>\n";
            return INTMAX;
        }
        else if (loc < 0 || loc > size - 1) // loc is out of bounds
        {
            cout << "\n<ERROR: Out of bounds.>\n";
            return INTMAX;
        }
        else if (loc == 0) // loc is frontmost item
        {
            return popFront();
        }
        else if (loc == size - 1) // loc is rearmost item
        {
            return popRear();
        }
        else // Travels through until it reaches index
        {
            Node *temp = head;
            for (int i = 0; i < loc; i++)
            {
                temp = temp->next;
            }
            int returnMe = temp->data;
            temp->prev->next = temp->next; // Links temp->prev Node to temp->next Node
            temp->next->prev = temp->prev; // and vice-versa
            delete temp;

            return returnMe;
        }
    }

    /**
     * Public: find
     * 
     * Description:
     *      Travels through the vector and searches for the index of an item
     * 
     * Params:
     *      int : item to be searched for
     * 
     * Returns:
     *      int :   index of item that was searched for
     */
    int find(int val)
    {
        Node *temp = head;
        int i = 0;

        while (temp)
        {
            if (val == temp->data) // If found, return index
            {
                return i;
            }
            else // Move to next node
            {
                temp = temp->next;
                i++;
            }
        }
        return -1;
    }

    /**
     * Public: print
     * 
     * Description:
     *      Prints the entire vector to stdout
     * 
     * Params:
     *      - None
     * 
     * Returns:
     *      void
     */
    void print()
    {
        if (head) // If head exists
        {
            Node *travel = head; // travel points to head

            cout << "[";

            while (travel) // Travels until travel == nullptr
            {
                cout << travel->data; // Print data from node
                if (travel->next)
                {
                    cout << ", ";
                }
                travel = travel->next; // Move to next node
            }
            cout << ']' << endl;
        }
    }

    /**
     * Public: print
     * 
     * Description:
     *      Prints entire vector to output file
     * 
     * Params:
     *      ofstream&   : output file stream by reference
     * 
     * Returns:
     *      void        : returns void but prints to file
     */
    void print(ofstream &outfile)
    {
        if (head) // If head exists
        {
            Node *travel = head; // travel points to head

            outfile << "[";

            while (travel) // Travels until travel == nullptr
            {
                outfile << travel->data; // Print data from node
                if (travel->next)
                {
                    outfile << ", ";
                }
                travel = travel->next; // Move to next node
            }
            outfile << ']' << endl;
        }
    }

    /**
     * Public: getSize()
     * 
     * Description:
     *      Returns the size of the vector
     * 
     * Params:
     *      - None
     * 
     * Returns:
     *      int        : returns size of vector
     */
    int getSize()
    {
        return size;
    }
};