//Designed as a singleton, because there is only supposed to be a single instance across
//the lifetime of the program.
#include "TextBuddy.h"
#include "Constants.h"
#include "CommandPicker.h"
#include "TextHandler.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

TextBuddy::TextBuddy(){
};

TextBuddy& TextBuddy::Instance(){
	static TextBuddy *instance = new TextBuddy();
	return *instance;
}

//The meat of the class. main function calls this, which serves as the command loop
//for the rest of the lifetime of the program
//Input: the arguments of the main function, verbatim
void TextBuddy::controlLoop(std::string filename){
	while (!quitProgram){
		TextBuddy::sayString(FEEDBACK_PROMPT);
		std::getline(std::cin, inputline);
		//passes input to commander which parses, chooses and executes the command
		TextBuddy::sayString(feedCommandPicker(inputline, filename));
		textHandler->saveFile();
	}
}

//Tells the program to exit after the next loop
void TextBuddy::setExit(){
	quitProgram = true;
}

//Passes user input into a CommandPicker object and executes the command returned
std::string TextBuddy::feedCommandPicker(std::string inputline, std::string filename){
	CommandPicker picker(inputline, filename);
	return picker.executeCommand();
}

//Greets the user upon program init
//Input: filename as a string
void TextBuddy::sayHi(std::string filename){
	std::cout << MSG_WELCOME(filename) << std::endl;
}

void TextBuddy::sayString(std::string output){
	std::cout << output;
}

//Helper function for sayHi(): strips a full path of the directory prefix.
//Input: character array of the directory path + filename
//Output: a string containing the filename
std::string TextBuddy::getFilenameFromPath(char* argv){
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath_s(argv, drive, dir, fname, ext);
	std::stringstream ss;
	ss << fname << ext;
	std::string filename = "";
	ss >> filename;
	return filename;
}

TextHandler* TextBuddy::getTextHandler(){
	return textHandler;
}

//Simple check for argument count at program start
bool TextBuddy::checkInputArgs(int argc){
	return argc == 2;
}

void TextBuddy::initializeTextHandler(std::string filename){
	textHandler = new TextHandler(filename);
}

void TextBuddy::setUp(std::string filename){
	TextBuddy::Instance().initializeTextHandler(filename);
}

void TextBuddy::tearDown(){
	delete TextBuddy::Instance().getTextHandler();
}