#include "Customer.h"

void Customer::saveRegister(string firstname,string lastname,string passportId,string username,string password){
	ofstream regis;
	regis.open("DataBased\\CustomerData",ios::app);
	regis << firstname << "," << lastname << "," << passportId << "," << username << "," << password << endl;
	regis.close();
}

bool Customer::checkLogin(string username,string password){
		string f,l,p,u,pass;
		string filein;
		ifstream data;
		data.open("DataBased\\CustomerData",ios::in);
		while (getline(data,filein)){
			f = filein.substr(0,filein.find(','));
	   			filein.erase(0,filein.find(',')+1);
			l = filein.substr(0,filein.find(','));	
				filein.erase(0,filein.find(',')+1);	
			p = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);	
			u = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);	
			pass = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);	
			if(u == username && pass == password){
				return true;
			}
		}
			return false;
}

Customer Customer::getCustomerInformasion(){
	
}
