#include <iostream>
#include <string>

#include"NAFS.h"
#include "admin.h"
#include "loginclass.h"
#include "register.h"
#include "flight_shedule.h"
#include "booking.h"


using namespace std;

int main()
{
    Airplane a1;
    Login login;
    Regiter reg;
    FlightSchedule shd;
    string name;
    int cancel;
    string key;
     int flightNumber;
    bool found = false;
    int mode;
    int isLocal, isForeign, hasVisa;
    bool m = true;
    while (m == true)
    {

        cout << "1. Join As an Admin \n2. Join As a Passenger\n0. Exit";
        cin >> mode;
        string fType, start, end;
        int depTime, date, month, year, af, economic_seats, bussiness_seats, lr;
        bool book;
        Flight flight;
        // ! for the main menue ----------------------------------
        Menu menue;

        if (mode == 2)
        {
            int choice = 0;
            if (menue.mm == 0)
            {
                menue.showMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                menue.Input(choice);
            }
            for (int i = 0; i < 10; i++)
            {
                if (choice == 9 && menue.Main_m == 0 && menue.login_v == 0)
                {

                    menue.Input(9);
                }
            }
            // ! login --------------------------------------------------

            if (choice == 2)
                for (int i = 0; i < 5; i++)
                {

                    if (login.login_v == 0)

                    {
                        login.login_user();
                    }
                }
            // !Register a new user ------------------------------------------

            if (choice == 3)

                for (int i = 0; i < 5; i++)
                {

                    if (reg.Register_v == 0)

                    {
                        reg.Register_user();
                         cout << "Is the passport local? (0/1): ";
                        cin >> isLocal;

                        cout << "Is the passport foreign? (0/1): ";
                        cin >> isForeign;

                        cout << "Does the passport have a visa? (0/1): ";
                        cin >> hasVisa;
                    }
                }

            if (choice == 4)
            {
                //  a1.display();
                // create an array of FlightSchedule instances
                const int numSchedules = 3;
                FlightSchedule schedules[numSchedules] = {
                    FlightSchedule("PIA", "International", 10, 14, 4, 250, 10, 5, 25, 5, 2022),
                    FlightSchedule(" Shaheen", "Local", 15, 19, 2, 100, 5, 22, 5, 5, 2022),
                    FlightSchedule("PIA", "International", 5, 10, 4, 250, 10, 13, 5, 5, 2023)};

                // ask the user if they want to see local or international flights
                string flightType;
                cout << "What Type of Shedule You Want to See ||  Local, INternational OR Both :  " << endl;
                cin >> flightType;
                // display all flight schedules
                if (flightType == "Both")
                {
                    cout << "All Flight Schedules:\n";
                    for (int i = 0; i < numSchedules; i++)
                    {
                        schedules[i].displaySchedule();
                        cout << endl;
                    }
                }

                // display flight schedules of the chosen type
                cout << endl
                     << flightType << " Flight Schedules:\n";
                for (int i = 0; i < numSchedules; i++)
                {
                    if (schedules[i].getFlightType() == flightType)
                    {
                        schedules[i].displaySchedule();
                        cout << endl;
                    }
                }
            }
            if (choice == 5)
            {
                

                bool stop = true;

                // Ask the user to enter flight details
                while (stop)
                {
                    Flight flights[5] = {
                        {332, "Lahore", "Dubai", "12 pm ", "5 pm", 50, 10, 5},
                        {333, "Lahore", "Karachi", "5 pm ", "10 pm", 50, 10, 5},
                        {334, "Islamabad", "Paris", "5 pm ", "12 pm", 50, 10, 5},
                        {335, "Karachi", "Lahore", "2 am ", "5 pm", 50, 10, 15},
                        {336, "Peshawar", "Canada", "8 am ", "12 pm", 50, 10, 4},
                    };
                    for (int i = 0; i < 5; i++)
                    {

                        cout << "Flight ID: " << flights[i].getFlightId() << endl;
                        cout << "Origin: " << flights[i].getAirpot() << endl;
                        cout << "Destination: " << flights[i].getDestination() << endl;
                        cout << "Departure time: " << flights[i].getDepartureTime() << endl;
                        cout << "Arrival time: " << flights[i].getArrivalTime() << endl;
                        cout << "Number of available economy seats: " <<  flights[i].getEconomySeats() << endl;
                        cout << "Number of available business seats: " <<  flights[i].getBusinessSeats() << endl;
                        cout << "Duration: " << flights[i].getDuration() << " minutes" << endl;
                        cout << "-----------------------------------------------------\n";
                    }
                    cout << "Enter flight number: ";
                   
                    cin >> flightNumber;
                    flight.setFlightId(flightNumber);

                    // cin.ignore();

                    flight.setEconomySeats(0);
                    flight.setBusinessSeats(0);

                    // Define an array of flights


                    // Search for flights that match the origin and destination cities
                    
                    for (int i = 0; i < 5; i++)
                    {
                        if (flights[i].getFlightId() == flightNumber && !flights[i].Isfull())
                        {
                            cout << "Flight found: " << flights[i].getAirpot() << " -> " << flights[i].getDestination() << std::endl;
                            found = true;
                        }
                    }

                    // If no flights were found, inform the user
                    if (!found)
                    {
                        cout << "Sorry, no flights were found matching your search." << std::endl;
                        cout << "1.Again   0.Back  2.Exit";
                        cin >> af;
                        if (af == 0)
                        {
                            // menue.showMenu();
                            stop = false;
                        }
                        else if (af == 2)
                        {
                            cout << "ThankYou For using NAFS\n";
                            exit(0);
                        }
                    }

                    // Reserve a seat
                    if (found == true)
                    {
                        int choice_class;
                        cout << "1. Business class \n2.Economy class: ";
                        cin >> choice_class;
                        int book = 0;
                        if (choice_class == 1)
                        {
                            book = 1;
                            flight.reserveSeat(book);
                        }
                        if (choice_class == 2)
                        {
                            book = 2;
                            flight.reserveSeat(book);
                        }
                        cout << " You wnat to book more seats \n";
                        cout << " 1.Book  2.Exit  3.Back";
                        cin >> af;
                        if (af == 3)
                            stop = true;
                        else if (af == 2)
                            exit(0);
                            else if(stop==1){
                                 choice_class;
                        cout << "1. Business class \n2.Economy class: ";
                        cin >> choice_class;
                        
                        if (choice_class == 1)
                        {
                            book = 1;
                            flight.reserveSeat(book);
                        }
                        if (choice_class == 2)
                        {
                            book = 2;
                            flight.reserveSeat(book);
                        }
                            }
                            
                  //  searchFlights(flights, 5);
                            
                        break;
                    }

                    // Output the flight details

                    // Output the cost of the flight
                    cout << flight << endl;
                }
            }
            else if (choice == 6)
            {

                cin.ignore();
                cout << "Enter Your New Name\n";
                getline(cin, login.stored_name);

                cout << "Enter Your New Key\n";
                cin.ignore();
                getline(cin, login.stored_key);
                cout << "Successfuly Changed\n";
                cout << "1.Back\n0.Exit";
                cin >> af;
                if (af == 1)
                {
                    menue.showMenu();
                }
                else if (af == 0)
                {
                    cout << "ThankYou for choosing NAFS\n";
                    exit(0);
                }
            }

            else if(choice==7){
                if(found==true){
                    cout<<"You Want to Cancel The Book Flight With id :"<<flightNumber<<endl;
                    cout<<"1.Yes  2.No\n";
                    cin>>cancel;
                    found=false;
                }
                if(cancel==1){
                    cout<<"Successfully Canceled\n";
                }
                else if(cancel==2){
                    menue.showMenu();
                }
            }
            else if(choice==8){

                exit(0);
            }
        }
        //}
        else if (mode == 1)
        {
            int admin_choice = 0;
            Admin admin;
            admin.display();
            cout << "Eneter Your Choice :";
            cin >> admin_choice;

            switch (admin_choice)
            {
            case 1:
                admin.aboutNAFS();
                break;
            case 2:
                if (admin_choice == 2)

                    for (int i = 0; i < 5; i++)
                    {

                        if (reg.Register_v == 0)

                        {
                            reg.Register_user();
                        }
                    }
                break;
            case 3:

                if (admin_choice == 3)
                    for (int i = 0; i < 5; i++)
                    {

                        if (login.login_v == 0)

                        {
                            login.login_user();
                        }
                    }
                break;
            case 4:
                cout << "--------------------You Can Now Add a flight-----------------\n";
                shd.add_Flight(fType, depTime, date, month, year);
                af = 1;
                while (af == 1)
                {

                    cout << "1.Do You Want to Add More Flights \n2.Back\n3.Exit\n";
                    cin >> af;
                    if (af == 1)
                        shd.add_Flight(fType, depTime, date, month, year);
                    else if (af == 2)
                    {
                        admin.display();
                        af = 0;
                    }
                    else if (af == 3)
                        exit(0);
                }
                break;
            case 5:
                cout << "---------------YOu Can Now  Add  a New Route For a Local Flight----------------\n";
                shd.add_Route(start, end);
                af = 1;
                while (af == 1)
                {

                    cout << "1.Do You Want to Change  More Flights Routes  \n2.Back\n3.Exit\n";
                    cin >> af;
                    if (af == 1)
                        shd.add_Route(start, end);
                    else if (af == 2)
                    {
                        admin.display();
                        af = 0;
                    }
                    else if (af == 3)
                        exit(0);
                }
                break;

            case 7:
                cout << " You can Now Update The Airline INquiry\n";
                break;
            case 8:
            
                cout << "------------------You can  Restrict The Number OF Passenger------------------- \n";
                shd.Restrict_Passengers(economic_seats, bussiness_seats);
                af = 1;
                while (af == 1)
                {
                    cout << "1.Do You Want to Restrict  More Setas  \n2.Back\n3.Exit\n";
                    cin >> af;
                    if (af == 1)
                        shd.Restrict_Passengers(economic_seats, bussiness_seats);
                    else if (af == 2)
                    {
                        admin.display();
                        af = 0;
                    }
                    else if (af == 3)
                        exit(0);
                }
                break;
            case 10:
                exit(0);
            default:
                break;
            }
        }
        else if (mode == 0)
        {
            cout << "Thankyou For choosing NAFS\n";
            exit(0);
        }
    }

    return 0;
}
