//There is NO EXCEPTION HANDLING IN THIS CURRENT VERSION
//It will crash catastrophically in the event that a delete operation is attempted on a
//non existent line.
#include <iostream>
#include <string>
#include "TextBuddy.h"


int main(int argc, char* argv[]){
	//Init program variables
	if (TextBuddy::Instance().checkInputArgs(argc)){
		std::string filename = TextBuddy::Instance().getFilenameFromPath(argv[1]);
		TextBuddy::Instance().setUp(filename);
		TextBuddy::Instance().sayHi(filename);
		TextBuddy::Instance().controlLoop(filename);
		TextBuddy::Instance().tearDown();
	}
	return 0;
}

