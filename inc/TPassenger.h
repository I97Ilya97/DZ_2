

#ifndef TPASSENGER_H_
#define TPASSENGER_H_
#include <string>

#include <exception>
#include <vector>


class TPassenger {
public:
	TPassenger();
	//virtual ~TPassenger();
	virtual std::string& getClass();


};

//Military, Simple, Heavy
class TPassengerHeavy: TPassenger{
	std::string& getClass();
};

#endif /* TPASSENGER_H_ */
