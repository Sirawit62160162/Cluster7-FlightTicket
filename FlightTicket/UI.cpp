#include "UI.h"
bool UI::Register(string firstname,string lastname,string passportId,string username,string password){
	ReservationController *regis = new ReservationController();
	regis->Register(firstname,lastname,passportId,username,password);
	delete regis;
	return true;
}
bool UI::login(string username,string password){
	ReservationController *log = new ReservationController();
	customer = log->getCustomerinformation(username,password);
	//show
		cout << "=========================================" << endl;
		cout << customer.getFirstname() << " "<< customer.getLastname() <<" "<< customer.getPassportId() << endl;
	    cout << "=========================================" << endl;
		
	return log->login(username,password);
	delete log;
}
void UI::reserveTicket(string flightCode){
	ReservationController *reflight = new ReservationController();
	flight = reflight->reserveTicket(flightCode);
	//show
		cout << "=============================================================" << endl;
		cout <<  " " << flight.getStart() << " --> " << setw(12) << flight.getdestination() <<" | "; 
		cout <<  flight.getdepartureTime() << "-" << flight.getarriveTime() << " | "; 
		cout <<  setw(5) << flight.getprice() << "Bath | " << flight.getFlightCode() << endl;
		cout << "=============================================================" << endl;
	//
	reflight->getSeat(flightCode);
	delete reflight;
}
bool UI::reserveSeat(string seatId,string flightCode,int check){
	string ticketId;
	ReservationController *s = new ReservationController();
	if(s->checkseat(flightCode,seatId) == 0){
		return false;
	}else{
		seat = s->reserveSeat(seatId,flightCode);
	}
	seat = s->reserveSeat(seatId,flightCode);
	//show 
		cout << "==================================================" << endl;
		cout << "Seatid : " << seat.getseatId() << endl;
		cout << "Status : " << seat.getstatus() << endl;
		cout << "==================================================" << endl;
	//
	if(check == 1){
		ticketId = s->createTickedId(flight.getFlightCode(),seat.getseatId());
		cout << "Ticket ID : " << ticketId << endl;
		cout << "============================ Ticket ===========================" << endl;
		cout <<  customer.getFirstname() << " " << customer.getLastname() <<" " << customer.getPassportId() << endl;
		cout << flight.getStart() << "->" << flight.getdestination() << " | " << flight.getdepartureTime() << "-" << flight.getarriveTime() << " | " << flight.getFlightCode() <<endl;
		cout << endl;
		cout << "                Seat  : " << seat.getseatId() << endl; 
		cout << "                Price : " << flight.getprice() << " Baht" << endl;
		cout << " Ticket Id : " << ticketId << endl;
		cout << "===============================================================" << endl;
		s->saveTicketinformation(customer,flight,seat,ticketId);
	}//check customer or employee
	return true;
}
void UI::showFlight(){
	ReservationController *showFlight = new ReservationController();
	showFlight->showFlight();
}

bool UI::cancelTicketId(string ticketId){
	ReservationController *cancelTicketId = new ReservationController();
    cancelTicketId->cancelTicketid(ticketId);
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
	ReservationController *checkin = new ReservationController();
    checkin->checkin(ticketId);
	
}
	
void UI::reserveTicketName(string firstname,string lastname,string passportId){
	string ticketId;
	ReservationController *re = new ReservationController(); 
	customer = re->reserveTicketName(firstname,lastname,passportId);
	cout << "=========================================" << endl;
	cout << customer.getFirstname() << " "<< customer.getLastname() <<" "<< customer.getPassportId() << endl;
	cout << "=========================================" << endl;
	ticketId = re->createTickedId(flight.getFlightCode(),seat.getseatId());
	cout << "Ticket ID : " << ticketId << endl;
	cout << "============================ Ticket ===========================" << endl;
	cout <<  customer.getFirstname() << " " << customer.getLastname() <<" " << customer.getPassportId() << endl;
	cout << flight.getStart() << "->" << flight.getdestination() << " | " << flight.getdepartureTime() << "-" << flight.getarriveTime() << " | " << flight.getFlightCode() <<endl;
	cout << endl;
	cout << "                Seat  : " << seat.getseatId() << endl; 
	cout << "                Price : " << flight.getprice() << " Baht" << endl;
	cout << " Ticket Id : " << ticketId << endl;
	cout << "===============================================================" << endl;
	re->saveTicketinformation(customer,flight,seat,ticketId);
}



