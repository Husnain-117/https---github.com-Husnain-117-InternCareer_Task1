#include <iostream>
#include <string>

using namespace std;

class FlightSchedule
{
private:
    string planeType;           // type of plane
    string flightType;          // local or international
    int departureTime;          // departure time
    int arrivalTime;            // arrival time
    int journeyTime;            // duration of flight journey in hours
    int availableSeats_economy; // number of available seats economy class
    int availableSeats_bussiness;
    int maxAirplanes; // maximum number of airplanes that can be at the airport
    int date;
    int month;
    int year;
    string start, end;

public:
    FlightSchedule()
    {
        availableSeats_economy = 50;
        availableSeats_bussiness = 10;
        maxAirplanes = 5;
    }
    // constructor
    FlightSchedule(string pType, string fType, int depTime, int arrTime, int jTime, int economy, int bussines, int maxPlanes, int date, int month, int year)
    {
        planeType = pType;
        flightType = fType;
        departureTime = depTime;
        arrivalTime = arrTime;
        journeyTime = jTime;
        availableSeats_economy = economy;
        availableSeats_bussiness = bussines;
        maxAirplanes = maxPlanes;
        this->date = date;
        this->year = year;
        this->month = month;
    }
    void add_Flight(string fType, int depTime, int date, int month, int year)
    {
        cout << " Enter THe flight TYpe \n . Local\n . International\n";
        cin >> fType;
        flightType = fType;
        cout << "Enetr The Departure Time Of a Flight :";
        cin >> depTime;
        departureTime = depTime;
        cout << "Enetr The Date in Days Of a Flight :";
        cin >> date;
        this->date = date;
        cout << "Enetr The Date in months Of a Flight :";
        cin >> month;
        this->month = month;
        cout << "Enetr The Date in Years Of a Flight :";
        cin >> year;
        this->year = year;
    }
    void add_Route(string start, string end)
    {
        cout << " Enetr The Plane Name  First\n";
        cin >> planeType;
        cout << endl;
        cout << " Enter The Satrting Point of a Flight\n";
        cin >> start;
        this->start = start;
        cout << " Enter the Ending Point of a Flight\n";
        cin >> end;
        this->end = end;
    }
    void Restrict_Passengers(int e_seats, int b_seats)
    {
        int restrict;
        int s;
        cout << "THe  Are " <<availableSeats_economy<<" Economy Seats and  "<< availableSeats_bussiness<<" Bussiness Seats \n";
        cout << " You Want to Restrict seats from economy Seats\n 1.yes    2.No";
        cin >> restrict;
        if (restrict == 1)
        {
            cout << " How many seats ? \n";
            cin >> s;
            if (s < 50)
                availableSeats_economy -= s;
                 cout << " You Want to Restrict seats from Bussiness Seats\n 1.yes    2.No";
                  cin >> restrict;
             if (restrict == 1)
        {
            cout << " How many seats ? \n";
            cin >> s;
            if (s < 10)
                availableSeats_bussiness -= s;
                

            else
            {
                cout << " Incorrect Amount\n";
                Restrict_Passengers(e_seats, b_seats);
            }
        }

            else if(s>10)
            {
                cout << " Incorrect Amount\n";
                Restrict_Passengers(e_seats, b_seats);
            }
        }
        else if (restrict == 2)
        {
            cout << " You Want to Restrict seats from Bussiness Seats\n 1.yes    2.No";
            cin >> restrict;
             if (restrict == 1)
        {
            cout << " How many seats ? \n";
            cin >> s;
            if (s < 10)
                availableSeats_bussiness -= s;

            else if(s>10)
            {
                cout << " Incorrect Amount\n";
                Restrict_Passengers(e_seats, b_seats);
            }
        }

        }
    }
    // getter methods
    string getPlaneType()
    {
        return planeType;
    }

    string getFlightType()
    {
        return flightType;
    }

    int getDepartureTime()
    {
        return departureTime;
    }

    int getArrivalTime()
    {
        return arrivalTime;
    }

    int getJourneyTime()
    {
        return journeyTime;
    }

    int getAvailableSeats_economy()
    {
        return availableSeats_economy;
    }
    int getAvailableSeats_bussiness()
    {
        return availableSeats_bussiness;
    }

    int getMaxAirplanes()
    {
        return maxAirplanes;
    }
    int getDate()
    {
        return date;
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }

    // setter methods
    void setPlaneType(string pType)
    {
        planeType = pType;
    }

    void setFlightType(string fType)
    {
        flightType = fType;
    }

    void setDepartureTime(int depTime)
    {
        departureTime = depTime;
    }

    void setArrivalTime(int arrTime)
    {
        arrivalTime = arrTime;
    }

    void setJourneyTime(int jTime)
    {
        journeyTime = jTime;
    }

   

    void setMaxAirplanes(int maxPlanes)
    {
        maxAirplanes = maxPlanes;
    }
    void setDate(int d)
    {
        if (d < 30)
            date = d;
        else
            cout << " invalid date" << endl;
    }
    void setMonth(int m)
    {
        if (m < 12)
            month = m;
        else
            cout << " invalid date" << endl;
    }
    void setYear(int y)
    {
        if (y < 2023)
            year = y;
        else
            cout << " invalid date" << endl;
    }

    // display flight schedule information
    void displaySchedule(string type = "all")
    {
        if (type == "all" || flightType == type)
        {
            cout << "Plane Type: " << planeType << endl;
            cout << "Flight Type: " << flightType << endl;
            cout << "Departure Time: " << departureTime << endl;
            cout << "Arrival Time: " << arrivalTime << endl;
            cout << "Journey Time: " << journeyTime << " hours" << endl;
            cout << "Available Economy Seats: " << availableSeats_economy << endl;
            cout << "Available bussiness Seats: " << availableSeats_bussiness << endl;
            cout << "Max Airplanes: " << maxAirplanes << endl;
            cout << endl;
        }
    }
};

class Airplane
{
private:
    string planeType;
    int maxSeats;
    int maxAirplanes;
    int currentAirplanes;
    int localFlights;
    int internationalFlights;
    int currentSeats_economy;
    int currentSeats_bussiness;

public:
    Airplane()
    {
        planeType = "";
        maxSeats = 60;
        maxAirplanes = 10;
        currentAirplanes = 5;
        localFlights = 10;
        internationalFlights = 5;
        currentSeats_economy = 50;
        currentSeats_bussiness = 10;
    }
    Airplane(string pType, int mSeats, int mPlanes, int lFlights, int iFlights)
    {
        planeType = pType;
        maxSeats = mSeats;
        maxAirplanes = mPlanes;
        currentAirplanes = 0;
        localFlights = lFlights;
        internationalFlights = iFlights;
        currentSeats_economy = 0;
        currentSeats_bussiness = 0;
    }

    string getPlaneType()
    {
        return planeType;
    }

    int getMaxSeats()
    {
        return maxSeats;
    }

    int getMaxAirplanes()
    {
        return maxAirplanes;
    }

    int getCurrentAirplanes()
    {
        return currentAirplanes;
    }

    int getLocalFlights()
    {
        return localFlights;
    }

    int getInternationalFlights()
    {
        return internationalFlights;
    }

    int getCurrentSeats_Economy()
    {
        return currentSeats_economy;
    }
    int getCurrentSeats_bussiness()
    {
        return currentSeats_bussiness;
    }

    void addAirplane()
    {
        if (currentAirplanes < maxAirplanes)
        {
            currentAirplanes++;
            cout << "Airplane added successfully" << endl;
        }
        else
        {
            cout << "Cannot add airplane, max limit reached" << endl;
        }
    }

    void removeAirplane()
    {
        if (currentAirplanes > 0)
        {
            currentAirplanes--;
            cout << "Airplane removed successfully" << endl;
        }
        else
        {
            cout << "Cannot remove airplane, no airplane available" << endl;
        }
    }

    void addLocalFlight()
    {
        if (localFlights < 10)
        {
            localFlights++;
            cout << "Local flight added successfully" << endl;
        }
        else
        {
            cout << "Cannot add local flight, max limit reached" << endl;
        }
    }

    void addInternationalFlight()
    {
        if (internationalFlights < 5)
        {
            internationalFlights++;
            cout << "International flight added successfully" << endl;
        }
        else
        {
            cout << "Cannot add international flight, max limit reached" << endl;
        }
    }

    void removeLocalFlight()
    {
        if (localFlights > 0)
        {
            localFlights--;
            cout << "Local flight removed successfully" << endl;
        }
        else
        {
            cout << "Cannot remove local flight, no local flight available" << endl;
        }
    }

    void removeInternationalFlight()
    {
        if (internationalFlights > 0)
        {
            internationalFlights++;
            cout << "International flight removed successfully" << endl;
        }
        else
        {
            cout << "Cannot remove international flight, no international flight available" << endl;
        }
    }

    void bookSeats(int numSeats)
    {
        string seat;
        cout << " What type of seat you want to book \n";
        cout << ". economy \n . Bussiness" << endl;
        cin >> seat;
        if (seat == "economy")
        {
            if (currentSeats_economy + numSeats <= maxSeats)
            {
                currentSeats_economy += numSeats;
                cout << "Seats booked successfully in a  economy section " << endl;
            }
            else
            {
                cout << "Cannot book seats, not enough seats available in economic section " << endl;
            }
        }
        if (seat == "bussiness")
        {
            if (currentSeats_bussiness + numSeats <= maxSeats)
            {
                currentSeats_bussiness += numSeats;
                cout << "Seats booked successfully in a  economy section " << endl;
            }
            else
            {
                cout << "Cannot book seats, not enough seats available in economic section " << endl;
            }
        }
    }

    void cancelSeats(int numSeats)
    {
        string seat;
        cout << " What type of seat you want to Cancel \n";
        cout << ". economy \n . Bussiness" << endl;
        cin >> seat;
        if (seat == "economy")
        {
            if (currentSeats_economy - numSeats >= 0)
            {
                currentSeats_economy -= numSeats;
                cout << "Seats cancelled successfully" << endl;
            }
            else
            {
                cout << "Cannot cancel seats, not enough seats booked" << endl;
            }
        }
        if (seat == "bussiness")
        {
            if (currentSeats_bussiness - numSeats >= 0)
            {
                currentSeats_bussiness -= numSeats;
                cout << "Seats cancelled successfully" << endl;
            }
            else
            {
                cout << "Cannot cancel seats, not enough seats booked" << endl;
            }
        }
    }
    void travelLocally()
    {
        if (localFlights > 0)
        {
            cout << "Plane is traveling locally today" << endl;
            localFlights--;
            currentSeats_economy = 0;
            currentSeats_bussiness = 0;
        }
        else
        {
            cout << "Cannot travel locally, no local flights available" << endl;
        }
    }

    void travelInternationally()
    {
        if (internationalFlights > 0)
        {
            cout << "Plane is traveling internationally today" << endl;
            internationalFlights--;
            currentSeats_economy = 0;
            currentSeats_bussiness = 0;
        }
        else
        {
            cout << "Cannot travel internationally, no international flights available" << endl;
        }
    }
    //* claculate the duration of a  flight
    void Flight_Duration(int departureTime, int arrivalTime)
    {
        int Flight_Duration = (24) - departureTime - (24 - arrivalTime);
        if (Flight_Duration < 0)
            Flight_Duration * (-1);
        cout << " The flight duration of a flight in hours is :" << Flight_Duration << endl;
    }
    // * condition to chec a plane is travel locally or international
    void check_plane(string PlaneType, string flighType)
    {
        if (PlaneType == "PIA")
        {
            if (flighType == "Loacl")
            {
                internationalFlights = 0;
            }
            else if (flighType == "International")
                localFlights = 0;
        }
    }

    void display()
    {
        cout << "Plane Type: " << planeType << endl;
        cout << "Maximum Seats: " << maxSeats << endl;
        cout << "Maximum Airplanes: " << maxAirplanes << endl;
        cout << "Current Airplanes: " << currentAirplanes << endl;
        cout << "Local Flights: " << localFlights << endl;
        cout << "International Flights: " << internationalFlights << endl;
        cout << "Current Seats economy Class : " << currentSeats_economy << endl;
        cout << "Current Seats bussiness Class : " << currentSeats_bussiness << endl;
    }
};

