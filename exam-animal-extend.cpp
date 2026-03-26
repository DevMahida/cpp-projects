#include <iostream>

using namespace std;

class Animal
{

private:
    string name, sound;

public:
    virtual void Sound() = 0;
    virtual void displayDetails() = 0;

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

    void Sound() override
    {
        cout << "Dog sound : " << getSound() << endl;
    }

    void displayDetails() override
    {
        cout << "\n-------------------" << endl;
        cout << "Name : " << getName() << endl;
        cout << "Sound : " << getSound() << endl;
        cout << "-------------------" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        setSound("Meow");
    }

    void Sound() override
    {
        cout << "Cat sound : " << getSound() << endl;
    }

    void displayDetails() override
    {
        cout << "\n-------------------" << endl;
        cout << "Name : " << getName() << endl;
        cout << "Sound : " << getSound() << endl;
        cout << "-------------------" << endl;
    }
};

int main()
{
    int size;
    string name, sound;

    cout << "Enter input size : ";
    cin >> size;
    cin.ignore();

    Animal *animals[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter Name : ";
        getline(cin, name);

        cout << "Enter sound : ";
        getline(cin, sound);

        animals[i]->setName(name);
        animals[i]->setSound(sound);
    }

    for (int i = 0; i < size; i++)
    {
        animals[i]->displayDetails();
    }

    return 0;
}