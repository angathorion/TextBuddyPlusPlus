#include <iostream>
#include "SortCmd.h"
#include "TextBuddy.h"
#include "Constants.h"

SortCmd::SortCmd(std::string filename){
	this->filename = filename;
}

SortCmd::~SortCmd(){
}

std::string SortCmd::execute(){
	TextHandler *handler = TextBuddy::Instance().getTextHandler();
	handler->sortContents();
	ss << FEEDBACK_SORT(filename) << std::endl;
	return ss.str();
}
