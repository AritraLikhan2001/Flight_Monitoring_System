all: exe

exe: main.o UpFlightData.o Emergency.o TotalInfo.o WeatherUps.o Runway.o
	g++ main.o UpFlightData.o Emergency.o TotalInfo.o WeatherUps.o Runway.o -o exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

UpFlightData.o: UpFlightData.cpp
	g++ -c UpFlightData.cpp -o UpFlightData.o

Emergency.o: Emergency.cpp
	g++ -c Emergency.cpp -o Emergency.o

TotalInfo.o: TotalInfo.cpp
	g++ -c TotalInfo.cpp -o TotalInfo.o

WeatherUps.o: WeatherUps.cpp
	g++ -c WeatherUps.cpp -o WeatherUps.o

Runway.o: Runway.cpp
	g++ -c Runway.cpp -o Runway.o	

clean:
	rm *.o