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
	if(seat != "10"){
		ticketId = flight + "0" + seat;
	}else{
		ticketId = flight + seat;	
	}
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

bool ReservationCustomer::cancelTicketId(string ticketcode){
	string flightCode,seatId,status,Ticketcheck,name,lname,passId,start,destination,tStart,tDestination,price;
	string str;
	status = "avalable";
	ifstream readFile;
	Seat *S = new Seat();
	readFile.open("DataBased\\ReserveCustomer.txt",ios::in);
	while(getline(readFile,str)){
			name = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			lname = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			passId = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			start = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			destination = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tStart = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tDestination = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			price = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			flightCode = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			seatId = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			status = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			Ticketcheck = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			if(ticketcode == Ticketcheck){
				if(S->changeStatusCancel(flightCode,seatId)== 0){
					return false;
				}else{
					S->changeStatusCancel(flightCode,seatId);
					return true;
				}
			}
	}
	return false;
}

void ReservationCustomer::setStatusCancel(string s,string ticketid){
	string str;
	ifstream readFile;
	int k=0;
	readFile.open("DataBased\\ReserveCustomer.txt",ios::in);
//if(ticketcode==ticketid)
	while(getline(readFile,str)){
		k++;
	}
	int i=0;
	readFile.close();
	string flightCode[k],seatId[k],status[k],Ticketcheck[k],name[k],lname[k],passId[k],start[k],destination[k],tStart[k],tDestination[k],price[k];
	readFile.open("DataBased\\ReserveCustomer.txt",ios::in);
	while(getline(readFile,str)){
			name[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			lname[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			passId[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			start[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			destination[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tStart[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tDestination[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			price[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			flightCode[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			seatId[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			status[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			Ticketcheck[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			i++;
	}
	for(int i=0;i<k;i++){
		if(Ticketcheck[i] == ticketid){
			status[i] = s;
			
		}
	}
	ofstream write;
	write.open("DataBased\\ReserveCustomer.txt",ios::out);
	for(int i=0;i<k;i++){
		write << name[i] <<","<< lname[i] << "," << passId[i] << "," 
		<< start[i] << "," << destination[i] << "," <<tStart[i]<< ","<< tDestination[i] << ","<< price[i] << "," << flightCode[i] << "," 
		<< seatId[i] << "," << status[i] << "," << Ticketcheck[i] << endl;
	}
	write.close();
}
void ReservationCustomer::setStatusCheckin(string s,string ticketid){
	string str;
	ifstream readFile;
	int k=0;
	readFile.open("DataBased\\ReserveCustomer.txt",ios::in);
	while(getline(readFile,str)){
		k++;
	}
	int i=0;
	readFile.close();
	string flightCode[k],seatId[k],status[k],Ticketcheck[k],name[k],lname[k],passId[k],start[k],destination[k],tStart[k],tDestination[k],price[k];
	readFile.open("DataBased\\ReserveCustomer.txt",ios::in);
	while(getline(readFile,str)){
			name[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			lname[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			passId[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			start[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			destination[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tStart[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tDestination[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			price[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			flightCode[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			seatId[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			status[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			Ticketcheck[i] = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			i++;
	}
	for(int i=0;i<k;i++){
		if(Ticketcheck[i] == ticketid){
			status[i] = s;
		}
	}
	ofstream write;
	write.open("DataBased\\ReserveCustomer.txt",ios::out);
	for(int i=0;i<k;i++){
		write << name[i] <<","<< lname[i] << "," << passId[i] << "," 
		<< start[i] << "," << destination[i] << "," <<tStart[i]<< ","<< tDestination[i] << ","<< price[i] << "," << flightCode[i] << "," 
		<< seatId[i] << "," << status[i] << "," << Ticketcheck[i] << endl;
	}
	write.close();
}

void ReservationCustomer::showCustomer(){
		ifstream show;
	show.open("DataBased\\ReserveCustomer.txt",ios::in);
	string firstname,lastname,passportID,str,st,des,dep,arr,p,code,seatID,status,ticketID;
	cout << endl;
	cout << "==================================================== ReserveCustomer =========================================================================" << endl;
		cout << setw(10) << setfill(' ') << left << "Firstname"
		<< setw(17) << setfill(' ') << left << "Lastname"
		<< setw(13) << setfill(' ') << left << "passportID"
		<< setw(10) << setfill(' ') << left << "Start" 
		<< setw(12) << setfill(' ') << left << "Destination"  
		<< setw(14) << setfill(' ') << left << "DepartureTime" 
		<< setw(14) << setfill(' ') << left << "ArriveTime" 
		<< setw(8) << setfill(' ') << left << "Price"      
		<< setw(12) << setfill(' ') << left << "FlightCode" 
		<< setw(7) << setfill(' ') << left << "SeatID"  
		<< setw(13) << setfill(' ') << left << "Status"
		<< setw(20) << setfill(' ') << left << "TicketID" << endl;  
	cout << "==============================================================================================================================================" << endl;
	while(getline(show,str)){
		firstname = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		lastname = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		passportID = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		st = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		des = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		dep = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		arr = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		p = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		code = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		seatID = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		status = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		ticketID = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		/*show*/
		cout << setw(10) << setfill(' ') << left << firstname
		<< setw(17) << setfill(' ') << left << lastname
		<< setw(13) << setfill(' ') << left << passportID
		<< setw(10) << setfill(' ') << left << st 
		<< setw(12) << setfill(' ') << left << des  
		<< setw(14) << setfill(' ') << left << dep 
		<< setw(14) << setfill(' ') << left << arr 
		<< setw(8) << setfill(' ') << left << p      
		<< setw(12) << setfill(' ') << left << code 
		<< setw(7) << setfill(' ') << left << seatID  
		<< setw(13) << setfill(' ') << left << status
		<< setw(20) << setfill(' ') << left << ticketID << endl;  
	}
	cout << "==============================================================================================================================================" << endl;	
}
bool ReservationCustomer::checkinTicketId(string ticketcode){
	string flightCode,seatId,status,Ticketcheck,name,lname,passId,start,destination,tStart,tDestination,price;
	string str;
	status = "not avalable";
	ifstream readFile;
	Seat *S = new Seat();
	readFile.open("DataBased\\ReserveCustomer.txt",ios::in);
	while(getline(readFile,str)){
			name = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			lname = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			passId = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			start = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			destination = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tStart = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			tDestination = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			price = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			flightCode = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			seatId = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			status = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);	
			Ticketcheck = str.substr(0,str.find(','));
				str.erase(0,str.find(',')+1);
			if(ticketcode == Ticketcheck){
				if(S->changeStatusCheckin(flightCode,seatId) == 0){
					return false;
				}else{
					S->changeStatusCheckin(flightCode,seatId);
					return true;
				}
			}		
	}
	return false;	
}
Customer ReservationCustomer::reserveTicketName(string firstname,string lastname,string passportId){
	informationCustomer.setReserveName(firstname,lastname,passportId);
	return informationCustomer;
}
string ReservationCustomer::getTicketId(){
	return ticketId;
}

