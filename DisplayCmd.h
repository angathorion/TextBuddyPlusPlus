//This class inherits from the BaseCmd class. It displays the file contents by iterating through
//the contents of the stringVector from TextHandler.
#ifndef __DISPLAY_CMD__
#define __DISPLAY_CMD__
#include "BaseCmd.h"
class DisplayCmd : public BaseCmd {
public:
	DisplayCmd();
	~DisplayCmd();

	std::string execute();
};
#endif