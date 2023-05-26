#include <bits/stdc++.h>

using namespace std;


class Flight {
public:
    string flightNumber;
    string departureAirport;
    string departureDate;
    string departureTime;
    string arrivalAirport;
    string arrivalDate;
    string arrivalTime;
    string aircraftType;

    Flight() {}

    Flight(const string& flightNumber, const string& departureAirport,const string& departureDate, const string& departureTime,
           const string& arrivalAirport,const string& arrivalDate, const string& arrivalTime, const string& aircraftType)
        : flightNumber(flightNumber), departureAirport(departureAirport),departureDate(departureDate), departureTime(departureTime),
          arrivalAirport(arrivalAirport),arrivalDate(arrivalDate), arrivalTime(arrivalTime), aircraftType(aircraftType) {}

    string toCsvString() const; 
    
    string getFlightNumber() const;
};

class FlightDataHandler {
  public:
    void readFlightData(const string& filename);

    void addFlightData(const string& filename, int numLines);

    void deleteFlightData(const string& filename, const string& flightNumber);

private:
    vector<Flight> flights;

    Flight parseFlightData(const string& line);

    Flight createFlightFromUserInput();
};
void display(string filename);

void ViewandUpdateFlightData();