#include "Customer.h"

void Customer::saveRegister(string firstname,string lastname,string passportId,string username,string password){
	ofstream writeFile;
	writeFile.open("DataBased\\CustomerData.txt",ios::app);
	writeFile << firstname << "," << lastname << "," << passportId << "," << username << "," << password << endl;
	writeFile.close();
}

bool Customer::checkLogin(string username,string password){
<<<<<<< HEAD
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
=======
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
>>>>>>> 7adaa883c8ca5164ddc77a97c85a8e8ce878e67d
}

Customer Customer::getCustomerInformasion(){
	
}
