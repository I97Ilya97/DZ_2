#include "TComandParser.h"

size_t countArgs(std::string com) {
	//std::cout << "Calculating command argc \"" << com << "\"\n";
	size_t len = com.length();
	size_t i = 0;
	size_t retval = 0;
	while (i < len) {
		if (i == 0)
			retval++;
		if (com[i] == ' ') {
			if (i > 0) {
				if (com[i - 1] != ' ') {
					retval++;
				}
			}
		}
		i++;
	}
	//std::cout << "argc: " << retval << "\n";
	return retval;
}

std::vector<std::string> splitCommand(std::string com) {
	//std::cout << "Parsing command \"" << com << "\"\n";
	std::vector<std::string> retval;
	//std::cout << "Vector created\n";
	size_t len = com.length();
	size_t i = 0;
	size_t ret_cnt = 0;
	//std::cout << len << "\n";
	//std::cout << "com = "; //<<com<<"\n";
	/*while (i < len) {
	std::cout << com[i];
	i++;
	}*/
	//std::cout << "\n";
	i = 0;
	while (i < len) {
		//std::cout << "scanning symbol " << i << " to ret\n";
		if (i == 0) {
			//std::cout << "Creating new string, because i=0\n";
			std::string s = "";
			retval.push_back(s);
			ret_cnt++;
			//std::cout << "Success\n";
		}
		if (com[i] != ' ') {
			//std::cout << "adding symbol " << i << " to ret\n";
			retval[ret_cnt - 1] += com[i];
			//std::cout << "added symbol to ret\n";
		}
		else {
			if (i > 0) {
				if (com[i - 1] != ' ') {
					//std::cout << "Creating new string, because i=0\n";
					std::string s = "";
					retval.push_back(s);
					ret_cnt++;
					//std::cout << "Success\n";

				}
			}
		}
		//std::cout << i;
		i++;
	}
	//i = 0;
	/*
	std::cout << "Parsed args:\n";
	while (i < retval.size()) {
	std::cout << "\"";

	std::cout << retval[i];
	std::cout << "\"";
	std::cout << "\n";
	i++;

	}*/
	return retval;
}

TComandParser::TComandParser(std::string * filename) {
	// TODO Auto-generated constructor stub

	//commands = *(new std::vector<std::string>());
	if (!filename)
		return;
	try {
		std::ifstream iFile;
		iFile.open(filename->data());
		while (!iFile.eof()) {
			std::string currCom;
			std::getline(iFile, currCom);
			doCommand(currCom);
		}

	}
	catch (std::exception e) {
		std::cout << "File IO error\n";
	}

}

TComandParser::~TComandParser() {
	// TODO Auto-generated destructor stub

	//delete (&commands);
}
void TComandParser::pushCommand(std::string command) {
	std::vector<std::string> args = splitCommand(command);
	if (countArgs(command) == 0)return;
	if ((args[0] == "save") || (args[0] == "show"))
		return;
	commands.push_back(command);
}
void TComandParser::saveCommands(std::string filename) {

	try {
		std::ofstream oFile;
		oFile.open(filename.data());
		size_t i = 0, len = commands.size();
		while (i < len) {
			oFile << commands[i] << "\n";
			i++;
		}

	}
	catch (std::exception e) {
		std::cout << "File IO error\n";
	}
}
void TComandParser::doCommand(std::string command) {
	size_t cnt = countArgs(command);
	if (!cnt)
		return;

	std::vector<std::string> args = splitCommand(command);

	if (args[0] == "save") {
		if (cnt > 1) {
			std::cout << "Trying to save into file:\n" << args[1] << "\n";
			saveCommands(args[1]);
		}
		else {
			std::cout << "I'm not understand, where you want to save.\n";
			std::cout << "Default usage of 'save' command:\n";
			std::cout << "\tshow <path-to-file>\n";
		}
	}
	if (args[0] == "add") {
		if (cnt > 1) {
			if (args[1] == "car") {
				if (cnt > 2) {
					if (args[2] == "heavy") {
						std::cout << "Added heavy vehicle\n";
						park.addVehicle(*((TVehicle *)(new TVehicleHeavy())));
					}
					if (args[2] == "--help") {
						std::cout << "COMMAND: add car\n";
						std::cout << "USAGE:\n\tadd car <args>\n";
						std::cout << "POSSIBLE ARGUMENTS:\n";
						std::cout << "\t--help\tPrint this help message\n";
						std::cout << "\theavy\tAdd heavy car into garage\n";
					}
				}
				else {
					std::cout
						<< "I'm not understand which car you want to add\n";
					std::cout
						<< "Type 'add car --help' to get help about this command\n";
				}
				//TODO: add another cars
			}
			if (args[1] == "driver") {
				if (cnt > 2) {

					if (args[2] == "heavy") {
						park.addDriver(*((TDriver *)(new TDriverHeavy())));
					}
					if (args[2] == "--help") {
						std::cout << "COMMAND: add driver\n";
						std::cout << "USAGE:\n\tadd driver <args>\n";
						std::cout << "POSSIBLE ARGUMENTS:\n";
						std::cout << "\t--help\tPrint this help message\n";
						std::cout
							<< "\theavy\tAdd heavy car driver into garage\n";
					}
				}
				else {
					std::cout
						<< "I'm not understand which driver you want to add\n";
					std::cout
						<< "Type 'add driver --help' to get help about this command\n";
				}
				//TODO: add another drivers
			}
			if (args[1] == "order") {
				if (cnt > 2) {
					if (args[2] == "heavy") {
						if (cnt > 4) {
							try {
								park.addOrder(
									(TPassenger *)(new TPassengerHeavy()),
									new TTime(args[3]), new TTime(args[4]));
							}
							catch (std::string e) {
								std::cout << e;

							}
						}
						else {
							std::cout << "Order must have description\n";
							std::cout
								<< "Type 'add order --help' to get help about this command\n";
						}
					}
					if (args[2] == "--help") {
						std::cout << "COMMAND: add order\n";
						std::cout << "USAGE:\n\tadd order <args>\n";
						std::cout << "POSSIBLE ARGUMENTS:\n";
						std::cout << "\t--help\tPrint this help message\n";
						std::cout
							<< "\theavy <when>\tAdd order with heavy payload\n";
						std::cout << "DESCRIPTIONS:\n\t<when>\n";
						std::cout << "\tMust have two time values\n";
						std::cout << "\tFirst one for start time\n";
						std::cout << "\tSecond one for finish time\n";
						std::cout << "\tTime format: hh.mm.ss.DD.MM.YYYY\n";
					}
				}
				else {

					std::cout << "Order must have description\n";
					std::cout
						<< "Type 'add order --help' to get help about this command\n";
				}
				//TODO: add orders for another passenger types
			}
			if (args[1] == "--help") {
				std::cout << "COMMAND: add\n";
				std::cout << "USAGE:\n\tadd <args>\n";
				std::cout << "POSSIBLE ARGUMENTS:\n";
				std::cout << "\t--help\tPrint this help message\n";
				std::cout << "\tcar\tAdd a car into garage\n";
				std::cout << "\tdriver\tAdd a car driver into garage\n";
				std::cout << "\torder\tAdd order\n";
			}
		}
		else {
			std::cout << "I'm not understand, what do you want to add.\n";
			std::cout << "Default usage of 'add' command:\n";
			std::cout << "\tadd <what>\n";
			std::cout
				<< "You also can type 'add --help' to get help about add\n";
		}

	}
	if (args[0] == "show") {
		//std::cout<<"show ";
		if (cnt > 1) {
			if ((args[1] == "orders")) {
				//std::cout<<"orders\n";
				std::vector<TOrder> v = park.getAllOrders();
				size_t i = 0;
				size_t cnt = v.size();
				if (cnt == i) {
					std::cout << "No orders\n";
				}
				while (i < cnt) {
					std::cout << "|";
					std::cout << i;
					std::cout << "|Class: " << v[i].getDriver()->getClass();
					std::cout << "|Start: " << v[i].getStartTime()->toString();
					std::cout << "|Finish: "
						<< v[i].getFinishtime()->toString();
					std::cout << "|\n";
					i++;
				}
			}
			if (args[1] == "history") {
				std::cout << "COMMAND HISTORY:\n";
				size_t i = 0;
				size_t cnt = commands.size();
				if (i == cnt) {
					std::cout << "No commands\n";
				}
				while (i < cnt) {
					std::cout << i << " : " << commands[i];
					i++;
				}
			}
			if (args[1] == "--help") {
				std::cout << "COMMAND: show\n";
				std::cout << "USAGE:\n\tshow <args>\n";
				std::cout << "POSSIBLE ARGUMENTS:\n";
				std::cout << "\t--help\tPrint this help message\n";
				std::cout << "\thistory\tPrint commands history\n";
				std::cout << "\torders\tPrint order history\n";
			}
		}
		else {
			std::cout << "I'm not understand, what do you want to see.\n";
			std::cout << "Default usage of 'show' command:\n";
			std::cout << "\tshow <what>\n";
			std::cout
				<< "You also can type 'show --help' to get help about show\n";
		}
	}
	pushCommand(command);
}

