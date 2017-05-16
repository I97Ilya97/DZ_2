

#include "TPassenger.h"
/*
TPassenger::TPassenger() {
	// TODO Auto-generated constructor stub
}
TPassenger::~TPassenger() {
	// TODO Auto-generated destructor stub
}
std::string& TPassenger::getClass(){
	return "Military";//Military, Simple, Heavy
}
*/

std::string& TPassengerHeavy::getClass(){
	static std::string retval("Heavy");
	return retval;
}
