#include "Seat.h"

void Seat::showSeat(string flightCode){
	int i = 1;
	string filein,p;
	ifstream data;
	string flight,s[10];
	data.open("DataBased\\seat.txt",ios::in);
	while(getline(data,filein)){
		flight = filein.substr(0,filein.find(','));
		   	filein.erase(0,filein.find(',')+1);
		s[0] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);	
		s[1] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);	
		s[2] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);	
		s[3] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);	
		s[4] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);
		s[5] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);
		s[6] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);
		s[7] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);
		s[8] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);
		s[9] = filein.substr(0,filein.find(','));
			filein.erase(0,filein.find(',')+1);
		if(flightCode == flight){
			cout << "=========== " << flightCode << " ===========" << endl;
			for(int i=0;i<10;i++){
				cout  <<setw(3)<< i+1 << "     "<< s[i] << endl;
			}
		}
	}	
}
Seat Seat::reserveSeat(string Id,string flightCode){
	int id;
	stringstream ss;
	ss << Id;
	ss >> id; 
	ss.clear();
	string s[10];
	Seat se;
	ifstream readFile;
	string str;
	readFile.open("DataBased\\seat.txt",ios::in);
	int k=0;
	while(getline(readFile,str)){
		k++;
	}
	readFile.close();
	string flight[k],filein,s1[k],s2[k],s3[k],s4[k],s5[k],s6[k],s7[k],s8[k],s9[k],s10[k];
	int i=0;
	readFile.open("DataBased\\seat.txt",ios::in);
	while(getline(readFile,filein)){
		flight[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s1[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s2[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s3[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s4[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s5[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s6[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s7[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s8[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s9[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s10[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		i++;
	}
	readFile.close();
	for(int i=0;i<k;i++){
		if(flight[i]== flightCode){
			if(1 == id){
				s1[i]= "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(2 == id){
				s2[i]= "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(3 == id){
				s3[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(4 == id){
				s4[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(5 == id){
				s5[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(6 == id){
				s6[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(7 == id){
				s7[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(8 == id){
				s8[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(9 == id){
				s9[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}else if(10 == id){
				s10[i] = "Reserved";
				se.seatId = Id;
				se.status = "Reserved";
			}
		}
	}
	ofstream writeFile;
	writeFile.open("DataBased\\seat.txt",ios::out);
	for(int i=0;i<k;i++){
		writeFile <<flight[i]<<","<<s1[i]<<","<<s2[i]<<","<<s3[i]<<","<<s4[i]<<","<<s5[i]<<",";
		writeFile <<s6[i]<<","<<s7[i]<<","<<s8[i]<<","<<s9[i]<<","<<s10[i]<<","<<endl;
		}	
	writeFile.close();
	return se;
}
void Seat::changeStatusCancel(string flightCode,string id){
	ifstream readFile;
	string str;
	readFile.open("DataBased\\seat.txt",ios::in);
	int k=0;
	while(getline(readFile,str)){
		k++;
	}
	readFile.close();
	string flight[k],filein,s1[k],s2[k],s3[k],s4[k],s5[k],s6[k],s7[k],s8[k],s9[k],s10[k];
	int i=0;
	readFile.open("DataBased\\seat.txt",ios::in);
	while(getline(readFile,filein)){
		flight[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s1[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s2[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s3[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s4[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s5[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s6[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s7[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s8[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s9[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s10[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		i++;
	}
	readFile.close();
	for(int i=0;i<k;i++){
		if(flight[i]== flightCode){
			if("1" == id){
				s1[i]= "avalable";
			}else if("2" == id){
				s2[i]= "avalable";
			}else if("3" == id){
				s3[i]= "avalable";
			}else if("4" == id){
				s4[i]= "avalable";
			}else if("5" == id){
				s5[i]= "avalable";
			}else if("6" == id){
				s6[i]= "avalable";
			}else if("7" == id){
				s7[i]= "avalable";
			}else if("8" == id){
				s8[i]= "avalable";
			}else if("9" == id){
				s9[i]= "avalable";
			}else if("10" == id){
				s10[i]= "avalable";
			}
		}
	}
	ofstream writeFile;
	writeFile.open("DataBased\\seat.txt",ios::out);
	for(int i=0;i<k;i++){
		writeFile <<flight[i]<<","<<s1[i]<<","<<s2[i]<<","<<s3[i]<<","<<s4[i]<<","<<s5[i]<<",";
		writeFile <<s6[i]<<","<<s7[i]<<","<<s8[i]<<","<<s9[i]<<","<<s10[i]<<","<<endl;
		}	
	writeFile.close();

}
void Seat::changeStatusCheckin(string flightCode,string id){
	
	ifstream readFile;
	string str;
	readFile.open("DataBased\\seat.txt",ios::in);
	int k=0;
	while(getline(readFile,str)){
		k++;
	}
	readFile.close();
	string flight[k],filein,s1[k],s2[k],s3[k],s4[k],s5[k],s6[k],s7[k],s8[k],s9[k],s10[k];
	int i=0;
	readFile.open("DataBased\\seat.txt",ios::in);
	while(getline(readFile,filein)){
		flight[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s1[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s2[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s3[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s4[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s5[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s6[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s7[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s8[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s9[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s10[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		i++;
	}
	readFile.close();
	for(int i=0;i<k;i++){
		if(flight[i]== flightCode){
			if("1" == id){
				s1[i]= "not avalable";
			}else if("2" == id){
				s2[i]= "not avalable";
			}else if("3" == id){
				s3[i]= "not avalable";
			}else if("4" == id){
				s4[i]= "not avalable";
			}else if("5" == id){
				s5[i]= "not avalable";
			}else if("6" == id){
				s6[i]= "not avalable";
			}else if("7" == id){
				s7[i]= "not avalable";
			}else if("8" == id){
				s8[i]= "not avalable";
			}else if("9" == id){
				s9[i]= "not avalable";
			}else if("10" == id){
				s10[i]= "not avalable";
			}
		}
	}
	ofstream writeFile;
	writeFile.open("DataBased\\seat.txt",ios::out);
	for(int i=0;i<k;i++){
		writeFile <<flight[i]<<","<<s1[i]<<","<<s2[i]<<","<<s3[i]<<","<<s4[i]<<","<<s5[i]<<",";
		writeFile <<s6[i]<<","<<s7[i]<<","<<s8[i]<<","<<s9[i]<<","<<s10[i]<<","<<endl;
		}	
	writeFile.close();

}
string Seat::getseatId(){
	return seatId;
}
string Seat::getstatus(){
	return status;
}
void Seat::addseat(string flightCode){
	ofstream writeFile;
	writeFile.open("DataBased\\seat.txt",ios::app);
	writeFile << flightCode <<","<< "avalable"<<","<<"avalable"<<","<<"avalable"<<","<<"avalable"<<","<<"avalable"<<",";
	writeFile <<"avalable"<<","<<"avalable"<<","<<"avalable"<<","<<"avalable"<<","<<"avalable"<<","<<endl;
	writeFile.close();
}

bool Seat::checkseat(string flightCode,string seatid){
	ifstream readFile;
	string str;
	readFile.open("DataBased\\seat.txt",ios::in);
	int k=0;
	while(getline(readFile,str)){
		k++;
	}
	readFile.close();
	string flight[k],filein,s1[k],s2[k],s3[k],s4[k],s5[k],s6[k],s7[k],s8[k],s9[k],s10[k];
	int i=0;
	readFile.open("DataBased\\seat.txt",ios::in);
	while(getline(readFile,filein)){
		flight[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s1[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s2[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s3[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s4[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s5[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s6[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s7[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s8[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s9[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		s10[i] = filein.substr(0,filein.find(','));
		filein.erase(0,filein.find(',')+1);
		i++;
	}
	readFile.close();
	for(int i=0;i<k;i++){
		if(flight[i]== flightCode){
			if("1" == seatid){
				if(s1[i] == "Reserved")
					return false;
			}else if("2" == seatid){
				if(s2[i] == "Reserved")
					return false;
			}else if("3" == seatid){
				if(s3[i] == "Reserved")
					return false;
			}else if("4" == seatid){
				if(s4[i] == "Reserved")
					return false;
			}else if("5" == seatid){
				if(s5[i] == "Reserved")
					return false;
			}else if("6" == seatid){
				if(s6[i] == "Reserved")
					return false;
			}else if("7" == seatid){
				if(s7[i] == "Reserved")
					return false;
			}else if("8" == seatid){
				if(s8[i] == "Reserved")
					return false;
			}else if("9" == seatid){
				if(s9[i] == "Reserved")
					return false;
			}else if("10" == seatid){
				if(s10[i] == "Reserved")
					return false;
			}
		}
	}
	return true;
}
