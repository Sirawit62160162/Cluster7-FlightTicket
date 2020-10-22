#ifndef SEAT_H
#define SEAT_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
using namespace std;
class Seat
{
	private:
		string seatId;
		string status;
	public:
		void showSeat(string flightCode);
		Seat reserveSeat(string seatId,string flightCode);
		void changeStatus(string seatId,string status);
		string getseatId();
		string getstatus();
};

#endif
