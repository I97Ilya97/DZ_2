

#include "TVehicle.h"

TVehicle::~TVehicle() {

}

std::string& TVehicleHeavy::getClass() {
	static std::string retval("Heavy");
	return retval;
}


