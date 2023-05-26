#include<bits/stdc++.h>
#include "UpFlightData.h"
using namespace std;


// Base class for handling emergency incidents
class EmergencyIncident {
public:
    virtual void handleIncident() = 0; // Pure virtual function
};

// Derived class for handling flight-related emergencies
class FlightEmergency : public EmergencyIncident {
private:
    string flightNumber;
    string incidentDescription;

public:
    FlightEmergency(const string& flightNum, const string& description)
        : flightNumber(flightNum), incidentDescription(description) {}

    void handleIncident() ;
};

// Derived class for handling weather-related emergencies
class WeatherEmergency : public EmergencyIncident {
private:
     string flightNumber;
    string weatherCondition;

public:
    WeatherEmergency(const string& condition)
        : weatherCondition(condition) {}

        WeatherEmergency(const string& flightNum, const string& condition)
        : flightNumber(flightNum), weatherCondition(condition) {}


    void handleIncident() ;
};

// Function to parse flight data from the flight_data.txt file
vector<Flight> parseFlightData(const string& fileName) ;

void ManageEmergency();

