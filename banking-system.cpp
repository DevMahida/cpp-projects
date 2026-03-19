#include <iostream>

using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    BankAccount()
    {
        accountNumber = 0;
        balance = 0;
        accountHolderName = "";
    }

    BankAccount(int number, double balance, string name)
    {
        this->accountNumber = number;
        this->accountHolderName = name;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        this->balance = this->balance + amount;
        cout << "Balanced Deposited...\n"
             << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            this->balance = this->balance - amount;
            cout << "Balance Withdrawn...\n"
                 << endl;
        }
        else
        {
            cout << "Insufficient Balance...\n"
                 << endl;
        }
    }

    double getBalance()
    {
        return this->balance;
    }

    int accNum()
    {
        return this->accountNumber;
    }

    virtual void displayAccountInfo()
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Account Number is : " << this->accountNumber << endl;
        cout << "Account Holder Name is : " << this->accountHolderName << endl;
        cout << "----------------------------------------\n"
             << endl;
    }

    virtual void calculateInterest()
    {
        cout << "Interest not applicable for this account type." << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int number, double balance, string name, double interest) : BankAccount(number, balance, name)
    {
        this->interestRate = interest;
    }

    void displayAccountInfo()
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Account Number is : " << this->accountNumber << endl;
        cout << "Account Holder Name is : " << this->accountHolderName << endl;
        cout << "Interest Rate is : " << this->interestRate << "%." << endl;
        cout << "----------------------------------------\n"
             << endl;
    }

    void calculateInterest()
    {
        cout << "Interest Rate is : " << this->interestRate << endl;
        cout << "Interest for 1 year on Current Balance is : " << (getBalance() * interestRate * 1) / 100 << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    int overdraftLimit;

public:
    CheckingAccount(int number, double balance, string name, int overdraft) : BankAccount(number, balance, name)
    {
        this->overdraftLimit = overdraft;
    }

    void displayAccountInfo() override
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Account Number is : " << this->accountNumber << endl;
        cout << "Account Holder Name is : " << this->accountHolderName << endl;
        cout << "Overdraft Amount is : " << this->overdraftLimit << endl;
        cout << "----------------------------------------\n"
             << endl;
    }

    void withdraw(double amount) override
    {
        checkOverdraft(amount);
    }

    void checkOverdraft(double amount)
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrawn (Overdraft allowed)...\n"
                 << endl;
        }
        else
        {
            cout << "Exceeds overdraft limit!" << endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int terms;

public:
    FixedDepositAccount(int number, double balance, string name, int terms) : BankAccount(number, balance, name)
    {
        this->terms = terms;
    }

    void displayAccountInfo()
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Account Number is : " << this->accountNumber << endl;
        cout << "Account Holder Name is : " << this->accountHolderName << endl;
        cout << "Term : " << this->terms << " Months" << endl;
        cout << "----------------------------------------\n"
             << endl;
    }

    void calculateInterest()
    {
        cout << "Fixed Deposite Interest at 7.5% rate is :  " << (getBalance() * 7.5 * terms) / (100 * 12) << endl;
    }
};

int main()
{
    BankAccount *accounts[100];
    int count = 0;
    int choice;

menu:

    cout << "---------------- Banking System ----------------" << endl;
    cout << "Press 1 to Create Saving Account" << endl;
    cout << "Press 2 to Create Checking Account" << endl;
    cout << "Press 3 to Create Fixed Deposit Account" << endl;
    cout << "Press 4 to Deposit Money" << endl;
    cout << "Press 5 to Withdraw Money" << endl;
    cout << "Press 6 to Get Balance" << endl;
    cout << "Press 7 to Display Account Detials" << endl;
    cout << "Press 8 to Calculate Interest" << endl;
    cout << "Press 9 exit" << endl;

    cout << "Please Enter Your Choice : ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {

    // saving account
    case 1:
    {
        int number;
        string name;
        double amount, rate;

        cout << "Enter Account Number : ";
        cin >> number;

        cout << "Enter Name : ";
        cin >> name;

        cout << "Enter Amount : ";
        cin >> amount;

        cout << "Enter Interest Rate : ";
        cin >> rate;
        cout << endl;

        accounts[count++] = new SavingsAccount(number, amount, name, rate);

        goto menu;
    }

    // Checking account
    case 2:
    {
        int number, overdraft;
        string name;
        double amount;

        cout << "Enter Account Number : ";
        cin >> number;
        cin.ignore();

        cout << "Enter Name : ";
        cin >> name;

        cout << "Enter Amount : ";
        cin >> amount;

        cout << "Enter Overdraft Limit : ";
        cin >> overdraft;
        cout << endl;

        accounts[count++] = new CheckingAccount(number, amount, name, overdraft);

        goto menu;
    }

    // fixed deposit account
    case 3:
    {
        int number, term;
        string name;
        double amount;

        cout << "Enter Account Number : ";
        cin >> number;
        cin.ignore();

        cout << "Enter Name : ";
        cin >> name;

        cout << "Enter Amount : ";
        cin >> amount;

        cout << "Enter term (in months) : ";
        cin >> term;

        cout << endl;

        accounts[count++] = new FixedDepositAccount(number, amount, name, term);

        goto menu;
    }

    // deposit
    case 4:
    {
        int num;

        cout << "Enter The Account Number : ";
        cin >> num;

        int found = -1;

        for (int i = 0; i < count; i++)
        {
            if (accounts[i]->accNum() == num)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "Account not found ..." << endl;
            goto menu;
        }

        double amount;
        cout << "Enter The Amount to Deposit : ";
        cin >> amount;
        cout << endl;

        accounts[found]->deposit(amount);
        goto menu;
    }

    // withdraw
    case 5:
    {
        int num;

        cout << "Enter The Account Number : ";
        cin >> num;

        int found = -1;

        for (int i = 0; i < count; i++)
        {
            if (accounts[i]->accNum() == num)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "Account not found ..." << endl;
            goto menu;
        }

        double amount;
        cout << "Enter The Amount to withdraw : ";
        cin >> amount;
        cout << endl;

        accounts[found]->withdraw(amount);

        goto menu;
    }

    // get balance
    case 6:
    {
        int num;

        cout << "Enter The Account Number : ";
        cin >> num;

        int found = -1;

        for (int i = 0; i < count; i++)
        {
            if (accounts[i]->accNum() == num)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "Account not found ..." << endl;
        }
        else
        {
            cout << "Current Balance : " << accounts[found]->getBalance() << endl;
        }

        goto menu;
    }

    // account info
    case 7:
    {

        if (count == 0)
        {
            cout << "No Account .." << endl;
            goto menu;
        }

        for (int i = 0; i < count; i++)
        {
            accounts[i]->displayAccountInfo();
        }

        goto menu;
    }

    // calculate interest
    case 8:
    {
        int num;

        cout << "Enter The Account Number : ";
        cin >> num;

        int found = -1;

        for (int i = 0; i < count; i++)
        {
            if (accounts[i]->accNum() == num)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "Account not found ..." << endl;
            goto menu;
        }

        accounts[found]->calculateInterest();

        goto menu;
    }

    // exiting
    case 9:
        cout << " Exiting .... " << endl;
        break;

    default:
        cout << "Invalid Choice...\n"
             << endl;
        goto menu;
    }

    return 0;
}