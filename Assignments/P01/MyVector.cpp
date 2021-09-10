#include "MyVector.h"

Node::Node(int data, Node *prev = nullptr, Node *next = nullptr)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}

DLList::DLList()
{
    head = tail = nullptr;
    size = 0;
}

DLList::DLList(int *A, int size)
{
    head = tail = nullptr;

    for (int i = 0; i < size; i++)
    {
        pushRear(A[i]);
    }

}

DLList::DLList(string fileName)
{
    ifstream infile;
    infile.open(fileName);

    head = tail = nullptr;
    size = 0;

    while (!infile.eof())
    {
        int x;
        infile >> x;
        pushRear(x);
        size++;
    }
    infile.close();
}

void DLList::pushFront(int x)
{
    if (!head)
    {
        head = tail = new Node(x);         // 1 item, so head & tail are same
    }
    else if (head = tail)
    {
        head = new Node(x, nullptr, head); // New head->next points to old head
        tail->prev = head;                 // tail->prev points to new head

    }
    else
    {
        head = new Node(x, nullptr, head); // New head->next points to old head
        head->next->prev = head;           // Old head->prev points to new head      
    }
    size++;
}

void DLList::pushRear(int x)
{
    if (!head)
    {
        head = tail = new Node(x);          // 1 item, so head & tail are same
    }
    else if (head = tail)
    {
        tail = new Node(x, tail);           // New tail->prev points to old tail
        head->next = tail;                  // head->next points to new tail
    }
    else
    {
        tail = new Node(x, tail);           // New tail->prev points to old tail
        tail->prev->next = tail;            // Old tail->next points to new tail
    }
    size++;
}

void DLList::pushAt(int loc, int x)
{
    if( loc == 0)
    {
        pushFront(x);
    }
    else if(loc == size)
    {
        pushRear(x);
    }
    else
    {
        if (loc > (size - 1) / 2)
        {
            Node* position = head;

            for (int i = 0; i > loc; i++)
            {
                position = position->next;
            }

            position = new Node(x, position->prev, position); // New node->prev points to travel->prev
                                                        // New node->next points to travel
        }
    }
}

int DLList::popFront()
{
    if(head)
    {
        int returnMe = head->data; // Save data for return
        Node* deleteMe = head;     // Save pointer for deletion
        head = head->next;         // Move head down
        head->prev = nullptr;

        delete deleteMe;
        size--;
        return returnMe;
    }
}

int DLList::popRear()
{
    if (tail)
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

void DLList::print()
{
    Node *temp = head; // temp pointer copies head

    while (temp)
    {   // this loops until temp is NULL
        // same as `while(temp != NULL)`

        cout << temp->data; // print data from node
        if (temp->next)
        {
            cout << "->";
        }
        temp = temp->next; // move to next node
    }
    cout << endl;
}
