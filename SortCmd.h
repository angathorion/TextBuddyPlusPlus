//This class inherits from the BaseCmd class. It calls the sortContents function of TextHandler
//when executed

#ifndef __SORT_CMD__
#define __SORT_CMD__
#include "BaseCmd.h"
class SortCmd : public BaseCmd {
private:
public:
	SortCmd(std::string filename);
	~SortCmd();

	std::string execute();
};

#endif
