#include "ReservationController.h"
void ReservationController::Register(string firstname,string lastname,string passportId,string username,string password){
	Customer *regis = new Customer();
	regis->saveRegister(firstname,lastname,passportId,username,password);
	delete regis;
}

bool ReservationController::login(string username,string password){
	Customer *login = new Customer();
	return login->checkLogin(username,password);
}

Flight ReservationController::reserveTicket(string flightCode){
	ReservationCustomer reflight;
	return reflight.reserveTicket(flightCode);
}
	
void ReservationController::getSeat(string f){
     Flight *seat = new Flight();
	 return seat->getSeat(f);
}
	
Seat ReservationController::reserveSeat(string seatId,string flightCode){
	ReservationCustomer *seat = new ReservationCustomer;
	return seat->reserveSeat(seatId,flightCode);
}
	
Customer ReservationController::getCustomerinformation(string user,string pass){
	ReservationCustomer *c = new ReservationCustomer;
	return c->getCustomerInformation(user,pass);
}

string ReservationController::createTickedId(string f,string s){
	string ticket;
	ReservationCustomer *id = new ReservationCustomer();
	ticket = id->createTicketId(f,s);
	return ticket;
}
	
void ReservationController::saveTicketinformation(Customer customer,Flight flight,Seat seat,string id){
	ReservationCustomer *c = new ReservationCustomer();
	c->saveTicketInformation(customer,flight,seat,id);
	
}
void ReservationController::showFlight(){
	Flight *showFlight = new Flight();
	showFlight->getFlight();
}

bool ReservationController::cancelTicketid(string ticketId){
	string cancel = "Cancel";
	ReservationCustomer *Can = new ReservationCustomer();
	if(Can->cancelTicketId(ticketId)==0){
		return false;
	}else{
		Can->cancelTicketId(ticketId);
		Can->setStatusCancel(cancel,ticketId);
	}
}

void ReservationController::showCustomer(){
		ReservationCustomer *show = new ReservationCustomer();
		show->showCustomer();
}

bool ReservationController::deleteFlight(string flightCode){
	Flight *deleteFlight = new Flight();
	return 	deleteFlight->removeFlight(flightCode);
}

void ReservationController::addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode){
	Flight *addFlight = new Flight();
	addFlight->addFlight(start,destination,departureTime,arriveTime,price,flightCode);
	delete addFlight;
}

bool ReservationController::checkin(string ticketId){
	string checkin = "Checkin";
	ReservationCustomer *Che = new ReservationCustomer();
	if(Che->checkinTicketId(ticketId) == 0){
		return false;
	}else{
		Che->checkinTicketId(ticketId);
		Che->setStatusCheckin(checkin,ticketId);
	}
}

Customer ReservationController::reserveTicketName(string firstname,string lastname,string passportId){
	ReservationCustomer *c = new ReservationCustomer();
	return c->reserveTicketName(firstname,lastname,passportId);
}
bool ReservationController::checkseat(string flightCode,string seatid){
	Seat *s = new Seat();
	return s->checkseat(flightCode,seatid);
	
} 
bool ReservationController::checkFlight(string flightCode){
	Flight *f = new Flight();
	return f->checkFlight(flightCode);
}
bool ReservationController::checkRegister(string username,string password){
	Customer *c = new Customer();
	return c->checkRegister(username,password);
}
