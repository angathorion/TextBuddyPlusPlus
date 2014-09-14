//The class that abstracts away file operations from the rest of the program. It is instantiated
//only once, by TextBuddy, and utilized for the entire lifetime of the program. 
//Note that all instructions are passed to TextHandler through the CommandPicker, even in the case 
//when a command is not explicitly entered by the user.

//Text is stored line by line in a string vector, for ease of addition, deletion and sorting.
//Saving is done after every operation
#ifndef __TEXTHANDLER__
#define __TEXTHANDLER__
#include <fstream>
#include <vector>
#include <string>
#include "TextHandler.h"
class TextHandler{
private:
	std::ifstream textfile;
	std::vector<std::string> stringVector;
	std::string filename;
public:
	TextHandler();
	TextHandler(std::string filename);
	~TextHandler();
	void addText(std::string input);
	void deleteText(int index);
	void saveFile();
	std::string displayContents();
	void clearContents();
	std::vector<std::string> getStringVector();
	std::string getString(int index);
	void sortContents();
	std::vector<std::string> searchContents(std::string input);
};

#endif