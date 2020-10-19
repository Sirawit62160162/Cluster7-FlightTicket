#ifndef SEAT_H
#define SEAT_H
#include"FlightTicket.h"

class Seat
{
	private:
		string seatId;
		string status;
	public:
		void showSeat();
		void reserveSeat(string seatId);
		void changeStatus(string seatId,string status);
};

#endif
