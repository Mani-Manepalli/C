#include <iostream>
using namespace std;
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};
class Dog : public Animal {
public:
    void sound() override { 
        cout << "Dog barks" << endl;
    }
};
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animalPtr; 
    Dog dog;
    Cat cat;
    animalPtr = &dog;
    animalPtr->sound(); 
    animalPtr = &cat;
    animalPtr->sound(); 
    return 0;
}