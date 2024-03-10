#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
static int i = 0;

class Regiter
{
private:
    int lr = 0; // for the login and registration

public:
    string Account_No;
    int An = 0;
    int mm = 0;       // for the menue display
    int Main_m = 0;   // for the main menue display
    int Main_mm = 10; // for the back and exit in the Main Menue
    // --------------
    string name;
    string key;
   // int check=0;
    string CNIC;
    int mode = 0;
    string stored_name = "husnain";
    string stored_key = "husnain@123";
    string stored_CNIC = "365020000000";
    int Register_v = 0;
    int ch;
    // Register password -------
    bool is_password_valid(string password)
    {
        // Check length of  the password
        if (password.length() < 8)
        {
            cout << "Invalid password ,  The password should be at least 8 characters long and follow the note ._." << endl;
            return false;
        }
        //    if(CNIC.length()!=13){
        //     cout<<" INvalid CNIC type, TRy Again"<<endl;
        //     return false;

        //    }

        // Check if password contains special characters
        bool special_char = false;
        for (char ch : password)
        {
            if ((ch >= 32 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126))
            {
                special_char = true;
                break;
            }
        }

        if (special_char == false)
        {
            cout << "Invalid password. The password should contain at least one special character." << endl;
            return false;
        }

        // Check if password contains digits
        bool digit = false;
        for (char ch : password)
        {
            if (ch >= '0' && ch <= '9')
            {
                digit = true;
                break;
            }
        }

        if (digit == false)
        {
            cout << "Invalid password. The password should contain at least one digit." << endl;
            return false;
        }
        else
            return true;
    }
    bool Register(string stored_name, string stored_key, string stored_CNIC, int mode)
    {
        string name;
        string key;
        string CNIC;

        cout << "\n Note: \n. The maximum length of Username and Password is 35 characters.\n";
        cout << ". The password must be 8 characters long.\n. The password must contain a digit.\n";
        cout << ". The password must contain one or more special characters.\n";
        cout << "\n             --------Register from here : ------\n";

        while (true)
        {
            // cout << "1.As an Admin \n2.As a PAssenger \n";
            // cout << "Enter Your Choice :";
            // cin >> mode;

            cout << "\nEnter your  Username: " << endl;
            cin.ignore();
            getline(cin, name);

            cout << "\nEnter  your Password: " << endl;
            ch = getch();
            while (ch != 13)
            {
                key.push_back(ch);
                cout << "X";
                ch = getch();
            }

            cout << "\nEnter  your CNIC 13-Digit: " << endl;
            getline(cin, CNIC);

            if (is_password_valid(key))
            {
                break;
            }
        }

        // Append the user's information to the file

        ofstream outfile("users.txt", ios::app);
        if (!outfile.is_open())
        {
            cerr << "Failed to open file" << endl;
            return false;
        }

        outfile << i + 1 << ") "
                << "Name: " << name << " , Password: " << key << " , CNIC: " << CNIC <<" , Account No : "<<Account_No << endl;
        i++;

        // stored_name = name;
        stored_key = key;
        stored_CNIC = CNIC;
        if (stored_name == name)
        {
            cout << " Name is alredy registerd " << endl;
            cout << "\n\nSelect an option:\n1. Register\n3. Exit\n0. Back" << endl;
            int l_choice;
            cin >> l_choice;
            cin.ignore();
            switch (l_choice)
            {
            case 0:
                return false;

            case 1:
                Register(stored_name, stored_key, stored_CNIC, mode);

                break;

            case 3:
                cout << "Thank you for choosing NAFS!" << endl;
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
                Main_m = 0;
            }
        }
        else
        {
            cout << "Successfully Registered" << endl;
           // check=1;
            cout << "0. Back \n"
                 << "2. Exit \n";

            cout << "3.  To add Details for Payment and Transactions \n ";

            cin >> Register_v;
            if (Register_v == 2)
            {
                exit(0);
            }
            if (Register_v == 3)
            {
                verifyFinancialDEtails();
            }

            // Close the file
            outfile.close();

            return true;
        }
    }

    // condition --------------
    void Register_condition()
    {
        if (Register_v == 0)
        {
            cout << "\n\nSelect an option:\n1. Register\n3. Exit " << endl;
            int l_choice;
            cin >> l_choice;
            cin.ignore();

            switch (l_choice)
            {
            case 1:
                Register(stored_name, stored_key, stored_CNIC, mode);

                break;
           
            case 3:
                cout << "Thank you for choosing NAFS!" << endl;
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
                Main_m = 0;
            }
        }
    }

    void Register_user()
    {
        //*  login------------------------------------------------
       // 

        Register_condition();
        Register_v = 1;

      
    }
    void verifyFinancialDEtails()
    {
        for (int i = 0; i < 5; i++)
        {
            if (An == 0)
            {
                cout << "Note: Account Number Must Be 14 chracters \n";

                cout << " Enter Your Bank Account Number \n";
                cin >> Account_No;
                if (Account_No.length() != 14)
                {
                    cout << "Account Number is InValid \n";
                    An = 0;
                }
                else
                {
                    cout << "Successfully Added \n";
                    An++;
                }
            }
        }
    }
};

