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
#include<conio.h>
using namespace std;
void enter(){
 cout << endl;
 cout << "---------------------------" << endl;
 cout << "- Press Enter to Continue -" << endl;
 cout << "---------------------------" << endl;
 getch();
}
void outputMenu(char read[]){
 ifstream menu;
 menu.open(read);
 string line = " ";//Read string from file
 while(getline(menu,line)){
  cout << line << endl;
 }
}//Read Menu from file
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int choose;
	int check;
	int checkcustomer;
	string ticketcode;
	string firstName,lastName,ppId,username,password;
	string start,destination,departTime,arriveTime,flightCode;
	string numseat;
	double price;
	UI *interface = new UI();
	
	char readB[25] = "ASCII\\plan.txt";
	outputMenu(readB);
	enter();
	
	do{
		MainMenu :
			system("cls");
				char readA[25] = "ASCII\\role.txt";
 				outputMenu(readA);
 				cout<<endl;
		    cout << "============== Role ================" << endl;
			cout << "1. Customer" << endl;
			cout << "2. Employee" << endl;
			cout << "3. Exit" << endl;
			cout << "====================================" << endl;
			cout << "Choose Role : ";
			cin >> choose;
			switch(choose){
				case 1 :{
							Customer :
								cout << endl; 
								checkcustomer = 1;
								system("cls");
									char readA[25] = "ASCII\\role_customer.txt";
 									outputMenu(readA);
 									cout<<endl;
								cout << "===== Customer =====" << endl;
								cout << "1. Login" << endl;
								cout << "2. Register" << endl;
								cout << "3. Back" << endl;
								cout << "====================" << endl;
								cout << "Choose Menu : ";
								cin >> choose;
								switch(choose){
									case 1 :{
												system("cls");
												char readA[25] = "ASCII\\login.txt";
 												outputMenu(readA);
												cout << endl;
												cout << "======= Login =======" << endl;
												cout << "Enter Username : ";
												cin >> username;
												cout << "Enter Password : ";
												cin >> password; 			
												cout << "=====================" << endl; 				
												if(interface->login(username,password) == true){
													cout << endl;
													cout << "** Login status : Success" << endl;
													cout << "-> Welcome..." << endl;
													enter();
													showFlightCustomer:
													system("cls");
													interface->showFlight();
													cout << endl;
													cout << "=========== Menu ==========" << endl;
													cout << "1. Researve Flight Ticket" << endl;
													cout << "2. Logout" << endl	;
													cout << "===========================" << endl;
													cout << "Choose Menu : ";
													cin >> choose;
													switch(choose){
														case 1 :{	
																	system("cls");
																	interface->showFlight();
																	cout << endl;
																	cout << "======= Researve Flight Ticket =======" << endl;
																	cout << "Enter FlightCode : ";
																	cin >> flightCode;
																	do{
																	system("cls");
																	if(interface->reserveTicket(flightCode,checkcustomer) == 0){
																		goto showFlightCustomer;
																	}
																	cout << endl;
																	cout << "========== Choose Seat ===========" << endl;
												     				cout << "Enter Seat No. : ";
																	cin >> numseat;
																	}while(numseat<"1"||numseat>"10");
																	if(interface->reserveSeat(numseat,flightCode,checkcustomer)==0){
																	cout<<endl;
																	cout << "-> Seat not available." << endl;
																	enter();
																	goto showFlightCustomer;
																    }
																    enter();
																    goto showFlightCustomer;
																}
														case 2 :{
																	cout << endl;
																	cout << "** Logout Success -> Login&Register **" << endl;
																	enter();
																	goto Customer;
																}
													default : goto showFlightCustomer;
													}	
												}else{
															cout << endl;
														cout << "** Login status : Faild" << endl;
														cout << "-> Not found username or password in the system." << endl;
														enter();
														goto Customer;
											}
									}//Login
									case 2 :{
										system("cls");
										char readA[25] = "ASCII\\register.txt";
 										outputMenu(readA);
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
										cout << "==========================" << endl; 		
										if(interface->Register(firstName,lastName,ppId,username,password) == 0){
											cout << endl;		
											cout << "** Register status : Failed" << endl;
											cout << "-> Found username and password in system." << endl;
											enter();
										}else{
											interface->Register(firstName,lastName,ppId,username,password);
											cout << endl;		
											cout << "** Register status : Success" << endl;
											cout << "-> enjoy..." << endl;
											enter();
										}
										goto Customer;
										break;
									}//Register
									case 3 : 
											goto MainMenu;
											break; 
									default : 
											goto Customer;
											break;
								}//Customer
				}//Customer
				case 2 :{
					Employee :
						system("cls"); 
						char readA[25] = "ASCII\\role_employee.txt";
 						outputMenu(readA);
						cout << endl;
						checkcustomer = 2;
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
								showFlightEmployee:
								system("cls");
								interface->showFlight();
								cout << endl;
								cout << "=========== Menu ==========" << endl;
								cout << "1. Researve Flight Ticket" << endl;
								cout << "2. Logout" << endl	;
								cout << "===========================" << endl;
								cout << "Choose Menu : ";
								cin >> choose;
								switch(choose){
										case 1 :{	
											cout << endl;
											cout << "======= Researve Flight Ticket =======" << endl;
											cout << "Enter FlightCode : ";
											cin >> flightCode;
											do{
												system("cls");
												if(interface->reserveTicket(flightCode,checkcustomer) == 0){
													goto showFlightEmployee;
												}
												cout << "========== Choose Seat ===========" << endl;
												cout << "Enter Seat No. : ";
	
												cin >> numseat;
											}while(numseat<"1"||numseat>"10");
											if(interface->reserveSeat(numseat,flightCode,checkcustomer)==0){
												cout << "Seat not avalable" << endl;
												enter();
												goto showFlightEmployee;
											}else{
												interface->reserveSeat(numseat,flightCode,checkcustomer);
											}
											system("cls");
											char readA[35] = "ASCII\\Customer information.txt";
 											outputMenu(readA);
											cout << "Enter Firstname : ";
											cin >> firstName;
											cout << "Enter Lastname : ";
											cin >> lastName;
											cout << "Enter PassprotId : ";
											cin >> ppId;
											interface->reserveTicketName(firstName,lastName,ppId);
											enter();
											goto Employee;
											break;
										}
										case 2:{
											goto Employee;
											break;
										}
										default : goto showFlightEmployee;
								}				
							}
							case 2 :{
								system("cls");
								interface->showCustomer();
								enter();
								goto Employee;
							}
							case 3 :{
								ShowFlight :
									system("cls");
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
											
											if(interface->addFlight(start,destination,departTime,arriveTime,price,flightCode) == true){
												cout << "** Add Flight Success **" << endl;
												enter();
												goto ShowFlight;
											}
										}
										//Add Flight
										case 2 :{
											cout << endl;
											cout << "======== Delete Flight ========" << endl;
											cout << "Enter FlightCode : ";
											cin >> flightCode;
				
											if(interface->deleteFlight(flightCode) == 1){
												cout << "** Delete Flight Success **" << endl;
												enter();
											}else{
												cout << "** Delete Failed **" << endl;
												enter();
												goto ShowFlight;
											}
										}//Delete Flight
										case 3 : goto Employee;
										default : goto ShowFlight; 
									}
							}//Show Flight
							case 4 :{
									system("cls");
									char readA[30] = "ASCII\\Employee Check-in.txt";
 									outputMenu(readA);
									cout << endl;
									cout << "======== Check-In Flight ========" << endl;
									cout << "Enter TicketID : ";
									cin >> ticketcode;
									if(interface->checkin(ticketcode)==0){
										system("cls");
										char readA[30] = "ASCII\\checkin fail.txt";
 										outputMenu(readA);
										enter();
										goto Employee;
									}else{
										interface->checkin(ticketcode);
										system("cls");
										char readA[30] = "ASCII\\checkin success.txt";
 										outputMenu(readA);
										enter();
										goto Employee;
									}
									break;
							}
							case 5 :{
									system("cls");
									char readA[30] = "ASCII\\Employee cancel.txt";
 									outputMenu(readA);
									cout << endl;
									cout << "======== Cancel Flight ========" << endl;
									cout << "Enter TicketID : ";
									cin >> ticketcode;
									if(interface->cancelTicketId(ticketcode)== 0){
										system("cls");
										char readA[30] = "ASCII\\cancel fail.txt";
 										outputMenu(readA);
										enter();
										goto Employee;
									}else{
										interface->cancelTicketId(ticketcode);
										system("cls");
										char readA[30] = "ASCII\\cancel success.txt";
 										outputMenu(readA);
										enter();
										goto Employee;
									}
									break;
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
