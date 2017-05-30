

#ifndef TDATABASE_H_
#define TDATABASE_H_

#include <vector>
#include "TOrder.h"
#include "TVehicle.h"
#include "TDriver.h"
#include <memory>
#include <cstdlib>


class TPark {

private:
	std::vector<TOrder> * orders;
	std::vector<TVehicle> * vehicles;
	std::vector<TDriver> * drivers;
public:
	TPark();

	virtual ~TPark();

	TOrder& findOrderByUUID(unsigned int uuid);
	std::vector<TOrder> findOrdersByPassenger(TPassenger * passenger);
	std::vector<TOrder> findOrdersByDriver(TDriver * driver);
	std::vector<TOrder> findOrdersByVehicle(TVehicle * vehicle);
	std::vector<TOrder> getAllOrders();
	//������� ������, ���������� ������� ���������� � ���������� ����� a � b
	std::vector<TOrder> findOrdersByStartTime(TTime * a, TTime * b);
	//������� ������, ���������� ������� ������������� � ���������� ����� a � b
	std::vector<TOrder> findOrdersByFinishTime(TTime * a, TTime * b);
	//������� ������, ���������� ������� ���������� � ���������� ����� a � b
	std::vector<TOrder> findOrdersByTime(TTime * a, TTime * b);

	std::vector<TDriver> findDriversByType(std::string& type);
	std::vector<TVehicle> findVehiclesByType(std::string& type);

	bool isBusy(TVehicle * vehicle, TTime * a, TTime * b);
	bool isBusy(TDriver * driver, TTime * a, TTime * b);



	TVehicle * findFreeVehicle(std::string& type, TTime * start, TTime * finish);
	TDriver * findFreeDriver(std::string& type, TTime * start, TTime * finish);
	bool addOrder(TPassenger * passenger, TTime * start, TTime * finish);
	bool addVehicle(TVehicle& vehicle) { vehicles->push_back(vehicle); return true; }
	bool addDriver(TDriver& driver) { drivers->push_back(driver); return true; };
	bool removeOrder(TOrder * order);
	bool removeOrder(unsigned int uuid);



};



#endif /* TDATABASE_H_ */
