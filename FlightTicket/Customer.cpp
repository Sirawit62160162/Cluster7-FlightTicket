#include "Customer.h"

void Customer::saveRegister(string firstname,string lastname,string passportId,string username,string password){
	ofstream regis;
	regis.open("DataBased\\CustomerData",ios::app);
	regis << firstname << "," << lastname << "," << passportId << "," << username << "," << password << endl;
	regis.close();
}
