#include "UpFlightData.h"

string Flight::toCsvString() const
{
        return flightNumber + "," + departureAirport + "," + departureDate + ","+ departureTime + "," + arrivalAirport + "," + arrivalDate + "," +
               arrivalTime + "," + aircraftType;
}



    void  FlightDataHandler:: readFlightData(const string& filename) {
        ifstream file(filename);
        try
        {
           if (file.is_open()) {
            string line;
            getline(file, line); // Read and ignore the header line
            while (getline(file, line)) {
                Flight flight = parseFlightData(line);
                flights.push_back(flight);
            }
            file.close();
        } else {
            throw;
        }
        }
        catch(const std::exception& e)
        {
           // std::cerr << e.what() << '\n';
           cerr << "Error opening file: " << filename << endl;
        }
        
        
    }
    void FlightDataHandler:: addFlightData(const string& filename, int numLines) {
        ofstream file(filename, ios::app);
        try
        {
           if (file.is_open()) {
            for (int i = 0; i < numLines; ++i) {
                Flight flight = createFlightFromUserInput();
                file << flight.toCsvString() << endl;
                flights.push_back(flight);
            }
            file.close();
            cout << numLines << " lines of flight data added successfully!" << endl;
        } else {
            throw;
        }
        }
        catch(const std::exception& e)
        {
            cerr << "Error opening file: " << filename << endl;
        }
        
    }

    void FlightDataHandler:: deleteFlightData(const string& filename, const string& flightNumber) {
    vector<Flight> updatedFlights;
    int numDeleted = 0;

    for (const auto& flight : flights) {
        if (flight.flightNumber != flightNumber) {
            updatedFlights.push_back(flight);
        } else {
            numDeleted++;
        }
    }

    if (numDeleted > 0) {
        ofstream file(filename);
        try
        {
            if (file.is_open()) {
            file << "FlightNumber,DepartureAirport,DepartureDate,DepartureTime,ArrivalAirport,ArrivalDate,ArrivalTime,AircraftType" << endl;
            for (const auto& flight : updatedFlights) {
                file << flight.toCsvString() << endl;
            }
            file.close();
            cout << "Deleted " << numDeleted << " line(s) of flight data with flight number " << flightNumber << " successfully!" << endl;
        } else {
            throw;
        }
        }
        catch(const std::exception& e)
        {
            cerr << "Error opening file: " << filename << endl;
        } 
        
    } else {
        cout << "Flight with flight number " << flightNumber << " not found!" << endl;
    }
}

  //  vector<Flight> flights;

    Flight FlightDataHandler :: parseFlightData(const string& line) {
        istringstream iss(line);
        string flightNumber, departureAirport, departureDate, departureTime, arrivalAirport, arrivalDate, arrivalTime, aircraftType;

        getline(iss, flightNumber, ',');
        getline(iss, departureAirport, ',');
        getline(iss, departureDate, ',');
        getline(iss, departureTime, ',');
        getline(iss, arrivalAirport, ',');
        getline(iss, arrivalDate, ',');
        getline(iss, arrivalTime, ',');
        getline(iss, aircraftType, ',');

        return Flight(flightNumber, departureAirport,departureDate,departureTime, arrivalAirport,arrivalDate, arrivalTime, aircraftType);
    }

    Flight FlightDataHandler :: createFlightFromUserInput() {
        string flightNumber, departureAirport,departureDate,departureTime, arrivalAirport,arrivalDate, arrivalTime, aircraftType;

        cout << "Enter Flight Number: ";
        cin >> flightNumber;
        cout << "Enter Departure Airport: ";
        cin >> departureAirport;
        cout << "Enter Departure Date: ";
        cin >> departureDate ;
        cout << "Enter Departure Time: ";
        cin >> departureTime ;
        cout << "Enter Arrival Airport: ";
        cin >> arrivalAirport;
        cout << "Enter Arrival Date: ";
        cin >> arrivalDate;
        cout << "Enter Arrival Time: ";
        cin >> arrivalTime;
        cout << "Enter Aircraft Type: ";
        cin >> aircraftType;

        return Flight(flightNumber, departureAirport,departureDate,departureTime, arrivalAirport,arrivalDate, arrivalTime, aircraftType);
    }

  void display(string filename)
  {
      ifstream file(filename);
           if (file.is_open()) {
            string line;
            getline(file, line); // Read and ignore the header line
            while (getline(file, line)) {
                cout<<line<<endl;
            }
            file.close();
        } else {
            cerr<<"Error opening file!"<<endl;
        }
  }  

 void ViewandUpdateFlightData(){
    FlightDataHandler handler;
    string filename = "flight_data.txt";
    handler.readFlightData(filename);

    int choice;
    int numLines;
    string flightnum;

    cout << "1. Add flight data\n";
    cout << "2. Delete flight data\n";
    cout << "3.View flight data\n";
    cout << "Enter your choice: ";

    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter the number of lines to add: ";
            cin >> numLines;
            handler.addFlightData(filename, numLines);
            break;
        case 2:
            cout << "Enter the flight number to delete: ";
            cin >> flightnum;
            handler.deleteFlightData(filename,flightnum);
            break;
        case 3:
           display(filename);
           break;
        default:
            cout << "Invalid choice!" << endl;
    }
 }
  

