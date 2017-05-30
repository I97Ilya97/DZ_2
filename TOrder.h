

#ifndef TORDER_H_
#define TORDER_H_

#include <exception>
#include "TTime.h"
#include "TDriver.h"
#include "TPassenger.h"
#include "TVehicle.h"

class TOrder {
public:
	using value_type = TOrder;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = std::vector<value_type>::iterator;
	using const_iterator = std::vector<value_type>::const_iterator;


private:
	//using _Base = std::vector<value_type>::_Base;

	TVehicle * _vehicle;
	TDriver * _driver;
	TPassenger * _passenger;
	TTime * _start, *_finish;
	unsigned int _uuid;
public:
	TOrder(TDriver * driver, TVehicle * vehicle, TPassenger * passenger,
		TTime * start, TTime * finish, unsigned int uuid);
	TDriver * getDriver();
	TPassenger * getPassenger();
	TVehicle * getVehicle();
	TTime * getStartTime();
	TTime * getFinishtime();
	unsigned int getUUID();


	bool changeDriver(TDriver * driver);
	bool changeVehicle(TVehicle * vehicle);

	virtual ~TOrder();
};

#endif /* TORDER_H_ */
