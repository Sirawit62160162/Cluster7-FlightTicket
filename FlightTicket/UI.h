#ifndef UI_H
#define UI_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
#include"ReservationController.h"
#include"Flight.h"
#include<conio.h>
using namespace std;

class UI
{
	private:
		Flight flight;
		Seat seat;
		Customer customer;
	public:
		bool Register(string firstname,string lastname,string passportId,string username,string password);
		bool login(string username,string password);
		bool reserveTicket(string flightCode);
		bool reserveSeat(string seatId,string flightCode,int check);
		void showFlight();
		bool cancelTicketId(string ticketId);
		void showCustomer();
		bool deleteFlight(string flightCode);
		bool addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode);
		bool checkin(string ticketId);
		void reserveTicketName(string firstname,string lastname,string passportId);


		void enter(){
			cout << endl;
 			cout << "---------------------------" << endl;
 			cout << "- Press Enter to Continue -" << endl;
 			cout << "---------------------------";
   			getch();
		}		
		
		void outputMenu(char read[]){
 			ifstream menu;
 			menu.open(read);
 			string line = " ";//Read string from file
		 	while(getline(menu,line)){
  				cout << line << endl;
 			}
		}//Read Menu from file	
};

#endif
