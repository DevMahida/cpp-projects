#include <iostream>

using namespace std;

class Animal
{

private:
    string name, sound;

public:
    virtual void Sound() = 0;

    void setName(string name) { this->name = name; }
    void setSound(string sound) { this->sound = sound; }

    string getName() { return this->name; }
    string getSound() { return this->sound; }
};

class Dog : public Animal
{
public:
    Dog()
    {
        setSound("Bark");
    }

    void Sound()
    {
        cout << "Dog sound : " << getSound() << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        setSound("Meow");
    }

    void Sound()
    {
        cout << "Cat sound : " << getSound() << endl;
    }
};

int main()
{

    Dog d1;
    Cat c1;

    d1.Sound();
    c1.Sound();

    return 0;
}