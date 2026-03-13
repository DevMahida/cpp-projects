#include <iostream>
#include <cstring>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

public:
    static int trainCount;

    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");

        trainCount++;
    }

    Train(int num, const char name[], const char src[], const char des[], const char time[])
    {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, des);
        strcpy(trainTime, time);

        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    int returnTrainNumber()
    {
        return trainNumber;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number : ";
        cin >> this->trainNumber;
        cin.ignore();

        cout << "Enter Train Name : ";
        cin.getline(this->trainName, 50);

        cout << "Enter Train Source : ";
        cin.getline(this->source, 50);

        cout << "Enter Train Destination : ";
        cin.getline(this->destination, 50);

        cout << "Enter Train Time : ";
        cin.getline(this->trainTime, 10);
        cout << endl;
    }

    void displayTrainDetails()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Train Number : " << this->trainNumber << endl;
        cout << "Train Name : " << this->trainName << endl;
        cout << "Train Source : " << this->source << endl;
        cout << "Train Destination : " << this->destination << endl;
        cout << "Train Time : " << this->trainTime << endl;
        cout << "-----------------------------------------" << endl;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains >= 100)
        {
            cout << "\nTrain Limit Is Full.\n"
                 << endl;
        }
        else
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo Train Records.\n"
                 << endl;
        }
        else
        {
            cout << "\nTrain Records : \n"
                 << endl;
            for (int i = 0; i < totalTrains; i++)
            {
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;
        for (int i = 0; i < totalTrains; i++)
        {
            if (number == trains[i].returnTrainNumber())
            {
                cout << "\nTrain Found : " << endl;
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\nTrain Not Found.\n"
                 << endl;
        }
    }
};

int main()
{
    RailwaySystem system;
    int choice;
    int num;

menu:

    cout << "\nRailWay System : " << endl;
    cout << "1 : Add New Train Record." << endl;
    cout << "2 : Display All Train Records." << endl;
    cout << "3 : Search Train By Number." << endl;
    cout << "4 : Exit." << endl;
    cout << "\nPlease Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system.addTrain();
        goto menu;
    case 2:
        system.displayAllTrains();
        goto menu;
    case 3:
    {
        cout << "Enter The Train Number : ";
        cin >> num;
        system.searchTrainByNumber(num);
        goto menu;
    }
    case 4:
        cout << "Exiting the system. Goodbye!" << endl;
        break;

    default:
        cout << "Invalid Choice." << endl;
        break;
    }

    return 0;
}