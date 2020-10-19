#ifndef RESERVATIONCUSTOMER_H
#define RESERVATIONCUSTOMER_H
#include"FlightTicket.h"
#include"Customer.h"
#include"Flight.h"
#include"Seat.h"

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
