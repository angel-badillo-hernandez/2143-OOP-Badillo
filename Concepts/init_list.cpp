#include <iostream>

using namespace std;

class A
{
protected:
    int x;
    int y;
    int z;
public:
    A():x(0),y{0},z(0){}
    A(int x, int y, int z):x{x},y{y},z(z){}
};

class B: public A
{
public:
    B()
    {
        cout << x << endl;
    }
};

int main()
{
    A obj1;
    A obj2(2, 3, 4);

    B obj3;
}