#include "UI.h"

void UI::Register(string firstname,string lastname,string passportId,string username,string password){
	ReservationController *test = new ReservationController();
	test->Register(firstname,lastname,passportId,username,password);
}
