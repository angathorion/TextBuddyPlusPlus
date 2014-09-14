#include "TextHandler.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Constants.h"

TextHandler::TextHandler(std::string filename)
	: filename(filename)
{
	std::string inputline;
	filename = filename;
	std::ifstream textfile(filename);

	//Check if file can be opened
	if (!textfile){
		std::cout << FEEDBACK_ERROR_FILE_OPEN << std::endl;
	}
	else {
		//Populates text vector with the file's contents
		while (std::getline(textfile, inputline)){
			addText(inputline);
		}
	}
}

TextHandler::~TextHandler(){
	textfile.close();
}

void TextHandler::addText(std::string input){
	stringVector.push_back(input);
}

//Iterates through stringVector and outputs contents in prescribed format
std::string TextHandler::displayContents(){
	int i = 1;
	std::stringstream ss;
	for (std::vector<std::string>::iterator it = stringVector.begin(); it != stringVector.end(); ++it) {
		ss << i << ". " << *it << std::endl;
		i++;
	}
	if (i == 1){
		ss << FEEDBACK_FILE_EMPTY(filename) << std::endl;
	}
	return ss.str();
}

void TextHandler::clearContents(){
	stringVector.clear();
}

void TextHandler::sortContents(){

}


//Writes contents of stringVector to file
void TextHandler::saveFile(){
	std::ofstream outfile(filename);
	for (std::vector<std::string>::iterator it = stringVector.begin(); it != stringVector.end(); ++it) {
		outfile << *it << std::endl;
	}
	outfile.close();
}

void TextHandler::deleteText(int index){
	int vectorSize = stringVector.size();
	stringVector.erase(stringVector.begin() + index - 1);
}

std::string TextHandler::getString(int index){
	return stringVector[index-1];
}

std::vector<std::string> TextHandler::getStringVector(){
	return stringVector;
}