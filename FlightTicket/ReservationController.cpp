#include "ReservationController.h"

void ReservationController::Register(string firstname,string lastname,string passportId,string username,string password){
	Customer *test = new Customer();
	test->saveRegister(firstname,lastname,passportId,username,password);
}
