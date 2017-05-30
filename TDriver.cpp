#include "TDriver.h"


TDriver::~TDriver() {

}
std::string& TDriverHeavy::getClass() {
	static std::string retval("Heavy");
	return retval;
}
