#include <iostream>
#include <fstream>

using namespace std;

template <class T, class P>
auto sum(T x, P y)
{
    auto z = x + y;
    return z;
}

int main()
{
    string x = "Hello ";
    string y = "world!";
    
    int a = 1;
    double b = 1.1;

    cout << sum(x, y) << '\n';

    cout << sum(a, b) << '\n';
}
