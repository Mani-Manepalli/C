//write a c++ program to illustrate the pure virtual function  in polymorphism

#include <iostream>
using namespace std;
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle";
    }
};
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "\nDrawing a Rectangle";
    }
};
class Triangle : public Shape {
public:
    void draw() override {
        cout << "\nDrawing a Triangle";
    }
};

int main() {
    Shape* shape;

    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    shape = &circle;
    shape->draw();

    shape = &rectangle;
    shape->draw();

    
    shape = &triangle;
    shape->draw();

    return 0;
}