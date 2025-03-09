/*Write a program to print the area of a rectangle by creating a class named 'Area' having two functions. First
function named as 'setDim' takes the length and breadth of the rectangle as parameters and the second
function named as 'getArea' returns the area of the rectangle. Length and breadth of the rectangle are entered
through keyboard.
*/
#include<iostream>
using namespace std;
class Area{

    int length,breadth;

    public:

    void setdim(int a,int b)
    {
        length  = a;
        breadth = b;
    };

    int getarea(){

        return length*breadth;
    };



};


int main()
{
    int length,breadth,output;
    cout << "Enter length,Breadth values:";
    cin >> length >> breadth;

    Area area;
    area.setdim(length,breadth);
    output =area.getarea();
    cout << "Area is:"<<output;

    return 0;
}
