#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"FlightTicket.h"

class Customer
{	
	private:
		string firstname;
		string lastname;
		string passportId;
		string username;
		string password;
	public:
		void saveRegister(string firstname,string lastname,string passportId,string username,string password);
		bool checkLogin(string username,string password);
		Customer getCustomerInformasion();
};

#endif
