#include <iostream>
#include "ClearCmd.h"
#include "TextBuddy.h"
#include "Constants.h"

ClearCmd::ClearCmd(std::string filename){
	this->filename = filename;
}

ClearCmd::~ClearCmd(){
}

std::string ClearCmd::execute(){
	TextHandler *handler = TextBuddy::Instance().getTextHandler();
	handler->clearContents();
	ss << FEEDBACK_CLEAR(filename) << std::endl;
	return ss.str();
}

