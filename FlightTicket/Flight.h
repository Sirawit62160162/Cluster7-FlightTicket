#ifndef FLIGHT_H
#define FLIGHT_H
#include"FlightTicket.h"
#include"Seat.h"
class Flight
{
	private:
		string start;
		string destination;
		string departureTime;
		string arriveTime;
		string flightCode;
		double price;
		Seat seats[10];
	public:
		Flight reserveTicket(string flightCode);
		void getSeat(string flightCode);
		void getFlight();
		bool removeFlight(string flightCode);
		void addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
};

#endif
