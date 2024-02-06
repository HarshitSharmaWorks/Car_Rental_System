#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iomanip>
#include <conio.h>

using namespace std;

class Customer
{
public:
    string customername;
    string carmodel;
    string carnumber;
};

class Rent : public Customer
{
public:
    int days = 0;
    int rentalfee = 0;

    void inputData()
    {
        login();
        
        cout << "\nPlease Enter Customer Name: ";
        cin >> customername;
        cout << endl;

        do
        {
            cout << "Available Car Options: " << endl;
            cout << "(A) Tesla (Model: 2020)" << endl;
            cout << "(B) Fortuner (Model: 2019)" << endl;
            cout << "(C) Swift (Model: 2019)" << endl;
            cout << "Enter Your Choice (Car Name): ";
            cin >> carmodel;
            cout << endl;            
        } while (carmodel != "Tesla" && carmodel != "Fortuner" && carmodel != "Swift");

        cout << "" << endl;
        cout << "\nPlease Fill the Given Details: " << endl;
        cout << "Enter Car Number of your choice : ";
        cin >> carnumber;
        cout << "Enter Number of days for Car rent : ";
        cin >> days;
        cout << endl;
    }

    void calculate()
    {
        cout << "Calculating rent. Please wait......." << endl;

        if (carmodel == "Tesla")
            rentalfee = days * 100;
        else if (carmodel == "Fortuner")
            rentalfee = days * 50;
        else if (carmodel == "Swift")
            rentalfee = days * 30;
    }

    void showRent()
    {
        cout << "\nCustomer Invoice" << endl;
        cout << "----------------------------------------------------------" << endl;
        srand(time(0));
        int randomNum = rand() % 90000 + 10000;
        cout << "Invoice No. : INVOICE" << randomNum << endl;
        cout << "Customer Name:" << customername << endl;
        cout << "Car Model :" << carmodel << endl;
        cout << "Car Number :" << carnumber << endl;
        cout << "Number of days :" << days << endl;
        cout << "Your Rental Amount is :" << rentalfee << endl;
        cout << "Total Rental Amount is :" << rentalfee << endl;
        int advance = rentalfee * 0.5;
        cout << "Total Advanced Payment Need to pay :" << advance << endl;
        cout << "\nTotal balanced Payment:" << rentalfee - advance << endl;
        cout << "" << endl;
        cout << "----------------------------------------------------------" << endl;

        ifstream inf("Thanks.txt");
        char str[3000];
        while (inf)
        {
            inf.getline(str, 3000);
            if (inf)
                cout << str << endl;
        }
        inf.close();
    }

    void login()
    {
        string pass = "";
        char ch;
        cout << "CAR RENTAL SYSTEM" << endl;
        cout << "-----------------\n"
             << endl;
        cout << "For login Enter Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        if (pass == "HS")
        {
            cout << "\n";
            cout << "Successfully logged in" << endl;
        }
        else
        {
            cout << "\n";
            cout << "Wrong Password...Please Try Again\n";
            system("CLS");
            login();
        }
    }
};

class Welcome
{
public:
    void welcomeMessage()
    {
        ifstream inFile("Welcome.txt");
        if (!inFile)
        {
            cout << "Cannot open input file." << endl;
        }
        char str[1000];
        while (inFile)
        {
            inFile.getline(str, 1000);
            if (inFile)
                cout << str << endl;
        }
        inFile.close();
        cout << "\nStarting the program please wait....." << endl;
    }
};

int main()
{
    Welcome welcome;
    welcome.welcomeMessage();

    Rent rent;
    rent.inputData();
    rent.calculate();
    rent.showRent();

    return 0;
}
