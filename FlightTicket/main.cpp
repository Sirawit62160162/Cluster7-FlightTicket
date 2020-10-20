#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
#include"UI.h"
#include"ReservationController.h"
#include"Customer.h"
#include"ReservationCustomer.h"
#include"Flight.h"
#include"Seat.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int choose;
	string firstName,lastName,ppId,username,password;
	string start,destination,departTime,arriveTime,flightCode;
	double price;
	
	UI *interface = new UI();
	do{
		MainMenu :
			system("cls");
			cout << "===== Reservation Fight Ticket =====" << endl;
			cout << "1. Customer" << endl;
			cout << "2. Employee" << endl;
			cout << "3. Exit" << endl;
			cout << "====================================" << endl;
			cout << "Choose Menu : ";
			cin >> choose;
			switch(choose){
				case 1 :{
							Customer :
								cout << endl; 
								//system("cls");
								cout << "===== Customer =====" << endl;
								cout << "1. Login" << endl;
								cout << "2. Register" << endl;
								cout << "3. Back" << endl;
								cout << "====================" << endl;
								cout << "Choose Menu : ";
								cin >> choose;
								switch(choose){
									case 1 :{
										cout << endl;
										cout << "======= Login =======" << endl;
										cout << "Enter Username : ";
										cin >> username;
										cout << "Enter Password : ";
										cin >> password; 								
										
										if(interface->login(username,password) == true){
											cout << "** Login Success **" << endl;
											interface->showFlight();
											cout << endl;
											cout << "Enter FlightCode : ";
											cin >> flightCode;
											//interface->reserveTicket();
											goto Customer;
										}else{
											cout << "** Login Failed **" << endl;
											goto Customer;
										}
									}//Login
									case 2 :{
										cout << endl;
										cout << "======== Register ========" << endl;
										cout << "Enter Firstname : ";
										cin >> firstName;
										cout << "Enter Lastname : ";
										cin >> lastName;
										cout << "Enter PassportID : ";
										cin >> ppId;
										cout << "Enter Username : ";
										cin >> username;
										cout << "Enter Password : ";
										cin >> password; 
										
										if(interface->Register(firstName,lastName,ppId,username,password) == true);
											cout << "** Register Success **" << endl;
										goto Customer;
									}//Register
									case 3 : goto MainMenu; 
									default : goto Customer;
								}//Customer
				}//Customer
				case 2 :{
					Employee : 
						cout << endl;
						cout << "========== Employee ==========" << endl;
						cout << "1. Reserve Flight Ticket" << endl;
						cout << "2. Show Customer Information" << endl;
						cout << "3. Show Flight" << endl;
						cout << "4. Check-In Flight" << endl;
						cout << "5. Cancel Flight" << endl;
						cout << "6. Back" << endl;
						cout << "==============================" << endl;
						cout << "Choose Menu : ";
						cin >> choose;
						switch(choose){
							case 1 :{
								ReserveFlight :
								interface->showFlight();
								cout << endl;
								//interface->reserveTicketName();
								goto Employee;
							}
							case 2 :{
								interface->showCustomer();
								goto Employee;
							}
							case 3 :{
								ShowFlight :
									interface->showFlight();
									cout << endl;
									cout << "======= Menu =======" << endl;
									cout << "1. Add Flight" << endl;
									cout << "2. Delete Flight" << endl;
									cout << "3. Back" << endl;
									cout << "====================" << endl;
									cout << "Choose Menu : ";
									cin >> choose;
									switch(choose){
										case 1 :{
											cout << endl;
											cout << "======== Add Flight ========" << endl;
											cout << "Enter Start : ";
											cin >> start;
											cout << "Enter Destination : ";
											cin >> destination;
											cout << "Enter DepartureTime : ";
											cin >> departTime;
											cout << "Enter ArriveTime : ";
											cin >> arriveTime;
											cout << "Enter Price : ";
											cin >> price;
											cout << "Enter FlightCode : ";
											cin >> flightCode;
											
											if(interface->addFlight(start,destination,departTime,arriveTime,price,flightCode) == true)
												cout << "** Add Flight Success **" << endl;
											goto ShowFlight;
										}//Add Flight
										case 2 :{
											cout << endl;
											cout << "======== Delete Flight ========" << endl;
											cout << "Enter FlightCode : ";
											cin >> flightCode;
											
											if(interface->deleteFlight(flightCode) == true)
												cout << "** Deleter Flight Success **" << endl;
											else
												cout << "** Login Failed **" << endl;

											goto ShowFlight;
										}//Delete Flight
										case 3 : goto Employee;
										default : goto ShowFlight; 
									}
							}//Show Flight
							case 4 :{
									out << endl;
									cout << "======== Check-In Flight ========" << endl;
									cout << "Enter FlightCode : ";
									cin >> flightCode;
									//interface->checkin();		
							}
							case 5 :{
									cout << endl;
									cout << "======== Cancel Flight ========" << endl;
									cout << "Enter FlightCode : ";
									cin >> flightCode;
									//interface->cancelTicketld();
							}
							case 6 : goto MainMenu;
							default : goto Employee;
						}
					goto MainMenu;
				}//Employee
				case 3 :{
					return 0;
					delete interface;
				}//Exit
				default : goto MainMenu;
			}//switch Pre-Main Menu
	}while(true);	
	return 0;
}
