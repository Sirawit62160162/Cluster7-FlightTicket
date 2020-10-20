#ifndef UI_H
#define UI_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
#include"ReservationController.h"
using namespace std;

class UI
{
	public:
<<<<<<< HEAD
		bool Register(string firstname,string lastname,string passportId,string username,string password);
		bool login(string username,string password);
=======
		void Register(string firstname,string lastname,string passportId,string username,string password);
		bool login(string username,string password);
		int test();
>>>>>>> 7adaa883c8ca5164ddc77a97c85a8e8ce878e67d
		void reserveTicket(string flightCode );
		void reserveSeat(string seatId);
		void showFlight();
		bool cancelTicketld(string ticketId);
		void showCustomer();
		bool deleteFlight(string flightCode);
		bool addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		bool checkin(string ticketId);
		void reserveTicketName(string firstname,string lastname,string passportId);
			
};

#endif
