#include <iostream>
#include "SearchCmd.h"
#include "TextBuddy.h"
#include "Constants.h"
#include <numeric>
SearchCmd::SearchCmd(std::string input){
	this->input = input;
}

SearchCmd::~SearchCmd(){
}

std::string SearchCmd::execute(){
	TextHandler *handler = TextBuddy::Instance().getTextHandler();
	std::vector<std::string> results;
	results = handler->searchContents(input);

	std::string str = std::accumulate(results.begin(), results.end(), std::string("\n"));
	ss << FEEDBACK_SEARCH << str << std::endl;
	return ss.str();
}
