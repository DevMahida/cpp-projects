#include <iostream>

using namespace std;

class Book
{
private:
    string title, author, publishedYear;

public:
    void setData(string title, string author, string year)
    {
        this->title = title;
        this->author = author;
        this->publishedYear = year;
    }

    string getTitle() { return this->title; }
    string getAuthor() { return this->author; }
    string getPublishedYear() { return this->publishedYear; }
};

int main()
{
    Book brr[3];

    brr[0].setData("Liebe", "Liebe", "12-11-2005");
    brr[1].setData("Asta", "Asta", "04-11-2005");
    brr[2].setData("Yuno", "Yuno", "04-11-2005");

    for (int i = 0; i < 3; i++)
    {
        cout << "\n--------------------------------" << endl;
        cout << "Title : " << brr[i].getTitle() << endl;
        cout << "Author : " << brr[i].getAuthor() << endl;
        cout << "Published Year : " << brr[i].getPublishedYear() << endl;
        cout << "--------------------------------\n" << endl;
    }
    
    return 0;
}