

#include "TPark.h"

TPark::TPark() {
	// TODO Auto-generated constructor stub
	orders = new std::vector<TOrder>();
	drivers = new std::vector<TDriver>();
	vehicles = new std::vector<TVehicle>();

}

TPark::~TPark() {
	// TODO Auto-generated destructor stub
	if (vehicles)
		delete (vehicles);
	vehicles = nullptr;
	if (orders)
		delete (orders);
	orders = nullptr;
	if (drivers)
		delete (drivers);
	drivers = nullptr;

}

TOrder& TPark::findOrderByUUID(unsigned int uuid) {
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	size_t cnt = (*orders).size();
	size_t i = 0;
	TOrder * retval = nullptr;
	while (i < cnt) {
		if ((*orders)[i].getUUID() == uuid)
			(*retval) = (*orders)[i];
		i++;
	}
	if (!retval) {
		throw new std::string("nothing found\n");
	}

	return *retval;
}
std::vector<TOrder> TPark::findOrdersByPassenger(TPassenger * passenger) {
	static std::vector<TOrder> retval;
	size_t i = 0;
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	if (!passenger)
		throw new std::string("Мне передали нулевой указатель\n");
	while (i < orders->size()) {
		if ((*orders)[i].getPassenger() == passenger) {
			retval.push_back((*orders)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}
std::vector<TOrder> TPark::findOrdersByDriver(TDriver * driver) {
	static std::vector<TOrder> retval;
	size_t i = 0;
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	if (!driver)
		throw new std::string("Мне передали нулевой указатель\n");
	while (i < orders->size()) {
		if ((*orders)[i].getDriver() == driver) {
			retval.push_back((*orders)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Ничего не могу найти\n");
	}
	return retval;
}
std::vector<TOrder> TPark::findOrdersByVehicle(TVehicle * vehicle) {
	static std::vector<TOrder> retval;
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	if (!vehicle)
		throw new std::string("Мне передали нулевой указатель\n");
	size_t i = 0;
	while (i < orders->size()) {
		if ((*orders)[i].getVehicle() == vehicle) {
			retval.push_back((*orders)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}
std::vector<TOrder> TPark::getAllOrders() {
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	return *orders;
}
//Находит заказы, выполнение которых начинается в промежутке между a и b
std::vector<TOrder> TPark::findOrdersByStartTime(TTime * a, TTime * b) {
	static std::vector<TOrder> retval;
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	if (!a || !b)
		throw new std::string("Мне передали нулевой указатель\n");
	size_t i = 0;
	while (i < orders->size()) {
		if ((*(*orders)[i].getStartTime() >= *a)
				&& (*(*orders)[i].getStartTime() <= *b)) {
			retval.push_back((*orders)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}
//Находит заказы, выполнение которых заканчивается в промежутке между a и b
std::vector<TOrder> TPark::findOrdersByFinishTime(TTime * a, TTime * b) {
	static std::vector<TOrder> retval;
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	if (!a || !b)
		throw new std::string("Мне передали нулевой указатель\n");
	size_t i = 0;
	while (i < orders->size()) {
		if ((*(*orders)[i].getStartTime() >= *a)
				&& (*(*orders)[i].getStartTime() <= *b)) {
			retval.push_back((*orders)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}
//Находит заказы, выполнение которых происходит в промежутке между a и b
std::vector<TOrder> TPark::findOrdersByTime(TTime * a, TTime * b) {
	static std::vector<TOrder> retval;
	if (!orders)
		throw new std::string("Почему-то у меня нет списка заказов...\n");
	if (!a || !b)
		throw new std::string("Мне передали нулевой указатель\n");
	size_t i = 0;
	while (i < orders->size()) {
		if ((*(*orders)[i].getStartTime() >= *a)
				&& (*(*orders)[i].getStartTime() <= *b)) {
			retval.push_back((*orders)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}

std::vector<TDriver> TPark::findDriversByType(std::string& type) {
	static std::vector<TDriver> retval;
	if (!drivers)
		throw new std::string("Почему-то у меня нет списка водителей...\n");
	size_t i = 0;
	while (i < drivers->size()) {
		if ((*drivers)[i].getClass() == type) {
			retval.push_back((*drivers)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}
std::vector<TVehicle> TPark::findVehiclesByType(std::string& type) {
	static std::vector<TVehicle> retval;
	if (!vehicles)
		throw new std::string("Почему-то у меня нет списка машин...\n");
	size_t i = 0;
	while (i < vehicles->size()) {
		if ((*vehicles)[i].getClass() == type) {
			retval.push_back((*vehicles)[i]);
		}
		i++;
	}
	if (!retval.size()) {
		throw new std::string("Nothing found\n");
	}
	return retval;
}

bool TPark::isBusy(TVehicle * vehicle, TTime * a, TTime * b) {
	std::vector<TOrder> _orders;
	bool retval = false;
	if (!vehicle || !a || !b)
		throw new std::string("Мне передали нулевой указатель\n");
	try {
		_orders = findOrdersByVehicle(vehicle);
	} catch (std::string& e) {
#ifdef DEBUG
		std::cout<<e;
#endif
	}
	size_t i = 0;
	while (i < _orders.size()) {
		if (((*_orders[i].getStartTime() >= *a)
				&& (*_orders[i].getStartTime() <= *b))
				|| ((*_orders[i].getFinishtime() >= *a)
						&& (*_orders[i].getFinishtime() <= *b))) {
			retval = true;
			break;
		}
		i++;
	}
	return retval;
}
bool TPark::isBusy(TDriver * driver, TTime * a, TTime * b) {
	std::vector<TOrder> _orders;
	bool retval = false;
	if (!driver || !a || !b)
		throw new std::string("Мне передали нулевой указатель\n");
	try {
		_orders = findOrdersByDriver(driver);
	} catch (std::string& e) {
#ifdef DEBUG
		std::cout<<e;
#endif
	}
	size_t i = 0;
	while (i < _orders.size()) {
		if (((*_orders[i].getStartTime() >= *a)
				&& (*_orders[i].getStartTime() <= *b))
				|| ((*_orders[i].getFinishtime() >= *a)
						&& (*_orders[i].getFinishtime() <= *b))) {
			retval = true;
			break;
		}
		i++;
	}
	return retval;
}

bool TPark::addOrder(TPassenger * passenger, TTime * start, TTime * finish) {
	if (!passenger || !start || !finish)
		throw new std::string("Мне передали нулевой указатель\n");
	bool retval = false;
	TVehicle * vehicle =
			findFreeVehicle(passenger->getClass(), start, finish);
	if (!vehicle){
		throw new std::string("Не удалось найти подходящего водителя\n");
	}
	TDriver * driver = findFreeDriver();

	return retval;
}

TVehicle * TPark::findFreeVehicle(std::string& type, TTime * start,
		TTime * finish) {
	if (!start || !finish)
		throw new std::string("Мне передали нулевой указатель\n");
	TDriver * retval = nullptr;
	std::vector<TDriver> _drivers = findDriversByType(type);
	size_t i = 0;
	while (i < _drivers.size()) {
		if (!isBusy(&_drivers[i], start, finish)) {
			retval = &_drivers[i];
			break;
		}
		i++;
	}

	return retval;

}
TDriver * TPark::findFreeDriver(std::string& type, TTime * start,
		TTime * finish) {
}

bool TPark::removeOrder(TOrder * order) {
}
bool TPark::removeOrder(unsigned int uuid) {
}
