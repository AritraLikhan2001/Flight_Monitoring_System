#include "WeatherUps.h"

    string WeatherData:: getTemperature() const {
        return temperature;
    }

    string WeatherData:: getWindSpeed() const {
        return windSpeed;
    }

    string WeatherData :: getVisibility() const {
        return visibility;
    }


    string FlightData:: getFlightDataNumber() const {
        return flightNumber;
    }

    string FlightData:: getDate() const {
        return date;
    }

    string FlightData:: getTime() const {
        return time;
    }

    string FlightData:: getOrigin() const {
        return origin;
    }

    string FlightData:: getDestination() const {
        return destination;
    }

    const WeatherData& FlightData:: getWeatherData() const {
        return weatherData;
    }

    void FlightData:: updateWeatherData(const string& temp, const string& wind, const string& vis) {
        weatherData = WeatherData(temp, wind, vis);
    }



    FlightData FlightDataManager::parseFlightData(const string& line) {
        istringstream iss(line);
        string flightNumber, date, time, origin, destination;
        string temperature, windSpeed, visibility;
        getline(iss, flightNumber, ',');
        getline(iss, date, ',');
        getline(iss, time, ',');
        getline(iss, origin, ',');
        getline(iss, destination, ',');
        getline(iss, temperature, ',');
        getline(iss, windSpeed, ',');
        getline(iss, visibility, ',');

        return FlightData(flightNumber, date, time, origin, destination, temperature, windSpeed, visibility);
    }

    void FlightDataManager::readFlightData(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            getline(file, line); // Read and ignore the header line
            while (getline(file, line)) {
                FlightData flight = parseFlightData(line);
                flights.push_back(flight);
            }
            file.close();
        } else {
            cerr << "Error opening file: " << filename << endl;
        }
    }

    void FlightDataManager:: writeFlightData(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "FlightData_Number,Date,Time,Origin,Destination,Temperature(C),Wind Speed(km/h),Visibility(km)" << endl;
            for (const FlightData& flight : flights) {
                file << flight.getFlightDataNumber() << ","
                    << flight.getDate() << ","
                    << flight.getTime() << ","
                    << flight.getOrigin() << ","
                    << flight.getDestination() << ","
                    << flight.getWeatherData().getTemperature() << ","
                    << flight.getWeatherData().getWindSpeed() << ","
                    << flight.getWeatherData().getVisibility() << endl;
            }
            file.close();
            cout << "FlightData data has been updated and written to the file: " << filename << endl;
        } else {
            cerr << "Error opening file: " << filename << endl;
        }
    }

    FlightData* FlightDataManager:: findFlightByNumber(const string& flightNumber) {
        auto it = find_if(flights.begin(), flights.end(), [&flightNumber](const FlightData& flight) {
            return flight.getFlightDataNumber() == flightNumber;
        });

        if (it != flights.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }


template<typename T>
void printWeatherData(const T& flight) {
    cout << "FlightData Number: " << flight.getFlightDataNumber() << endl;
    cout << "Date: " << flight.getDate() << endl;
    cout << "Time: " << flight.getTime() << endl;
    cout << "Origin: " << flight.getOrigin() << endl;
    cout << "Destination: " << flight.getDestination() << endl;
    cout << "Temperature: " << flight.getWeatherData().getTemperature() << " deg C" << endl;
    cout << "Wind Speed: " << flight.getWeatherData().getWindSpeed() << " km/h" << endl;
    cout << "Visibility: " << flight.getWeatherData().getVisibility() << " km" << endl;
    cout << endl;
}

void WeatherUpdates()
{
     FlightDataManager handler;
    string filename = "weather_data.txt";
    handler.readFlightData(filename);

    // Print the flights and their weather data
    for (const FlightData& flight : handler.flights) {
        printWeatherData(flight);
    }

    // Update the weather data of a flight
    string flightNumberToUpdate;
    cout << "Enter the flight number to update its weather data: ";
    cin >> flightNumberToUpdate;

    FlightData* flightToUpdate = handler.findFlightByNumber(flightNumberToUpdate);
    if (flightToUpdate != nullptr) {
        string newTemperature, newWindSpeed, newVisibility;
        cout << "Enter the new temperature: ";
        cin >> newTemperature;
        cout << "Enter the new wind speed: ";
        cin >> newWindSpeed;
        cout << "Enter the new visibility: ";
        cin >> newVisibility;

        flightToUpdate->updateWeatherData(newTemperature, newWindSpeed, newVisibility);
        handler.writeFlightData(filename);
    } else {
        cout << "Flight not found!" << endl;
    }
}