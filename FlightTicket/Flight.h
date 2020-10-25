#ifndef FLIGHT_H
#define FLIGHT_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
#include"Seat.h"
using namespace std;class Flight
{
	private:
		string start;
		string destination;
		string departureTime;
		string arriveTime;
		string flightCode;
		double price;
		Seat seats;
	public:
		Flight reserveTicket(string flightCode);
		void getSeat(string f);
		void getFlight();
		bool removeFlight(string flightCode);
		void addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		string getStart();
		string getdestination();
		string getdepartureTime();
		string getarriveTime();
		double getprice();
		string getFlightCode();
		bool checkFlight(string flightCode);
		
};

#endif
