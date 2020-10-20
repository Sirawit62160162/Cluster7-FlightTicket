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
		void showSeat();
		void reserveSeat(string seatId);
		void changeStatus(string seatId,string status);
};

#endif
