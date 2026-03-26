#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void area()
    {
        cout << "Area is pi * r * r." << endl;
    }
    void draw()
    {
        cout << "Circle is drawn." << endl;
    }
};

class Rectangle : public Shape
{
    void area()
    {
        cout << "Area is L * B." << endl;
    }
    void draw()
    {
        cout << "Rectangle is drawn." << endl;
    }
};

int main()
{

    Shape* shapes[3];

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->area();
        shapes[i]->draw();
    }
    

    return 0;
}