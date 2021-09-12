#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int INTMAX = numeric_limits<int>::max(); // Max value of int, used for errors

class Node
{
public:
    int data;   // Data value
    int index;  // Index of item
    Node *prev; // Points to previous node on list
    Node *next; // Points to next node on list

    Node(int _data, Node *_prev = nullptr, Node *_next = nullptr)
    {
        data = _data;
        prev = _prev;
        next = _next;
    }
};

class MyVector
{
private:
    Node *head; // Head of the vector
    Node *tail; // Tail of the vector
    int size;   // Size of vector

public:
    MyVector() //Default constructor
    {
        head = tail = nullptr;
        size = 0;
    }

    MyVector(MyVector& V2)
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

    MyVector(int *A, int _size) //Array constructor
    {
        head = tail = nullptr;
        size = 0;

        for (int i = 0; i < _size; i++)
        {
            pushRear(A[i]);
        }
    }

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

    ~MyVector() // Deletes
    {
        if (head)
        {
            for (int i = 0; i < size; i++)
            {
                popFront();
            }
        }
    }

    void pushFront(int val) // Pushes
    {
        if (!head)
        {
            head = tail = new Node(val); // 1 item, so head & tail are same
        }
        else if (head == tail)
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

    void pushFront(MyVector &V2)
    {
        Node *temp = V2.tail;

        while (temp)
        {
            pushFront(temp->data);
            temp = temp->prev;
        }
    }

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

    void pushRear(MyVector &V2)
    {
        Node *temp = V2.head;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    void pushAt(int loc, int x)
    {
        if (loc >= 0 && loc < size)
        {
            Node *position = head;

            for (int i = 0; i > loc; i++)
            {
                position = position->next;
            }

            position->data = x;
        }
        else
        {
            cout << "\n<ERROR: Cannot access out of bounds.>\n";
        }
    }

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

    int popRear()
    {
        if (!tail)
        {
            cout << "\n<ERROR: Cannot pop from empty vector.>\n";
            return INTMAX;
        }
        else if (head == tail)
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
            tail->next = nullptr;

            delete deleteMe;
            size--;
            return returnMe;
        }
    }

    int popAt(int loc)
    {
        if(!head)
        {
            cout << "\n<ERROR: Cannot pop from empty vector.>\n";
            return INTMAX;
        }
        else if(loc < 0 || loc > size-1)
        {
            cout << "\n<ERROR: Out of bounds.>\n";
            return INTMAX;
        }
        else if(loc == 0)
        {
            return popFront();
        }
        else if(loc == size-1)
        {
            return popRear();
        }
        else
        {
            Node* temp = head;
            for(int i = 0; i < loc; i++)
            {
                temp = temp->next;
            }
            int returnMe = temp->data;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            
            return returnMe;
        }
    }

    int find(int val)
    {
        Node* temp = head;
        int i = 0;
        while(temp)
        {
            if(val == temp->data)
            {
                return i;
            }
            else
            {
                temp = temp->next;
                i++;
            }
        }
        return -1;
    }

    void print()
    {
        if (head) // If head exists
        {
            Node *travel = head;        // travel points to head

            cout << "[";

            while (travel)             // Travels until travel == nullptr
            {
                cout << travel->data;  // Print data from node
                if (travel->next)
                {
                    cout << ", ";
                }
                travel = travel->next; // Move to next node
            }
            cout << ']' << endl;
        }
    }

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
};