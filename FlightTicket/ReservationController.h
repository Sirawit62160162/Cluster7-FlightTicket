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
using namespace std;

class ReservationController
{
	public:
    	void Register(string firstname,string lastname,string passportId,string username,string password);
		bool login(string username,string password);
		void reserveTicket( string flightCode );
		void getSeat(string flightCode);  
		void reserveSeat(string seatId);
    	void getCustomerinformation();
		void createTickedid();
		void showTicketinformation();
		void showFlight();
		bool cancelTicketid(string ticketId);
		void showCustomer();
		void deleteFlight(string flightCode);
		void addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		bool checkin(string ticketId);
		void reserveTicketName(string firstname,string lastname,string passportId); 
};

#endif
