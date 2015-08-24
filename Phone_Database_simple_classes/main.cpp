#include <iostream>
#include <cstdlib>
#include <string>
#include "Phone.h"
#include "Database.h"

using namespace std;


int main()
{
    int max=500;
    cout <<"What is the maximum number of phones that you would like to save in the database" <<endl;
    cin >> max;
    Database smartphones(max);
    int user_input;

    while(user_input!=6)
    {
        cout << "Welcome to the smart phone database. Please select one of the options below to proceed." <<endl;
        cout << "Enter 1 to add a new item...\n";
        cout << "Enter 2 to update an item...\n";
        cout << "Enter 3 to print the database...\n";
        cout << "Enter 4 to display a smart phone's information in the database\n";
        cout << "Enter 5 to query the data \n";
        cout << "Enter 6 to quit this program...\n";
        

        cin >> user_input;
        cin.ignore();

        switch(user_input)
        {
            case 1: cout << "you have chosen 1" <<endl;
            smartphones.add_phone();
            break;
            case 2: cout << "You have chosen 2" <<endl;
            smartphones.update();
            break;
            case 3: cout << "You have chosen 3" <<endl;
            smartphones.print_database();
            break;
            case 4: cout << "You have chosen 4" <<endl;
            smartphones.display();
            break;
            case 5: cout << "You have chosen 5" <<endl;
            smartphones.query();
            break;
            case 6: cout << "You have chosen 6" <<endl;
            break;
            default: cout <<"You must choose a number from 1 through 6. Please try again..." <<endl;
            break;

        }
        cout << endl <<endl;

    }

    return 0;
    }
