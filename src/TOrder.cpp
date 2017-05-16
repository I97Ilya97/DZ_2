

#include "TOrder.h"

TOrder::TOrder(TDriver * driver, TVehicle * vehicle, TPassenger * passenger,
		TTime * start, TTime * finish, unsigned int uuid) {
	// TODO Auto-generated constructor stub
	if (!start || !finish || !driver || !vehicle || !passenger) {
		throw new std::string("Мне передали нулевой указатель\n");
	}
	if (driver->getClass() != vehicle->getClass()) {
		throw new std::string(
				"У водителя нет прав для вождения данного автомобиля\n");
	}
	if (vehicle->getClass() != passenger->getClass()) {
		throw new std::string("Этого пассажира нельзя возить в такой машине\n");
	}
	if (start > finish) {
		throw new std::string(
				"Наши машины умеют передвигаться в пространстве, но не во времени\n");
	}
	_vehicle = vehicle;
	_driver = driver;
	_passenger = passenger;
	_start = start;
	_finish = finish;
	_uuid = uuid;
#ifdef DEBUG
	std::cout<<"Заказ успешно сформирован";
#endif
}

TDriver * TOrder::getDriver() {
	return _driver;
}
TPassenger * TOrder::getPassenger() {
	return _passenger;
}
TVehicle * TOrder::getVehicle() {
	return _vehicle;
}
TTime * TOrder::getStartTime() {
	return _start;
}
TTime * TOrder::getFinishtime() {
	return _start;
}

bool TOrder::changeDriver(TDriver * driver) {
	if(!driver||!_driver){
#ifdef DEBUG
		std::cout<<"Передан нулевой указатель\n";
#endif
		return false;
	}
	if(driver->getClass()!=_driver->getClass()){
		return false;
	}
	return true;

}
bool TOrder::changeVehicle(TVehicle * vehicle) {
	if(!vehicle||!_vehicle){
#ifdef DEBUG
			std::cout<<"Передан нулевой указатель\n";
#endif
			return false;
		}
		if(vehicle->getClass()!=vehicle->getClass()){
			return false;
		}
		return true;
}
unsigned int TOrder::getUUID(){
	return _uuid;
}

TOrder::~TOrder() {

	// TODO Auto-generated destructor stub
}

