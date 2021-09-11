#include "MyVector.h"

Node::Node(int data, Node *prev, Node *next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}

MyVector::MyVector()
{
    this->head = this->tail = nullptr;
    size = 0;
}

MyVector::MyVector(int *A, int size)
{
    this->head = this->tail = nullptr;
    this->size = size;

    for (int i = 0; i < size; i++)
    {
        pushRear(A[i]);
    }

}

MyVector::MyVector(string fileName)
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

MyVector::~MyVector()
{
      for(int i = 0; i < size; i++)
      {
        popFront();
      }
}

void MyVector::pushFront(int x)
{
    if (!head)
    {
        head = tail = new Node(x);         // 1 item, so head & tail are same
    }
    else if (head == tail)
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

void MyVector::pushFront(MyVector& V2)
{
  if(!head)
  {
    this->size = V2.getSize();

    for(int i = 0; i < this->size; i++)
    {
      pushFront(V2.popRear());
    }
  }
  else
  {
    this->size += V2.getSize();
    for(int i = 0; i < V2.getSize(); i++)
    {
      pushFront(V2.popRear());
    }
  }
}

void MyVector::pushRear(int x)
{
    if (!head)
    {
        head = tail = new Node(x);          // 1 item, so head & tail are same
    }
    else if (head == tail)
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

void MyVector::pushRear(MyVector& V2)
{
  if(!head)
  {
    this->size = V2.getSize();

    for(int i = 0; i < V2.getSize(); i++)
    {
      pushRear(V2.getFront());
    }
  }
  else
  {
    this->size += V2.getSize();
    for(int i = 0; i < V2.getSize(); i++)
    {
      pushFront(V2.getFront());
    }
  }
}

void MyVector::pushAt(int loc, int x)
{
  if ( loc >= 0 && loc < size)
  {
    Node* position = head;

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

int MyVector::popFront()
{
    if(!head)
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
        Node* deleteMe = head;     // Save pointer for deletion
        head = head->next;         // Move head down
        head->prev = nullptr;

        delete deleteMe;
        size--;
        return returnMe;
    }
    
}

int MyVector::popRear()
{
    if (!tail)
    {
        cout << "\n<ERROR: Cannot pop from empty vector.>\n";
        return INTMAX;
    }
    else if(head == tail)
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

int MyVector::popAt(int loc)
{
  if ( loc >= 0 && loc < size)
  {
    Node* position = head;

    for (int i = 0; i > loc; i++)
    {
      position = position->next;
    }

    int returnMe = position->data;
    position->prev->next = position->next;
    position->next->prev = position->prev;
    delete position;
    return returnMe;
  }
  else
  {
    cout << "\n<ERROR: Cannot pop out of bounds.>\n";
    return INTMAX;
  }
}

void MyVector::print()
{
    if(head)
    {
      Node *temp = head; // temp pointer copies head
      cout << "\n[";
      while (temp)
      {   // this loops until temp is NULL
        // same as `while(temp != NULL)`
        
        cout << temp->data; // print data from node
        if (temp->next)
        {
            cout << ", ";
        }
        temp = temp->next; // move to next node
      }
      cout << ']' << endl;
    }
    else
    {
      cout << "\n<ERROR: Cannot print from empty vector.>\n";
    }
}

int MyVector::find(int val)
{
  if(head)
  {
    Node *temp = head; // temp pointer copies head

    if(val == head->data)
    {
      return 0;
    }
    else if(val == tail->data)
    {
      return size-1;
    }
    else
    {
      for (int i = 0; i > size; i++)
      {
        temp = temp->next;

        if(val == temp->data)
        {
          return i;
        }

      }
    }
  }
  
  cout << "\n<ERROR: Item not found.>\n";
  return INTMAX;
}

int MyVector::getSize()
{
  return size;
}