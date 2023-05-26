#include<bits/stdc++.h>
using namespace std;

class FlightInfo {
private:
    int passengers;
    int crews;
    int flightHours;

public:
    FlightInfo() : passengers(0), crews(0), flightHours(0) {}

    FlightInfo(int p, int c, int fh) : passengers(p), crews(c), flightHours(fh) {}

    FlightInfo operator+(const FlightInfo& other) ;

    void printData() ;
};

void TotalFlightInfo();
