//Constants for user feedback such as error and operational messages
#ifndef __TEXTBUDDY_CONSTS__
#define __TEXTBUDDY_CONSTS__
#include <string>

#define MSG_WELCOME(filename) \
	"Welcome to TextBuddy. " + filename + " is ready for use"
#define FEEDBACK_ADD(filename, addstring) \
	"added to " + filename + ": \"" + addstring << "\""
#define FEEDBACK_DELETE(filename, deletestring) \
	 "deleted from " + filename + ": \"" + deletestring + "\"" 
#define FEEDBACK_CLEAR(filename) \
	"all content deleted from " + filename
#define FEEDBACK_UNRECOGNIZED \
	"Unrecognized command."
#define FEEDBACK_ERROR_FILE_OPEN \
	"Cannot open file"
#define FEEDBACK_PROMPT \
	"command: "
#define FEEDBACK_FILE_EMPTY(filename) \
	filename + " is empty"
#endif