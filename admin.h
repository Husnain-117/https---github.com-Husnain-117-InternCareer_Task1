#include <iostream>
#include <string>
using namespace std;

using namespace std;

class Admin
{
public:
    int choice = 100;
    void display()
    {
        int choice;

        cout << "Welcome to NUCES Airline Flight System (NAFS)" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. About NAFS" << endl;
        cout << "2. Register as a new user" << endl;
        cout << "3. Login to NAFS" << endl;
        cout << "4. Add a Flight" << endl;
        cout << "5. Add New Route For a Local Flight" << endl;
       
        cout << "7. Update THe Airline Inquiry " << endl;
        cout << "8. Restrict The Number OF Passenger " << endl;
        cout << "10. Exit" << endl;
        
    }
    void aboutNAFS()
    {
        cout << "NUCES Airline Flight System (NAFS) is a newly established airline with operations in five major cities of Pakistan." << endl;
        cout << "NAFS has a network of flights in 25 countries around the globe, and offers both local and international flights." << endl;
        cout << endl;

       
        cout << "0.Back\n1.Exit" << endl;
        cin >> choice;
        while (true)
        {
            if (choice == 0)
                return;
            else if (choice == 1)
                exit(0);
        }
    }
    
};


