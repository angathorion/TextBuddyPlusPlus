//This class inherits from the BaseCmd class. It adds a string to the stringVector via addstring,
//the details of which are passed down via CommandPicker.
//Note that this class, as with all the other commands, do not modify the file directly.
#ifndef __ADD_CMD__
#define __ADD_CMD__
#include "BaseCmd.h"
class AddCmd : public BaseCmd {
private:
	//Input string
	std::string addstring;
public:
	AddCmd(std::string filename, std::string parameters);
	~AddCmd();

	std::string execute();
};
#endif

