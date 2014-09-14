//This class inherits from the BaseCmd class. Its purpose is to exit the program by simply
//flipping the boolean quitProgram variable of the TextBuddy class.
#ifndef __EXIT__CMD__
#define __EXIT__CMD__
#include "BaseCmd.h"

class ExitCmd : public BaseCmd {
public:
	ExitCmd();
	~ExitCmd();

	std::string execute();
};
#endif

