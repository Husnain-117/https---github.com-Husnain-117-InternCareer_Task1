#include <iostream>
#include <string>
using namespace std;

class Passport {
private:
    bool isLocal;
    bool isForeign;
    bool hasVisa;
public:
    Passport(bool local = true, bool visa = true , bool foreign=true) {
        isLocal = local;
        hasVisa = visa;
        isForeign=foreign;
    }

    bool getIsLocal() {
        return isLocal;
    }
    bool getIsForiegn() {
        return isForeign;
    }

    void setIsLocal(bool local) {
        isLocal = local;
    }
    void setIsForeign(bool foreign) {
        isForeign = foreign;
    }

    bool getHasVisa() {
        return hasVisa;
    }

    void setHasVisa(bool visa) {
        hasVisa = visa;
    }
};

class Passenger {
private:
    string name;
    string email;
    string password;
    Passport passport;
    string mostVisitedCountry;
    double travelCostEstimate;

public:
Passenger(){
    
}
    Passenger(string n, string e, string p, Passport pass,
              string mvc = "", double tce = 0.0) {
        name = n;
        email = e;
        password = p;
        passport = pass;
        mostVisitedCountry = mvc;
        travelCostEstimate = tce;
    }

    string getName() {
        return name;
    }

    void setName(std::string n) {
        name = n;
    }

    string getEmail() {
        return email;
    }

    void setEmail(string e) {
        email = e;
    }

    string getPassword() {
        return password;
    }

    void setPassword(string p) {
        password = p;
    }

    Passport getPassport() {
        return passport;
    }

    void setPassport(Passport pass) {
        passport = pass;
    }

    string getMostVisitedCountry() {
        return mostVisitedCountry;
    }

    void setMostVisitedCountry(string mvc) {
        mostVisitedCountry = mvc;
    }

    double getTravelCostEstimate() {
        return travelCostEstimate;
    }

    void setTravelCostEstimate(double tce) {
        travelCostEstimate = tce;
    }



  

    void viewMostVisitedCountry() {
        // implementation code for viewing most visited country and travel cost estimate
    }
    void estimated_Price(){
        // --------------
    }

    bool travel_locally( bool local , bool visa ){
        if(local==true)
        return true;
        else cout<<" You Have not a valid Password , You cant travel "<<endl;
    }
    bool travel_Foriegn( bool foreign , bool visa ){
        if(foreign==true){
            if(visa=true)
            return true;
        }
        else cout<<" You Have no Visa, You are unable to travel in Foreign Countries  "<<endl;
    }

};
// int main() {
//     string mostVisitedCountry;
//     bool isLocal, isForeign, hasVisa;
//     double travelCostEstimate;

  

//     cout << "Is the passport local? (0/1): ";
//     cin >> isLocal;

//     cout << "Is the passport foreign? (0/1): ";
//     cin >> isForeign;

//     cout << "Does the passport have a visa? (0/1): ";
//     cin >> hasVisa;

//     cout << "Enter most visited country: ";
//     cin.ignore();
//     getline(cin, mostVisitedCountry);

//     cout << "Enter travel cost estimate: ";
//     cin >> travelCostEstimate;

//     // Create a Passport object
//     Passport passport(isLocal, hasVisa, isForeign);

//     // Create a Passenger object
//     Passenger passenger(name, email, password, passport, mostVisitedCountry, travelCostEstimate);

//     // Perform actions with the passenger object
//     passenger.registerPassenger();
//     passenger.login();
//     passenger.updateDetails();
//     passenger.viewMostVisitedCountry();

//     // Perform travel based on passport type
//     bool localTravelResult = passenger.travel_locally(isLocal, hasVisa);
//     bool foreignTravelResult = passenger.travel_Foriegn(isForeign, hasVisa);

//     if (localTravelResult) {
//         cout << "You can travel locally." << endl;
//     }

//     if (foreignTravelResult) {
//         cout << "You can travel to foreign countries." << endl;
//     }

//     return 0;
// }


