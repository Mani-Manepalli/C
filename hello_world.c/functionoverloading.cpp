#include <iostream>
using namespace std;

void cube(int a)
{

    cout << "Cube Value:" << a * a * a;
}

void cube(int a, bool)
{
    cout << "\nSquare Value:" << a * a;
}

int main()
{

    int a = 2;

    cube(a);

    cube(a, true);

    return 0;
}