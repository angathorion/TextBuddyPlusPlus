#include <iostream>
#include "DeleteCmd.h"
#include "TextBuddy.h"
#include "Constants.h"

DeleteCmd::DeleteCmd(std::string filename, std::string parameters){
	index = std::stoi(parameters);
	this->filename = filename;
}

DeleteCmd::~DeleteCmd(){
}

std::string DeleteCmd::execute(){
	TextHandler *handler = TextBuddy::Instance().getTextHandler();
	std::string deletestring = handler->getString(index);
	handler->deleteText(index);
	ss << FEEDBACK_DELETE(filename, deletestring) << std::endl;
	return ss.str();
}

