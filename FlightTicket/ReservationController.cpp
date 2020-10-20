#include "ReservationController.h"

void ReservationController::Register(string firstname,string lastname,string passportId,string username,string password){
	Customer *regis = new Customer();
	regis->saveRegister(firstname,lastname,passportId,username,password);
}

void ReservationController::login(string username,string password){
	
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
	
}

bool ReservationController::cancelTicketid(string ticketId){
	
}

void ReservationController::showCustomer(){
	
}

void ReservationController::deldeteFlight(string flightCode){
	
}

void ReservationController::addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode){
	
}

bool ReservationController::checkin(string ticketId){
	
}

void ReservationController::reserveTicketName(string firstname,string lastname,string passportId){
	
}

