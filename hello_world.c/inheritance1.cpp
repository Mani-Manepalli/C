#include<iostream>
using namespace std;
class details{
    public:
    string name,n1;
    int rollno,r1;
    float marks,m1;

};
class s1:public details{
    public:
    void input(){
    cout << "Enter s1 details 'Name , rollno , marks':";
    cin >> name >> rollno >> marks;
    };

    void output(){

        cout << "\nName:" << name << "\nRollno:" << rollno << "\nMarks:" << marks;
    }

};
class s2:public details{
    public:
    void input2(){
        cout << "\nEnter s2 details 'Name , roll , marks':";
        cin >> n1 >> r1 >> m1;

    };
    void output2(){

        cout << "\nName:" << n1 << "\nRollno:" << r1<< "\nMarks:" << m1;
        
    }

};
int main(){

    s1 s1;
    s2 s2;
    s1.input();
    s2.input2();
    s1.output();
    s2.output2();
    return 0;

}