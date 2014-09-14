#include "DisplayCmd.h"
#include "TextBuddy.h"
DisplayCmd::DisplayCmd(){
}

DisplayCmd::~DisplayCmd(){
}

std::string DisplayCmd::execute(){
	TextHandler *handler = TextBuddy::Instance().getTextHandler();
	return handler->displayContents();
}