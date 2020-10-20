#include "Flight.h"
Flight Flight::reserveTicket(string flightCode){
	
	
}
void Flight::getSeat(string flightCode){
	
}
void Flight::getFlight(){
	ifstream showFlight;
	showFlight.open("DataBased\\FlightData.txt",ios::in);
	string str,st,des,dep,arr,p,code;
	int num = 1;
	cout << endl;
	cout << "==================================================== Flight Available ====================================================" << endl;
	cout << setw(10) << setfill(' ') << left << "No." 
	<< setw(10) << setfill(' ') << left << "Start" 
	<< setw(15) << setfill(' ') << left << "Destination"   
	<< setw(20) << setfill(' ') << left << "DepartureTime" 
	<< setw(20) << setfill(' ') << left << "ArriveTime" 
	<< setw(20) << setfill(' ') << left << "Price"    
	<< setw(15) << setfill(' ') << left << "FlightCode" << endl;  
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	while(getline(showFlight,str)){
		stringstream ss;
		ss << num;
		
		st = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		des = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		dep = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		arr = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		p = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		code = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		
		/*show*/
		cout << setw(10) << setfill(' ') << left << ss.str()+"."  
		<< setw(10) << setfill(' ') << left << st 
		<< setw(15) << setfill(' ') << left << des  
		<< setw(20) << setfill(' ') << left << dep 
		<< setw(20) << setfill(' ') << left << arr 
		<< setw(20) << setfill(' ') << left << p      
		<< setw(15) << setfill(' ') << left << code << endl;  
		
		num ++;
	}
	cout << "==========================================================================================================================" << endl;
}
void Flight::removeFlight(string flightCode){
	ifstream readFile;
	string str;
	readFile.open("DataBased\\FlightData.txt",ios::in);
	int k=0;
	while(getline(readFile,str)){
		k++;
	}
	readFile.close();
	string st[k],des[k],dep[k],arr[k],p[k],code[k];
	int i=0;
	
	readFile.open("DataBased\\FlightData.txt",ios::in);
	while(getline(readFile,str)){
		st[i] = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		des[i] = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		dep[i] = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		arr[i] = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		p[i] = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		code[i] = str.substr(0,str.find(','));
		str.erase(0,str.find(',')+1);
		i++;
	}
	readFile.close();
	
	ofstream writeFile;
	writeFile.open("DataBased\\FlightData.txt",ios::out);
	for(int i=0;i<k;i++){
		cout << st[i] << " " << des[i] << " " << dep[i] << " " << arr[i] << " " << p[i] << " " << code[i] << endl;
		if(code[i] == flightCode){
			continue;
		}else{
			writeFile << st[i] << "," << des[i] << "," << dep[i] << "," << arr[i] << "," << p[i] << "," << code[i] << endl;
		}
	}
	writeFile.close();
}
void Flight::addFlight(string start,string destination,string departureTime,string arriveTime,double price,string flightCode){
	ofstream addFlight;
	addFlight.open("DataBased\\FlightData.txt",ios::app);
	addFlight << start << "," << destination << "," << departureTime << "," << arriveTime << "," << price << "," << flightCode << endl;
	addFlight.close();
}

