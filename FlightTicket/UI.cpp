#include "UI.h"

bool UI::Register(string firstname,string lastname,string passportId,string username,string password){
	ReservationController *regis = new ReservationController();
	regis->Register(firstname,lastname,passportId,username,password);
	delete regis;
	return true;
}
bool UI::login(string username,string password){
	ReservationController *log = new ReservationController();
	return log->login(username,password);
}
void UI::reserveTicket(string flightCode ){
	
}
void UI::reserveSeat(string seatId){
	
}

void UI::showFlight(){
	ReservationController *showFlight = new ReservationController();
	showFlight->showFlight();
}

bool UI::cancelTicketld(string ticketId){
	
}

void UI::showCustomer(){

}
	
bool UI::deleteFlight(string flightCode){
	ReservationController *deleteFlight = new ReservationController();
	return deleteFlight->deleteFlight(flightCode);
}
bool UI::addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode){
	ReservationController *addFlight = new ReservationController();
	addFlight->addFlight(start,destination,departureTime,arriveTime,price,flightCode);
	delete addFlight;
	return true;
}

bool UI::checkin(string ticketId){
	
}
	
void UI::reserveTicketName(string firstname,string lastname,string passportId){
	
}


