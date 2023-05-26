#include "Runway.h"


    template<typename T>
    void Airport<T>:: addRunway(T* runway) {
        runways.push_back(runway);
    }

    template<class T> 
    T *Airport<T>::getAvailableRunway() const {
        for (T* runway : runways) {
            if (dynamic_cast<AvailableRunway*>(runway) != nullptr) {
                return runway;
            }
        }
        return nullptr;
    }

    template<class T> 
    string Airport<T>::getName() const {
        return name;
    }


void RunwayStatus()
{
    ifstream file("runways.txt");
    vector<Airport<Runway>> airports;

    string line;
    string airportName;
    while (getline(file, line)) {
        if (line.find("Airport:") != string::npos) {
            airportName = line.substr(line.find(":") + 2);
            airports.emplace_back(airportName);
        }
        else if (line.find("Runway") != string::npos) {
            string runwayStatus = line.substr(line.find(":") + 2);
            Runway* runway = nullptr;
            if (runwayStatus == "Available") {
                runway = new AvailableRunway(line.substr(0, line.find(":")));
            }
            else if (runwayStatus == "Occupied") {
                runway = new OccupiedRunway(line.substr(0, line.find(":")));
            }

            if (runway != nullptr) {
                airports.back().addRunway(runway);
            }
        }
    }

    string inputAirport;
    cout << "Enter the name of the airport: ";
    cin>> inputAirport;

    for (const auto& airport : airports) {
        if (airport.getName() == inputAirport) {
            Runway* availableRunway = airport.getAvailableRunway();
            if (availableRunway != nullptr) {
                if (AvailableRunway* available = dynamic_cast<AvailableRunway*>(availableRunway)) {
                    cout << "Available runway for landing: " << available->name << endl;
                }
            }
            else {
                cout << "No available runway for landing." << endl;
            }
            break;
        }
    }

    for (auto& airport : airports) {
        for (Runway* runway : airport.runways) {
            delete runway;
        }
    }
}