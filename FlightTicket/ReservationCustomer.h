#ifndef RESERVATIONCUSTOMER_H
#define RESERVATIONCUSTOMER_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
#include"Flight.h"
#include"Customer.h"
#include"Seat.h"
using namespace std;

class ReservationCustomer
{
	private:
		Customer informationCustomer;
		Flight informationFlight;
		Seat informationSeat;
		string ticketId;
	public:
		Flight reserveTicket(string flightCode);
		Seat reserveSeat(string seatId,string flightCode);
		Customer getCustomerInformation(string username,string password);
		string createTicketId(string flight,string seat);
		void saveTicketInformation(Customer customer,Flight flight,Seat seat,string);
		bool cancelTicketId(string ticketcode);
		void setStatus(string status,string ticketid);
		void showCustomer();
		bool checkinTicketId(string ticketId);
		Customer reserveTicketName(string firstname,string lastname,string passportId);
		string getTicketId();
};

#endif
