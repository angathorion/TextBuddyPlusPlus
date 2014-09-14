#include <iostream>
#include "AddCmd.h"
#include "TextBuddy.h"
#include "Constants.h"

AddCmd::AddCmd(std::string filename, std::string parameters){
	this->filename = filename;
	addstring = parameters;
}

AddCmd::~AddCmd(){
}

std::string AddCmd::execute(){
	TextHandler *handler = TextBuddy::Instance().getTextHandler();
	handler->addText(addstring);
	ss << FEEDBACK_ADD(filename, addstring) << std::endl;
	return ss.str();
}

