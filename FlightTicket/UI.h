#ifndef UI_H
#define UI_H
#include"FlightTicket.h"

class UI
{
	public:
		void Register(string firstname,string lastname,string passportId,string username,string password);
		void login(string username,string password);
		void reserveTicket(string flightCode );
		void reserveSeat(string seatId);
		void showFlight();
		bool cancelTicketld(string ticketId);
		void showCustomer();
		bool deleteFlight(string flightCode);
		void addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		bool checkin(string ticketId);
		void reserveTicketName(string firstname,string lastname,string passportId);
			
};

#endif
