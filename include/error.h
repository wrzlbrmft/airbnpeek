#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>

class exception : public std::exception {
protected:
	std::string msg;

public:
	exception(std::string msg);
	virtual const char* what() const throw();
};

#endif
