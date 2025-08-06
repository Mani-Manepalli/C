#include <iostream>
using namespace std;
class Base {
public:
    int pubVar = 10;
protected:
    int proVar = 20;
private:
    int priVar = 30; 

public:
    int getPrivateVar() {
        return priVar;
    }
    int getprotectedvar(){
        return proVar;
    }
};
class Derived : public Base {
public:
    void display() {
        cout << "Public Variable: " << pubVar << endl; 
        cout << "Protected Variable: " << getprotectedvar()<< endl;
        cout << "Private Variable using getter: " << getPrivateVar() << endl;
    }
};

int main() {
    Derived obj;
    obj.display();
    cout << "Accessing Public Variable from Main: " << obj.pubVar << endl;

    return 0;
}