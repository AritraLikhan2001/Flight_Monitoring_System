#include "Emergency.h"


    string Flight::getFlightNumber() const {
        return flightNumber;
    }



    void FlightEmergency :: handleIncident() {
        cout << "Flight Emergency\n";
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Incident Description: " << incidentDescription << endl;
        // Additional handling operations can be performed here
    }


    void WeatherEmergency:: handleIncident() {
         cout << "Weather Emergency\n";
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Weather Condition: " << weatherCondition << endl;
        // Additional handling operations can be performed here
    }

vector<Flight> parseFlightData(const string& fileName) {
    vector<Flight> flights;

    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Failed to open the file: " << fileName << endl;
        return flights;
    }

    string line;
    getline(inputFile, line); // Skip header line

    while (getline(inputFile, line)) {
        stringstream ss(line);
       string flightNumber, departureAirport, departureDate, departureTime, arrivalAirport, arrivalDate, arrivalTime, aircraftType;

        getline(ss, flightNumber, ',');
        getline(ss, departureAirport, ',');
        getline(ss, departureDate, ',');
        getline(ss, departureTime, ',');
        getline(ss, arrivalAirport, ',');
        getline(ss, arrivalDate, ',');
        getline(ss, arrivalTime, ',');
        getline(ss, aircraftType, ',');
        flights.emplace_back(flightNumber, departureAirport, departureDate, departureTime, arrivalAirport, arrivalDate, arrivalTime, aircraftType);
    }

    inputFile.close();

    return flights;
}

void ManageEmergency()
{
    string emergencyFileName = "emergency_data.txt";
    string flightFileName = "flight_data.txt";

    ifstream emergencyFile(emergencyFileName);

    if (!emergencyFile) {
        cerr << "Failed to open the file: " << emergencyFileName << endl;
        return ;
    }

    vector<Flight> flights = parseFlightData(flightFileName);

    string line;
    getline(emergencyFile, line); // Skip header line

    while (getline(emergencyFile, line)) {
        stringstream ss(line);
        string flightNumber, incidentType, description;

        getline(ss, flightNumber, ',');
        getline(ss, incidentType, ',');
        getline(ss, description, ',');

        if (incidentType == "Flight") {
            for (const Flight& flight : flights) {
                if (flight.getFlightNumber() == flightNumber) {
                    EmergencyIncident *b;
                    FlightEmergency flightEmergency(flightNumber, description);
                    b = &flightEmergency;
                    b->handleIncident();
                }
            }
        } else if (incidentType == "Weather") {
             for (const Flight& flight : flights) {
                if (flight.getFlightNumber() == flightNumber) {
                    EmergencyIncident *c;
            WeatherEmergency weatherEmergency(flightNumber,description);
            c = &weatherEmergency;
            c->handleIncident();
        }
        }
        }
      
        cout << endl;
    }

    emergencyFile.close();

}
