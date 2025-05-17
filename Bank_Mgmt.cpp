#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::numeric_limits;

void start(string &name)
{
    int pin;
    int size;
    bool e = false;

    while(!e)
    {
        cout << "Welcome to TD Bank. Please type your name and PIN" << "\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "PIN: ";
        cin >> pin;
        system("cls");

        if((std::to_string(pin).size()) != 4)
        {
            cout << "PIN should be 4 digits!" << "\n";
            continue;
        }
        break;
    }


}

//manip: output << direction << width << text_to_adjust
void menu(string name, int c_num, int c_bal)
{

    void deposit(int &c_bal);
    void withdraw(int &c_bal);
    void transfer(int &c_bal);
    int choice;

    cout << "Welcome " << name << "!\n\n\n";
    cout <<"Chequing*" << c_num;
    cout << std::right << std::setw(70) << "Select what option to proceed with by typing it's number. " << "\n";
    cout << "Current balance: ";
    cout << std::right << std::setw(18) << "1. Deposit" << "\n";
    cout << "$" << c_bal;
    cout << std::right << std::setw(25) << "2. Withdraw" << "\n";
    cout << std::right << std::setw(30) << "3. Transfer Money" << "\n";
    cout <<std::right << std::setw(10) << "4. Exit" << "\n";
    cout << std::right << std::setw(30) << "What is your choice? ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            system("cls");
            deposit(c_bal);
            break;

        case 2:
            system("cls");
            withdraw(c_bal);
            break;

        case 3:
            system("cls");
            transfer(c_bal);
            break;

        case 4:
            cout << "Thank you for banking with us!";
            exit(1);
    }

}

void deposit(int &c_bal)
{
    int choice; //money to deposit
    int total;

    cout << "Balance: $" << c_bal << "\n\n";
    cout << "How much money would you like to deposit?";
    cin >> choice;
    total = c_bal + choice;

    cout << "Your new total is $" << total << "!";

}

void withdraw(int &c_bal)
{
    int choice;
    int total;

    cout << "Balance: $" << c_bal << "\n";
    while(true)
    {
        cout << "How much money would you like to withdraw? ";
        cin >> choice;

        total = c_bal - choice;
        if(total < 0)
        {
            cout << "Insufficient funds. Please use a smaller amount.";
            continue;
        }
        else
        {
            cout << "\n" << choice << " successfully withdrawn!" << "\n";
            cout << "Remaining Balance: " << total;
            break;
        }
    }

}

void transfer(int &c_bal)
{
    std::string recip;
    std::string acc_num;
    std::string b_name;
    std::string r_num;
    std::string addr;
    int tmoney; //money to be transferred
    int total;

    cout << "Balance: $" << c_bal << "\n\n";
    cout << "Recipient's info: " << "\n";
    cout << "***********************" << "\n\n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Full Name: ";
    getline(cin, recip);
    cout << "Bank Name: ";
    getline(cin, b_name);
    while(true)
    {
        cout << "Account Number: ";
        getline(cin, acc_num);
        if(acc_num.length() != 7 && acc_num.length() != 12)
        {
            cout << "Invalid Account Number - Must be 7 or 12 digits. Please try again." << "\n";
            continue;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout << "Routing Number: ";
        getline(cin, r_num);
        if(r_num.length() != 9)
        {
            cout << "Invalid Routing Number - Must be 9 digits. Please try again." << "\n\n";
            continue;
        }
        else
        {
            break;
        }
    }

    cout << "Address: ";
    getline(cin, addr);
    cout << "\n";

    while(true)
    {
        cout << "Amount to be transferred: ";
        cin >> tmoney;

        if(tmoney > c_bal)
        {
            cout << "Insufficient Funds.";
            continue;
        }
        else
        {
            cout << "Processing..." << "\n";
            total = c_bal - tmoney;
            cout << "Transaction to " << recip << " successful!" << "\n";
            cout << "You now have $" << total << "\n\n";
            cout << "Thank you for banking with us!";
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}
int main()
{
    string name;
    srand(time(0));
    int c_num = rand()%10000 + 1000; //account number
    int c_bal = rand()%100000 + 1000; //balance

    start(name);
    menu(name, c_num, c_bal);

}
