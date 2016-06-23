#include "error.h"

exception::exception(std::string msg) {
	this->msg = msg;
}

const char* exception::what() const throw() {
	return msg.c_str();
}
