#include "FlightTicket.h"
#include "UI.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int choose;
	int check;
	string firstName,lastName,ppId,username,password;
	UI *interface = new UI();
	//do{
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
							system("cls");
								cout << "===== Customer =====" << endl;
								cout << "1. Login" << endl;
								cout << "2. Register" << endl;
								cout << "3. Back" << endl;
								cout << "====================" << endl;
								cout << "Choose Menu : ";
								cin >> choose;
								switch(choose){
									case 1 :{
										cout << "Enter Username : ";
										cin >> username;
										cout << "Enter Password : ";
										cin >> password; 
										check = interface->login(username,password);
										if(check == 1){
											cout << "==================" << endl;
											cout << " Login Success" << endl;
										}else{
											cout << "==================" << endl;
											cout << " Login Fail" << endl;
										}
										break;
									}//Login
									case 2 :{
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
										interface->Register(firstName,lastName,ppId,username,password);
										goto Customer;
										break;
									}//Register
									case 3 : //goto MainMenu;
											break; 
									default : //goto Customer;
											break;
								}//Customer
				}//Customer
				case 2 :{
					break;
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
