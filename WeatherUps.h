#include<bits/stdc++.h>

using namespace std;

// Forward declaration of the FlightData class
class FlightData;

// Template function to print the weather data of a flight
template<typename T>
void printWeatherData(const T& flight);

// WeatherData class to store the weather information
class WeatherData {
    friend class FlightData;  // Friend class declaration

    string temperature;
    string windSpeed;
    string visibility;

public:
    WeatherData(string temp, string wind, string vis)
        : temperature(temp), windSpeed(wind), visibility(vis) {}

    // Getter functions
    string getTemperature() const; 

    string getWindSpeed() const;

    string getVisibility() const;
};

// FlightData class to store flight information
class FlightData {
    string flightNumber;
    string date;
    string time;
    string origin;
    string destination;
    WeatherData weatherData;

public:

    FlightData(const string& num, const string& dt, const string& tm,
           const string& org, const string& dest,
           const string& temp, const string& wind, const string& vis)
        : flightNumber(num), date(dt), time(tm), origin(org), destination(dest),
          weatherData(temp, wind, vis) {}

    // Getter functions
    string getFlightDataNumber() const;

    string getDate() const;

    string getTime() const;

    string getOrigin() const;

    string getDestination() const;

    const WeatherData& getWeatherData() const;

    // Function to update the weather data of a flight
    void updateWeatherData(const string& temp, const string& wind, const string& vis) ;
};

class FlightDataManager {
public:
    vector<FlightData> flights;

    FlightData parseFlightData(const string& line);

    void readFlightData(const string& filename);

    void writeFlightData(const string& filename);

    FlightData* findFlightByNumber(const string& flightNumber) ;
};

// Template function definition to print the weather data of a flight
template<typename T>
void printWeatherData(const T& flight);


void WeatherUpdates();

