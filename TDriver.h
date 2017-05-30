

#ifndef TDRIVER_H_
#define TDRIVER_H_

#include "TVehicle.h"

class TDriver {
public:
	TDriver() = default;
	//virtual ~TDriver();

	virtual std::string& getClass() {
		static std::string retval("");
		return retval;
	}
	virtual ~TDriver();

};

class TDriverHeavy : TDriver {
	std::string& getClass();
};

#endif /* TDRIVER_H_ */
