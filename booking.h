#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Flight
{
private:
    int flight_id_;
    string airpot;
    string destination_;
    string departure_time_;
    string arrival_time_;
    int economy_seats_;
    int business_seats_;
    int duration_;
    string fType;
    bool *economy_seat_map_;
    bool *business_seat_map_;
    int choice_seat;

public:
    Flight()
    {
        flight_id_ = 0;
        airpot = "";
        destination_ = "";
        departure_time_ = "";
        arrival_time_ = "";
        economy_seat_map_ = 0;
        business_seat_map_ = 0;
        economy_seats_ = 0;
        business_seats_ = 0;
    }
    Flight(int flight_id, string airpot, string destination, string departure_time,
           string arrival_time, int economy_seats_, int business_seats_, int duration)
    {
        this->flight_id_ = flight_id;
        this->airpot = airpot;
        this->destination_ = destination;
        this->departure_time_ = departure_time;
        this->arrival_time_ = arrival_time;
        this->economy_seats_ = economy_seats_;
        this->business_seats_ = business_seats_;
        duration_ = duration;
    }
    int getFlightId()
    {
        return flight_id_;
    }
    void setFlightId(int flight_id)
    {
        this->flight_id_ = flight_id;
    }
    string getAirpot()
    {
        return airpot;
    }
    void setOrigin(string airpot)
    {
        this->airpot = airpot;
    }
    string getDestination()
    {
        return destination_;
    }
    void setDestination(string destination)
    {
        destination_ = destination;
    }
    string getDepartureTime()
    {
        return departure_time_;
    }
    void setDepartureTime(string departure_time)
    {
        departure_time_ = departure_time;
    }
    string getArrivalTime()
    {
        return arrival_time_;
    }
    void setArrivalTime(string arrival_time)
    {
        arrival_time_ = arrival_time;
    }
    int getEconomySeats() const
    {
        return economy_seats_;
    }
    void setEconomySeats(int economy_seats)
    {
        economy_seats_ = economy_seats;
    }
    int getBusinessSeats() const
    {
        return business_seats_;
    }
    void setBusinessSeats(int business_seats)
    {
        business_seats_ = business_seats;
    }
    int getDuration() const
    {
        return duration_;
    }
    void setDuration(int duration)
    {
        duration_ = duration;
    }

    // Overloaded stream operator to output the cost of the flight
    friend ostream &operator<<(ostream &os, Flight &flight)
    {
        int price_per_hour;
        if (flight.fType == "Local")
        {
            price_per_hour = 10000;
        }
        else
        {
            price_per_hour = 20000;
        }

        int duration_hours = flight.getDuration() / 60; // duration in minutes
        int base_price = price_per_hour * duration_hours;

        double tax_rate;
        if (flight.fType == "Local")
        {
            tax_rate = 0.2;
        }
        else
        {
            tax_rate = 0.5;
        }

        double total_price = base_price * (1 + tax_rate);
        os << "Flight cost: " << total_price << " PKR";
        return os;
    }

    bool searchFlight(int flightNumber)
    {
        ifstream file("flights.txt" );
        string line;

        if (file.is_open())
        {
            while (getline(file, line))
            {
                // size_t pos = line.find(",");
                // int number = line.substr(0, pos);

                if (flight_id_ == flightNumber)
                {
                    cout << "Flight found!" << endl;
                    cout << "Flight Details: " << line << endl;
                    
                    file.close();
                    return true;
                  
                }
            }

            cout << "Flight not found." << endl;
           
            file.close();
             return false;
        }
        else
        {
            cout << "Error opening file." << endl;
        }
    }
    bool Isfull()
    {
        if (economy_seats_ >= 50)
        {
            return false;
        }
        else if (business_seats_ >= 10)
        {
            return false;
        }
        else
            return true;
    }
    void reserveSeat(int book)
    {
        if (book == 1)
        {
            if (business_seats_ <= 10)
            {
                for (int i = 0; i < 10 - business_seats_; i++)
                {
                    cout << " You want to book a seat in bussiness class \n 1.Yes \n 2.No";
                    cin >> choice_seat;
                    if (choice_seat == 1)
                    {
                        cout << "Successfully Booked\n";
                        writeBookingRecord();
                        business_seats_++;
                    }

                    else if (choice_seat == 2)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Business class seats are full." << endl;
            }
        }

        if (book == 2)
        {
            if (economy_seats_ <= 50)
            {
                for (int i = 0; i < 50; i++)
                {
                    cout << " You want to book a seat in Economy  class \n 1.Yes \n 2.No";
                    cin >> choice_seat;
                    if (choice_seat == 1)
                    {

                        cout << "Successfully Booked\n";
                        writeBookingRecord();

                        economy_seats_++;
                    }
                    else if (choice_seat == 2)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Economy class seats are full." << endl;
            }
        }
    }
    // Function to write seat booking record to a file
    void writeBookingRecord()
    {
        ofstream file("booking.txt", ios::app);
        if (file.is_open())
        {
            file << "Flight ID: " << flight_id_ << endl;
            file << "Booking Type: " << (choice_seat == 1 ? "Business" : "Economy") << endl;

            file << "-----------------------------" << endl;
            file.close();
            cout << "Booking record saved successfully." << endl;
        }
        else
        {
            cout << "Failed to open the file." << endl;
        }
    }
};
