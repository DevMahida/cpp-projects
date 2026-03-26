#include<iostream>

using namespace std;

class Person{
    private:
    string name,address;
    int age;

    public:

    Person(){
        this->name = "";
        this->age = 0;
        this->address = "";
    }

    Person(string name,int age,string address){
        this->name = name;
        this->age = age;
        this->address = address;
    }

    string getData(){
        cout << "\n--------------------------------" << endl;
        cout << "Name : " << this->name << endl;
        cout << "Age : " << this->age << endl;
        cout << "Address : " << this->address<< endl;
        cout << "--------------------------------" << endl;
    }
};

int main(){

    Person p1("Dev",18,"Gujarat");
    Person p2("raj",18,"Maharastra");
    Person p3("Dev",18,"Rajeshthan");

    p1.getData();
    p2.getData();
    p3.getData();

    return 0;
}