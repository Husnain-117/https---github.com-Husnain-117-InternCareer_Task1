#include <iostream>
#include <string>
using namespace std;
// ! implementation of  a menue function
#include <iostream>

using namespace std;

class Menu
{
private:
    int lr = 0; // for the login and registration

public:
    int mm = 0;       // for the menue display
    int Main_m = 0;   // for the main menue display
    int Main_mm = 10; // for the back and exit in the Main Menue
    // --------------
   
    int login_v=0;
   
    // ! ----------------------------------------------------
    void Input(int choice)
    {
        bool book;
        if (choice == 1)
        {
            // View NAFS Details
            cout << "Welcome to NAFS - the premier airline of Pakistan!" << endl;
            cout << "We have a fleet of 50 planes serving 10 airports in 5 cities across the country." << endl;
            cout << "We also offer flights to 25 countries around the world (subject to travel restrictions)." << endl;
            cout << "Thank you for choosing NAFS!" << endl;
            mm++;
            cout << endl;
            cout << "1. Back " << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your Choiice : ";
            cin >> mm;
            if (mm == 1)
            {
                mm = 0;
            }
            else if (mm == 2)
            {
                cout << "Thank you for choosing NAFS!" << endl;
            }
        }
        else if (choice == 2)
        {
            //*  login------------------------------------------------
           
        }
        else if (choice == 3)
        {
            // register
        }
        else if (choice == 4)
        {
        }
        else if (choice == 5)
        {
           
        }
        else if (choice == 6)
        {
            // must be login
        }
        else if (choice == 7)
        {
            // must be login
        }
        else if (choice == 9)
        {

            cout << " --------------  Main Menue  -------------- " << endl;
            cout << "-------------------------------------------\n";

            
            cout << "4. Contact Us\n";
            cout << "5. About Us\n";
            cout << "6. Exit\n";

            cout << "Enter your choice: ";
            cin >> Main_m;

            switch (Main_m)
            {
         
           
            case 3:
                cout << "Flight Information selected.\n";
                mm = 3;
                cout << " 0. Exit" << endl;
                cout << " 1. Back" << endl;
                cout << "Enter your Choice : ";
                cin >> Main_mm;
                if (Main_mm == 0)
                {
                    exit(0);
                }
                else if (Main_mm == 1)
                    Input(9);
                break;
            case 4:
                cout << "Email : nafs@gmail.com \n";
                cout << "Ph    : 03xx-xxxxxxx \n";
                mm = 3;
                cout << " 0. Exit" << endl;
                cout << " 1. Back" << endl;
                cout << "Enter your Choice : ";
                cin >> Main_mm;
                if (Main_mm == 0)
                {
                    exit(0);
                }
                else if (Main_mm == 1)
                    Input(9);

                break;
            case 5:
                cout << "The NUCES Airline Flight System (NAFS) is an innovative and reliable air travel platform that connects people around the world. ";
                cout << "at NAFS, we strive to provide our customers with a seamless and stress-free travel experience";
                cout << "from the moment they book their flights to the time they reach their destination. \n";
                mm = 3;
                cout << " 0. Exit" << endl;
                cout << " 1. Back" << endl;
                cout << "Enter your Choice : ";
                cin >> Main_mm;
                if (Main_mm == 0)
                {
                    exit(0);
                }
                else if (Main_mm == 1)
                    Input(9);
                break;
            case 6:
                cout << "Thank you for using NAFS. Goodbye!" << endl;
                mm = 3;
                cout << " 0. Exit" << endl;
                cout << " 1. Back" << endl;
                cout << "Enter your Choice : ";
                cin >> Main_mm;
                if (Main_mm == 0)
                {
                    exit(0);
                }
                else if (Main_mm == 1)
                    Input(9);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                mm = 3;
                Main_m = 0;
                break;
            }

            cout << endl;
        }

        else if (choice == 8)
        {
            // * exit option
            cout << "Thank you for using NAFS. Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice ,  Please enter a number from 1 to 8." << endl;
        }
    }
    void showMenu()
    {
        cout << "------------------Welcome to NAFS Airline Flight System-----------------" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "1. View NAFS Details " << endl;
        cout << "2. Login " << endl;
        cout << "3. Register " << endl;
        cout << "4. Search Flight Schedule " << endl;
        cout << "5. Book a Flight " << endl;
        cout << "6. Update Account Details " << endl;
        cout << "7. Cancel a Flight " << endl;
        cout << "9. Main Menue " << endl;
        cout << "8. Exit " << endl;
        cout<< "10. View the most Visited Country\n";
        cout << "--------------------------" << endl;
    }
};

