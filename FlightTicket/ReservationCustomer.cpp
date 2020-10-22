#include "ReservationCustomer.h"

Flight ReservationCustomer::reserveTicket(string flightCode){
	informationFlight = informationFlight.reserveTicket(flightCode);
	return informationFlight;
}

Seat ReservationCustomer::reserveSeat(string seatId,string flightCode){
	informationSeat = informationSeat.reserveSeat(seatId,flightCode);
	return informationSeat;
}

Customer ReservationCustomer::getCustomerInformation(string user,string pass){
	informationCustomer = informationCustomer.getCustomerInformasion(user,pass);
	return informationCustomer;
}

string ReservationCustomer::createTicketId(string flight,string seat){
	ticketId = flight + seat;
	return ticketId;	
}	

void ReservationCustomer::saveTicketInformation(Customer customer,Flight flight,Seat seat,string id){	
 	informationCustomer = customer;
 	informationFlight = flight;
 	informationSeat = seat;
 	ticketId = id;
 	ofstream write;
	write.open("DataBased\\ReserveCustomer.txt",ios::app);
	write << informationCustomer.getFirstname() <<","<<informationCustomer.getLastname()<<","<<informationCustomer.getPassportId()<<",";
	write << informationFlight.getStart()<<","<<informationFlight.getdestination()<<","<<informationFlight.getdepartureTime()<<","<<informationFlight.getarriveTime()<<","<<informationFlight.getprice()<<","<<informationFlight.getFlightCode()<<",";
	write << informationSeat.getseatId() <<","<< informationSeat.getstatus() <<","<< ticketId <<endl;
	write.close(); 
}

bool ReservationCustomer::cancelTickrtId(){
	
}

void ReservationCustomer::setStatus(string status){
	
}

void ReservationCustomer::showCustomer(){
	
}
bool ReservationCustomer::checkinTicketId(string ticketId){
	
}

Customer ReservationCustomer::reserveTicketName(string firstname,string lastname,string passportId){
	informationCustomer.setReserveName(firstname,lastname,passportId);
	return informationCustomer;
}
string ReservationCustomer::getTicketId(){
	return ticketId;
}

