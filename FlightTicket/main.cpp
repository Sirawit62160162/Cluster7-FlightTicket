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
 cout << "						---------------------------" << endl;
 cout << "						- Press Enter to Continue -" << endl;
 cout << "						---------------------------";
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
	//do{
		MainMenu :
			system("cls");
				char readA[25] = "DataBased\\mainmenu.txt";
 				outputMenu(readA);
 				cout<<endl;
		//	cout << "						===== Reservation Fight Ticket =====" << endl;
			cout << "								1. Customer" << endl;
			cout << "								2. Employee" << endl;
			cout << "								3. Exit" << endl;
			cout << "						====================================" << endl;
			cout << "								Choose Menu : ";
			cin >> choose;
			switch(choose){
				case 1 :{
							Customer :
								cout << endl; 
								checkcustomer = 1;
								system("cls");
									char readA[25] = "DataBased\\customer.txt";
 									outputMenu(readA);
 									cout<<endl;
							//	cout << "						===== Customer =====" << endl;
								cout << "								1. Login" << endl;
								cout << "								2. Register" << endl;
								cout << "								3. Back" << endl;
								cout << "								====================" << endl;
								cout << "								Choose Menu : ";
								cin >> choose;
								switch(choose){
									case 1 :{
												system("cls");
												char readA[25] = "DataBased\\login.txt";
 												outputMenu(readA);
										cout << endl;
									//	cout << "======= Login =======" << endl;
										cout << "						Enter Username : ";
										cin >> username;
										cout << "						Enter Password : ";
										cin >> password; 								
										if(interface->login(username,password) == true){
											cout<<endl;
											cout << "					** Login Success **" << endl;
											enter();
											showFlightCustomer:
											system("cls");
											interface->showFlight();
											cout << endl;
											cout << "					Enter FlightCode : ";
											cin >> flightCode;
											system("cls");
											if(interface->reserveTicket(flightCode) == 0){
												goto showFlightCustomer;
											}
											cout << "					Enter : ";
											cin >> numseat;
											if(interface->reserveSeat(numseat,flightCode,checkcustomer)==0){
												cout<<endl;
												cout << "				Seat not avalable" << endl;
												enter();
												goto showFlightCustomer;
											}else{
												enter();
												goto Customer;
											}
										}else{
											cout<<endl;
											cout << "						** Login Failed **" << endl;
											enter();
											goto Customer;
										}
										break;
									}//Login
									case 2 :{
												system("cls");
												char readA[25] = "DataBased\\register.txt";
 												outputMenu(readA);
										cout << endl;
									//	cout << "					======== Register ========" << endl;
										cout << "					Enter Firstname : ";
										cin >> firstName;
										cout << "					Enter Lastname : ";
										cin >> lastName;
										cout << "					Enter PassportID : ";
										cin >> ppId;
										cout << "					Enter Username : ";
										cin >> username;
										cout << "					Enter Password : ";
										cin >> password; 		
										if(interface->Register(firstName,lastName,ppId,username,password) == 0){
											cout<<endl;
											cout << "				** Register Failed **" << endl;
										}else{
											interface->Register(firstName,lastName,ppId,username,password);
											cout<<endl;
											cout << "				** Register Success **" << endl;
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
						char readA[25] = "DataBased\\Employee.txt";
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
								cout << "Enter FlightCode : ";
								cin >> flightCode;
								system("cls");
								if(interface->reserveTicket(flightCode) == 0){
									goto showFlightEmployee;
								}
								cout << "Enter : ";
								cin >> numseat;
								if(interface->reserveSeat(numseat,flightCode,checkcustomer)==0){
									cout << "Seat not avalable" << endl;
									enter();
									goto showFlightEmployee;
									
								}else{
									interface->reserveSeat(numseat,flightCode,checkcustomer);
								}
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
							//	}
							}
							case 2 :{
								system("cls");
								interface->showCustomer();
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
				
											if(interface->deleteFlight(flightCode) == true){
												cout << "** Deleter Flight Success **" << endl;
												enter();
											}else{
												cout << "** Login Failed **" << endl;
												enter();
												goto ShowFlight;
											}
										}//Delete Flight
										case 3 : goto Employee;
										default : goto ShowFlight; 
									}
							}//Show Flight
							case 4 :{
									cout << endl;
									cout << "======== Check-In Flight ========" << endl;
									cout << "Enter FlightCode : ";
									cin >> ticketcode;
									if(interface->checkin(ticketcode)==0){
										cout << "** Checkin failed **" << endl;
										enter();
										goto Employee;
									}else{
										interface->checkin(ticketcode);
										cout << "** Checkin Success **" << endl;
										enter();
										goto Employee;
									}
									break;
							}
							case 5 :{
									cout << endl;
									cout << "======== Cancel Flight ========" << endl;
									cout << "Enter FlightCode : ";
									cin >> ticketcode;
									if(interface->cancelTicketId(ticketcode)== 0){
										cout << "** Cancel failed **" << endl;
										enter();
										goto Employee;
									}else{
										interface->cancelTicketId(ticketcode);
										cout << "** Cancel Success **" << endl;
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
	//}while(true);	
	return 0;
}
