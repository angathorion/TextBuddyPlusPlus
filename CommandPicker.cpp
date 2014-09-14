#include "CommandPicker.h"
#include <sstream>
#include "BaseCmd.h"
#include <iostream>
#include "Constants.h"
#include "AddCmd.h"
#include "ClearCmd.h"
#include "ExitCmd.h"
#include "DisplayCmd.h"
#include "DeleteCmd.h"
#include "TextBuddy.h"
#include "SortCmd.h"
CommandPicker::CommandPicker(std::string input, std::string file){
	getCommandFromInput(input);
	getParametersFromInput(input);
	filename = file;
}

CommandPicker::~CommandPicker(){
}

//Following two commands come and work in a pair. Used in the constructor only
//for initializing values
void CommandPicker::getCommandFromInput(std::string input){
	command = input.substr(0, input.find(' '));
}

void CommandPicker::getParametersFromInput(std::string input){
	parameters = input.erase(0, command.length() + 1);
}

//Selects the appropriate command, initializes an instance and executes it
std::string CommandPicker::executeCommand(){
	if (command.compare("add") == 0){
		AddCmd cmd(filename, parameters);
		return cmd.execute();
	}
	else if (command.compare("display") == 0) {
		DisplayCmd cmd;
		return cmd.execute();
	}
	else if (command.compare("delete") == 0) {
		DeleteCmd cmd(filename, parameters);
		return cmd.execute();
	}
	else if (command.compare("clear") == 0) {
		ClearCmd cmd(filename);
		return cmd.execute();
	}
	else if (command.compare("exit") == 0) {
		ExitCmd cmd;
		return cmd.execute();
	}
	else if (command.compare("sort") == 0) {
		SortCmd cmd(filename);
		return cmd.execute();
	}
	else {
		std::stringstream ss;
		ss << FEEDBACK_UNRECOGNIZED << std::endl;
		return ss.str();
	}
}