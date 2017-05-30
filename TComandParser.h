#ifndef TCOMANDPARSER_H_
#define TCOMANDPARSER_H_
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "TPark.h"


class TComandParser {
private:
	std::vector<std::string> commands;
	TPark park;
	void pushCommand(std::string command);
	void saveCommands(std::string filename);
public:
	TComandParser(std::string * filename);
	void doCommand(std::string command);


	virtual ~TComandParser();
};


#endif /* TCOMANDPARSER_H_ */

