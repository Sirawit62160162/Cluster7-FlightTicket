#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
#include"Customer.h"
#include"Flight.h"
#include"ReservationCustomer.h"
using namespace std;

class ReservationController
{
	public:
    	void Register(string firstname,string lastname,string passportId,string username,string password);
		bool login(string username,string password);
		Flight reserveTicket(string flightCode );
		void getSeat(string flightCode);  
		Seat reserveSeat(string seatId,string flightCode);
    	Customer getCustomerinformation(string username,string password);
		string createTickedId(string filght,string seatid);
		void saveTicketinformation(Customer customer,Flight flight,Seat seat,string ticketid);
		void showFlight();
		bool cancelTicketid(string ticketId);
		void showCustomer();
		bool deleteFlight(string flightCode);
		void addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		bool checkin(string ticketId);
		Customer reserveTicketName(string firstname,string lastname,string passportId);
		bool checkseat(string flightCode,string seatid); 
};

#endif
