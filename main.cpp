#include "Emergency.h"
#include "TotalInfo.h"
#include "WeatherUps.h"
#include "Runway.h"
// Header file "UpFlightData.h" has not been included since it's already included in "Emergency.h"


int main() {
   
    cout<< "Welcome to Flight Monitoring System! Select an option to operate: "<<endl;
    cout<<"1.View and Update Flight Data"<<endl;
    cout<<"2.Handle Emergency" <<endl;
    cout<<"3.Total Flight Information"<<endl;
    cout<<"4.Weather Updates"<<endl; 
    cout<<"5.Check Runway Status"<<endl;
    int option;
    cin>>option;
    if(option==1)
    {
      ViewandUpdateFlightData();
    }
    else if(option==2)
    {
       ManageEmergency();
    }
    else if(option==3)
    {
        TotalFlightInfo();
    }
    else if(option==4)
    {
        WeatherUpdates();
    }
    else if(option==5)
    {
        RunwayStatus();
    }
    else
    {
        cout<<"Invalid option!"<<endl;
    }
}
