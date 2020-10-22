#include "Customer.h"

void Customer::saveRegister(string firstname,string lastname,string passportId,string username,string password){
	ofstream writeFile;
	writeFile.open("DataBased\\CustomerData.txt",ios::app);
	writeFile << firstname << "," << lastname << "," << passportId << "," << username << "," << password << endl;
	writeFile.close();
}

bool Customer::checkLogin(string username,string password){
	ifstream readFile;
	readFile.open("DataBased\\CustomerData.txt",ios::in);
	string str,fname,lname,ppId,user,pass;
	while(getline(readFile,str)){
		fname = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		lname = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		ppId = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		user = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		pass = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		
		if(username == user && password == pass)
			return 1;
	}
	return 0;
}

Customer Customer::getCustomerInformasion(string u,string p){
	Customer c;
	ifstream readFile;
	readFile.open("DataBased\\CustomerData.txt",ios::in);
	string str,fname,lname,ppId,user,pass;
	while(getline(readFile,str)){
		fname = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		lname = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		ppId = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		user = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		pass = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		if(u == user && p == pass){
			c.firstname = fname;
			c.lastname = lname;
			c.passportId = ppId;
			c.username = user;
			c.password = pass;
			return c;
		}
	}
}
string Customer::getFirstname(){
	return firstname;
}
string Customer::getLastname(){
	return lastname;	
}
string Customer::getPassportId(){
	return passportId;
}
void Customer::setReserveName(string f,string l,string p){
	firstname = f;
	lastname = l;
	passportId = p;
}
