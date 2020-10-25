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
		bool changeStatusCancel(string flightCode,string seatId);
		bool changeStatusCheckin(string flightCode,string seatId);
		string getseatId();
		string getstatus();
		void addseat(string flightCode);
		void deleteseat(string flightCode);
		bool checkseat(string flightCode,string seatId);
		
};

#endif
