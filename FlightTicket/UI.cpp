#include "UI.h"
int UI::test(){
	int i =6;
	return i;
}
void UI::Register(string firstname,string lastname,string passportId,string username,string password){
	ReservationController *regis = new ReservationController();
	regis->Register(firstname,lastname,passportId,username,password);
}
bool UI::login(string username,string password){
	ReservationController *login = new  ReservationController();
	int status;
	status = login->login(username,password);
	delete login;
	return status;
	
}
void UI::reserveTicket(string flightCode ){
	
}
void UI::reserveSeat(string seatId){
	
}

void UI::showFlight(){
	
}

bool UI::cancelTicketld(string ticketId){
	
}

void UI::showCustomer(){

}
	
bool UI::deleteFlight(string flightCode){
	
}
void UI::addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode){
	
}

bool UI::checkin(string ticketId){
	
}
	
void UI::reserveTicketName(string firstname,string lastname,string passportId){
	
}


