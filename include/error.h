#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>

class exception : public std::exception {
protected:
	std::string msg;

public:
	exception(const std::string msg);

	std::string get_msg() const;
	void set_msg(const std::string msg);

	virtual const char* what() const throw();
};

#endif
