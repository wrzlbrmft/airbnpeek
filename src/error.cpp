#include "error.h"

exception::exception(const std::string msg) {
	set_msg(msg);
}

std::string exception::get_msg() const {
	return msg;
}

void exception::set_msg(const std::string msg) {
	this->msg = msg;
}

const char* exception::what() const throw() {
	return get_msg().c_str();
}
