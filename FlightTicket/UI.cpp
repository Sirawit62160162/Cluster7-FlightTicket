#include "UI.h"
bool UI::Register(string firstname,string lastname,string passportId,string username,string password){
	ReservationController *regis = new ReservationController();
	if(regis->checkRegister(username,password)== 0){
		return false;
	}else{
		regis->Register(firstname,lastname,passportId,username,password);
		delete regis;
		return true;
	}
}
bool UI::login(string username,string password){
	ReservationController *log = new ReservationController();
	customer = log->getCustomerinformation(username,password);
	//show
	if(log->login(username,password)== 1){
		cout << endl;
		cout << "============ User Information ============" << endl;
		cout << "Firstname : " << customer.getFirstname() << endl;
		cout << "Lastname : " << customer.getLastname() << endl;
		cout << "Passport ID : " << customer.getPassportId() << endl;
	    cout << "==========================================" << endl;
	    return true;
	}else{
		return false;
	}
	delete log;
}
bool UI::reserveTicket(string flightCode){
	ReservationController *reflight = new ReservationController();
	if(reflight->checkFlight(flightCode) == 0){
		return false;
	}else{
		flight = reflight->reserveTicket(flightCode);
		//show

			cout << "========== Ticket Information ===========" << endl;
			cout << "+++ Travel information +++" << endl;
			cout << "  -> FlightCode : " << flight.getFlightCode() << endl;
			cout << "  -> Start : " << flight.getStart() << endl; 
			cout << "  -> Destination : " << flight.getdestination() << endl;
			cout << endl;
			cout << "+++ Time +++" << endl;
			cout << "  -> DepartureTime : " << flight.getdepartureTime() << " o'clock" << endl;
			cout << "  -> ArriveTime    : " << flight.getarriveTime() << " o'clock" << endl;
			cout << endl;
			cout << "+++ Charges(/person) ++" << endl;
			cout << "  -> Price : " << flight.getprice() << " Baht" << endl;
			cout << endl;
			cout << "+++ Traveler information +++" << endl;
			cout << "  -> Firstname : " << customer.getFirstname() << endl;
			cout << "  -> Lastname : " << customer.getLastname() << endl;
			cout << "  -> Passport ID : " << customer.getPassportId() << endl;
			cout << "=========================================" << endl;
				//
		enter();
		system("cls");
		reflight->getSeat(flightCode);
		delete reflight;
		return true;
	}
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
	//
	if(check == 1){
		system("cls");
		char readA[25] = "ASCII\\reserveSuccess.txt";
		outputMenu(readA);
		cout << endl;
		ticketId = s->createTickedId(flight.getFlightCode(),seat.getseatId());
		cout << "======================== Ticket =======================" << endl;
		char read[25] = "ASCII\\airplane.txt";
		outputMenu(read);
		cout << "    <" << flight.getStart() << ">                             <" << flight.getdestination() << ">"<< endl;
		cout << endl;
		cout << "+++ Travel information +++" << endl;
		cout << "  -> FlightCode : " << flight.getFlightCode() <<endl;
		cout << "  -> Start : "<< flight.getStart() << endl;
		cout << "  -> Destination : "<< flight.getdestination() << endl;
		cout << "  -> DepartureTime : "<< flight.getdepartureTime() << endl;
		cout << "  -> ArriveTime : "<< flight.getarriveTime() << endl;
	//
		cout << endl;
		cout << "+++ Seat +++" << endl;
		cout << "  -> SeatID : " << seat.getseatId() << endl;
		cout << endl;
		cout << "+++ Charges(/person) ++" << endl;
		cout << "  -> Price : " << flight.getprice() << " Baht" << endl;
		cout << endl;
		cout << "+++ Traveler information +++" << endl;
		cout << "  -> Firstname :" << customer.getFirstname() << endl;
		cout << "  -> Lastname : " << customer.getLastname() << endl;
		cout << "  -> Passport ID : " << customer.getPassportId() << endl;
		cout << endl;
		cout << "*** Ticket ID : #" << ticketId << endl;
		cout << "=======================================================" << endl;
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
    if(cancelTicketId->cancelTicketid(ticketId)== 0){
    	return false;
	}else{
		cancelTicketId->cancelTicketid(ticketId);
		return true;
	}
}

void UI::showCustomer(){
    	ReservationController *show = new ReservationController();
    	show->showCustomer();
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
    if(checkin->checkin(ticketId)== 0){
    	return false;
	}else{
		checkin->checkin(ticketId);
		return true;
	}
}
	
void UI::reserveTicketName(string firstname,string lastname,string passportId){
	string ticketId;
	ReservationController *re = new ReservationController(); 
	customer = re->reserveTicketName(firstname,lastname,passportId);
	ticketId = re->createTickedId(flight.getFlightCode(),seat.getseatId());
	system("cls");
	char readA[25] = "ASCII\\reserveSuccess.txt";
	outputMenu(readA);
	cout << endl;
	cout << "======================== Ticket =======================" << endl;
	char read[25] = "ASCII\\airplane.txt";
	outputMenu(read);
	cout << "    <" << flight.getStart() << ">                             <" << flight.getdestination() << ">"<< endl;
	cout << endl;
	cout << "+++ Travel information +++" << endl;
	cout << "  -> FlightCode : " << flight.getFlightCode() <<endl;
	cout << "  -> Start : "<< flight.getStart() << endl;
	cout << "  -> Destination : "<< flight.getdestination() << endl;
	cout << "  -> DepartureTime : "<< flight.getdepartureTime() << endl;
	cout << "  -> ArriveTime : "<< flight.getarriveTime() << endl;
	//
	cout << endl;
	cout << "+++ Seat +++" << endl;
	cout << "  -> SeatID : " << seat.getseatId() << endl;
	cout << endl;
	cout << "+++ Charges(/person) ++" << endl;
	cout << "  -> Price : " << flight.getprice() << " Baht" << endl;
	cout << endl;
	cout << "+++ Traveler information +++" << endl;
	cout << "  -> Firstname :" << customer.getFirstname() << endl;
	cout << "  -> Lastname : " << customer.getLastname() << endl;
	cout << "  -> Passport ID : " << customer.getPassportId() << endl;
	cout << endl;
	cout << "*** Ticket ID : #" << ticketId << endl;
	cout << "=======================================================" << endl;
	re->saveTicketinformation(customer,flight,seat,ticketId);
}



