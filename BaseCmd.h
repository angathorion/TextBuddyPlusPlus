//This is the base class from which all other Cmd classes inherit. It serves no other function.
#ifndef __TEXTBUDDY_COMMANDS__
#define __TEXTBUDDY_COMMANDS__
#include <string>
#include <sstream>
//Base command class from which all other commands inherit
class BaseCmd{
public:
	std::string filename;

	std::stringstream ss;
	virtual ~BaseCmd();
};
#endif