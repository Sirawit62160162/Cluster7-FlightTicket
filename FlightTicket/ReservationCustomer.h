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
		string tickeId;
	public:
		void reserveTicket(string flightCode);
		void reserveSeat(string seatId);
		void getCustomerInformation();
		void createTicketId();
		ReservationCustomer showTicketInformation();
		bool cancelTickrtId();
		void setStatus(string status);
		void showCustomer();
		bool checkinTicketId(string ticketId);
		void reserveTicketName(string firstname,string lastname,string passportId);
		void creatTicketId();
};

#endif
