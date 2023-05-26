#include<bits/stdc++.h>
using namespace std;

class Runway {
public:
    virtual ~Runway() {}
};

class AvailableRunway : public Runway {
public:
    string name;

    AvailableRunway(const string& name) : name(name) {}
};

class OccupiedRunway : public Runway {
public:
    string name;

    OccupiedRunway(const string& name) : name(name) {}
};

template <typename T>
class Airport {


public:
     string name;
    vector<T*> runways;
    Airport(const string& name) : name(name) {}

    void addRunway(T* runway);

    T* getAvailableRunway() const;

    string getName() const;
};

void RunwayStatus();