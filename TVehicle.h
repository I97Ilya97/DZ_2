#ifndef TVEHICLE_H_
#define TVEHICLE_H_

#include <string>



class TVehicle {
public:

	TVehicle();

	virtual std::string& getClass() {
		static std::string retval("");
		return retval;
	}
	virtual ~TVehicle();


};

class TVehicleHeavy {
public:
	std::string& getClass();
};

#endif /* TVEHICLE_H_ */
