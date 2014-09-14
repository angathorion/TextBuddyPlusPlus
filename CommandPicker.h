//This class interfaces between the TextBuddy class (program control loop) and the individual
//commands. It is instantiated once every loop in the TextBuddy class, and takes in the entire
//input line as the parameters for its constructor. It gets the command and command parameters
//from the input using getCommandFromInput and getParametersFromInput, and executes the command
//via executeCommand.

#ifndef __COMMANDPICKER__
#define __COMMANDPICKER
#include <string>
#include "TextHandler.h"
class CommandPicker{
private:
	std::string command;
	std::string parameters;
	std::string filename;
public:
	CommandPicker(std::string input, std::string filename);
	~CommandPicker();
	void getCommandFromInput(std::string input);
	void getParametersFromInput(std::string input);
	std::string executeCommand();
};
#endif