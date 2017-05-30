#include "TOrder.h"

TOrder::TOrder(TDriver * driver, TVehicle * vehicle, TPassenger * passenger,
	TTime * start, TTime * finish, unsigned int uuid) {
	// TODO Auto-generated constructor stub
	if (!start || !finish || !driver || !vehicle || !passenger) {
		throw new std::string("��� �������� ������� ���������\n");
	}
	if (driver->getClass() != vehicle->getClass()) {
		throw new std::string(
			"� �������� ��� ���� ��� �������� ������� ����������\n");
	}
	if (vehicle->getClass() != passenger->getClass()) {
		throw new std::string("����� ��������� ������ ������ � ����� ������\n");
	}
	if (start > finish) {
		throw new std::string(
			"���� ������ ����� ������������� � ������������, �� �� �� �������\n");
	}
	_vehicle = vehicle;
	_driver = driver;
	_passenger = passenger;
	_start = start;
	_finish = finish;
	_uuid = uuid;
#ifdef DEBUG
	std::cout << "����� ������� �����������";
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
	if (!driver || !_driver) {
#ifdef DEBUG
		std::cout << "������� ������� ���������\n";
#endif
		return false;
	}
	if (driver->getClass() != _driver->getClass()) {
		return false;
	}
	return true;

}
bool TOrder::changeVehicle(TVehicle * vehicle) {
	if (!vehicle || !_vehicle) {
#ifdef DEBUG
		std::cout << "������� ������� ���������\n";
#endif
		return false;
	}
	if (vehicle->getClass() != vehicle->getClass()) {
		return false;
	}
	return true;
}
unsigned int TOrder::getUUID() {
	return _uuid;
}

TOrder::~TOrder() {

	// TODO Auto-generated destructor stub
}

