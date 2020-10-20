#include "UI.h"
<<<<<<< HEAD

bool UI::Register(string firstname,string lastname,string passportId,string username,string password){
=======
int UI::test(){
	int i =6;
	return i;
}
void UI::Register(string firstname,string lastname,string passportId,string username,string password){
>>>>>>> 7adaa883c8ca5164ddc77a97c85a8e8ce878e67d
	ReservationController *regis = new ReservationController();
	regis->Register(firstname,lastname,passportId,username,password);
	delete regis;
	return true;
}
bool UI::login(string username,string password){
<<<<<<< HEAD
	ReservationController *log = new ReservationController();
	return log->login(username,password);
=======
	ReservationController *login = new  ReservationController();
	int status;
	status = login->login(username,password);
	delete login;
	return status;
	
>>>>>>> 7adaa883c8ca5164ddc77a97c85a8e8ce878e67d
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


