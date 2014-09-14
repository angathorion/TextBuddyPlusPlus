#include "ExitCmd.h"
#include "TextBuddy.h"

ExitCmd::ExitCmd(){
}

ExitCmd::~ExitCmd(){
}

//Sets quit_program to true so that the main loop exits in next round
//Passes control back to main()
std::string ExitCmd::execute(){
	TextBuddy::Instance().setExit();
	return "";
}