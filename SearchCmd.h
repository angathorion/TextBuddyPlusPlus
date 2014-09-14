//This class inherits from the BaseCmd class. It calls the searchContents function of TextHandler
//when executed

#ifndef __SEARCH_CMD__
#define __SEARCH_CMD__
#include "BaseCmd.h"
class SearchCmd : public BaseCmd {
private:
public:
	SearchCmd(std::string input);
	~SearchCmd();
	std::string input;
	std::string execute();
};

#endif
