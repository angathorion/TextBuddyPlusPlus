//The class that defines and controls the main flow of the program. It is instantiated
//as a singleton via the main() function, and runs from the initializeProgram() function.
//After doing some rudimentary argument and file checks, it loops indefinitely through
//a get-input/parse-input cycle. The input is parsed via the feedCommandPicker() function,
//and instantiates a new CommandPicker object every loop. All file operations are abstracted
//away into the TextHandler class, instantiated by this class.
//The class passes control back to the main function after a CommandPicker object parses
//an ExitCmd.
#ifndef __TEXTBUDDY__
#define __TEXTBUDDY__
#include <string>
#include "BaseCmd.h"
#include "TextHandler.h"
class TextBuddy{

private:
	TextBuddy();
	TextBuddy(const TextBuddy&);
	TextBuddy& operator= (const TextBuddy&);
	~TextBuddy();

	std::string filename;
	//Helper function: strips a full path of the directory prefix.
	bool quitProgram = false;
	TextHandler* textHandler;
	std::string inputline;
public:
	static TextBuddy &Instance();
	void sayHi(std::string filename);
	std::string getFilenameFromPath(char* argv);
	bool checkInputArgs(int argc);
	void sayString(std::string output);
	//Main program loop
	void controlLoop(std::string filename);
	void initializeTextHandler(std::string filename);
	//Takes in a line of input, tokenizes it, and executes the appropriate command
	std::string feedCommandPicker(std::string inputline, std::string filename);
	//Marks the program for exit using quitProgram
	void setExit();
	//A pointer to textHandler for use by the Cmd classes
	TextHandler* getTextHandler();
	void setUp(std::string filename);
	void tearDown();
};

#endif