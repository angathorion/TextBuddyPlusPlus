//This class inherits from the BaseCmd class. It deletes a line from the file by erasing a
//given member of the stringVector as indicated by the index variable.

#ifndef __DELETE_CMD__
#define __DELETE_CMD__
#include "BaseCmd.h"
class DeleteCmd : public BaseCmd {
private:
	//The line number to be deleted
	int index;
public:
	DeleteCmd(std::string filename, std::string parameters);
	~DeleteCmd();

	std::string execute();
};
#endif


