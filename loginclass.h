#include <iostream>
#include <string>
#include<conio.h>

using namespace std;

class Login
{
private:
    int lr = 0; // for the login and registration

public:
    int mm = 0;       // for the menue display
    int Main_m = 0;   // for the main menue display
    int Main_mm = 10; // for the back and exit in the Main Menue
    // --------------
    string name;
    string key;
    string stored_name = "husnain";
    string stored_key = "husnain@123";
    int login_v = 0;
    int faculty = 10;
    int ch;
    // login password -------
    bool is_password_valid(string password)
    {
        // Check length of  the password
        if (password.length() < 8)
        {
            cout << "Invalid password ,  The password should be at least 8 characters long and follow the note ._." << endl;
            return false;
        }

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

    bool login(string stored_name, string stored_key)
    {
        string name;
        string key;

        cout << "\n Note: \n. The maximum length of Username and Password is 35 characters.\n";
        cout << ". The password must be 8 characters long.\n. The password must contain a digit.\n";
        cout << ". The password must contain one or more special characters.\n";
        cout << "\n             --------LOGIN from here : ------\n";

        while (true)
        {
            cout << "\nEnter Username: " << endl;
            getline(cin, name);

            cout << "\nEnter Password: " << endl;
            
            ch=getch();
           while(ch!=13){
            key.push_back(ch);
            cout<<"X";
            ch=getch();
           }

            if (is_password_valid(key))
            {
                break;
            }
        }

        if (name == stored_name && key == stored_key)
        {

          
           
   
            return true;
        }
        else
        {
            if (name != stored_name)
                cout << " \nYour username is incorrect" << endl;
            else if (key != stored_key)

                cout << "\tYour  password is wrong." << endl;
            return false;
        }
    }
    // condition --------------
    void login_condition()
    {
        if (login_v == 1)
        {
            cout << "\n\nSelect an option:\n1. Login\n2. Change Credentials\n3. Exit" << endl;
            int l_choice;
            cin >> l_choice;
            cin.ignore();

            switch (l_choice)
            {
            case 1:
                login(stored_name, stored_key);

                break;
            case 2:
                change_credentials(stored_name, stored_key);
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
    void change_credentials(string &stored_name, string &stored_key)
    {
        cout << "\n\nNote:\n\t==>The maximum length of Username and Password is 35 characters.\n";
        cout << "\t==>The password must be 8 characters long.\n\t==>The password must contain a digit.\n";
        cout << "\t==>The password must contain one or more special characters.\n";
        cout << "\n\t\t**SIGN-UP*\n";

        cout << "\nEnter new Username: " << endl;
        getline(cin, name);

        while (true)
        {
            cout << "\nEnter new Password: " << endl;
            getline(cin, key);

            if (is_password_valid(key))
            {
                break;
            }
        }

        stored_name = name;
        stored_key = key;
        cout << "Credentials updated successfully." << endl;
        cout << " 0. Back " << endl
             << " 2. Exit " << endl;
        cin >> login_v;
        if (login_v == 2)
        {
            exit(0);
        }
    }
    void login_user()
    {
        //*  login------------------------------------------------
        login_v = 1;

        login_condition();
        //  is_password_valid(key);
        // login(stored_name, stored_key);
        // change_credentials(stored_name , stored_key);
    }
};

