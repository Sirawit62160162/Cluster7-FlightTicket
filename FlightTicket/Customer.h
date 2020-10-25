#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<cmath>
using namespace std;

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
		Customer getCustomerInformasion(string username,string pass);
		string getFirstname();
		string getLastname();
		string getPassportId();
		void setReserveName(string f,string l,string p);
		bool checkRegister(string username,string password);
};

#endif
