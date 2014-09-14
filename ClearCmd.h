//This class inherits from the BaseCmd class. It is instantiated by CommandPicker, and clears the
//text file of all data.
#ifndef __CLEAR_CMD__
#define __CLEAR_CMD__
#include <string>
#include "BaseCmd.h"
class ClearCmd : public BaseCmd {
public:
	ClearCmd(std::string filename);
	~ClearCmd();

	std::string execute();
};

#endif
