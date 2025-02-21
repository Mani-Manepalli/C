#include<iostream>
using namespace std;
class En4{
    public:
    string Name;
    string Colour;
    int Enrollment_number;

    void input(){
        cout << "Name enter chey raa pumkaa..!:\n";
        cin >> Name;
        cout << "colour chepu beyy:\n";
        cin >> Colour;
        cout << "enrollmentnum chepu ra ulli ga:\n";
        cin >> Enrollment_number;

    };
    void display(){
        cout << "Name:"<<Name<<"\ncolour:"<<Colour<<"\nenroll:"<<Enrollment_number;

    };

    int main(){
        En4  s1;
        s1.input();
        s1.display();
        return 0;

    }

};