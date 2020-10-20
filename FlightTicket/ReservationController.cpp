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

void ReservationController::reserveTicket( string flightCode ){
	
}
	
void ReservationController::getSeat(string flightCode){
	
}
	
void ReservationController::reserveSeat(string seatId){

}
	
void ReservationController::getCustomerinformation(){
	
}

void ReservationController::createTickedid(){
	
}
	
void ReservationController::showTicketinformation(){
	
}
	
void ReservationController::showFlight(){
	Flight *showFlight = new Flight();
	showFlight->getFlight();
}

bool ReservationController::cancelTicketid(string ticketId){
	
}

void ReservationController::showCustomer(){
	
}

void ReservationController::deleteFlight(string flightCode){
	Flight *deleteFlight = new Flight();
	return 	deleteFlight->removeFlight(flightCode);
}

void ReservationController::addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode){
	Flight *addFlight = new Flight();
	addFlight->addFlight(start,destination,departureTime,arriveTime,price,flightCode);
	delete addFlight;
}

bool ReservationController::checkin(string ticketId){
	
}

void ReservationController::reserveTicketName(string firstname,string lastname,string passportId){
	
}

