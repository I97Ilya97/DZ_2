#include <iostream>
using namespace std;
#include "TComandParser.h"

int main(int argc, char ** argv) {
	cout << "Hello. Type commands or 'help' for help:" << endl; 
	string s = (argc > 1) ? argv[1] : "";

	TComandParser cp((argc > 1) ? &s : nullptr);
	while (1) {
		std::cout << "\ncommand > ";
		s.clear();
		cin.clear();
		//cin>>s;
		getline(std::cin, s, '\n');
		if (s == "exit")
			break;
		if (s == "help") {
			std::cout << "This is a help message\n\n";
			std::cout << "SYNTAX:\n\t<command> <args>\n\n";
			std::cout << "COMMANDS:\n";
			std::cout << "\thelp\tPrint this help message\n";
			std::cout << "\tsave\tSave command history into file\n";
			std::cout << "\tadd\tAdd something into system\n";
			std::cout << "\tshow\tShow something\n";
		}
		else {
			cp.doCommand(s);
		}
	}
	return 0;
}
