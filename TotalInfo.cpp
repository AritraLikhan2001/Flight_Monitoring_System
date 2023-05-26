
#include "TotalInfo.h"

    FlightInfo FlightInfo:: operator+(const FlightInfo& other) {
        FlightInfo result;
        result.passengers = this->passengers + other.passengers;
        result.crews = this->crews + other.crews;
        result.flightHours = this->flightHours + other.flightHours;
        return result;
    }

    void FlightInfo:: printData() {
        cout << "Total passengers: " << passengers << endl;
        cout << "Total crews: " << crews << endl;
        cout << "Total flight hours: " << flightHours << endl;
    }

    void TotalFlightInfo()
    {
        
    ifstream inputFile("flights.txt");
    FlightInfo totalData;
    if(inputFile.is_open())
    {   
    string flightName;
    int passengers, crews, flightHours;
     
     string line;
     getline(inputFile, line);
    while (inputFile >> flightName >> passengers >> crews >> flightHours) {
        FlightInfo currentData(passengers, crews, flightHours);
        totalData = totalData + currentData;
    }
    inputFile.close();
    }
    else
    {   cerr << "Error opening file." << endl;
        return ;
    }
    
    totalData.printData();

    }