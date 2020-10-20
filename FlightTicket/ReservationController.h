#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H
#include"FlightTicket.h"
#include"Customer.h"

class ReservationController
{
	public:
    	void Register(string firstname,string lastname,string passportId,string username,string password);
		void login(string username,string password);
		void reserveTicket( string flightCode );
		void getSeat(string flightCode);  
		void reserveSeat(string seatId);
    	void getCustomerinformation();
		void createTickedid();
		void showTicketinformation();
		void showFlight();
		bool cancelTicketid(string ticketId);
		void showCustomer();
		void deldeteFlight(string flightCode);
		void addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		bool checkin(string ticketId);
		void reserveTicketName(string firstname,string lastname,string passportId);
	  
	  
};

#endif
