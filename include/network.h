#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <string>

class network {
public:
	static std::shared_ptr<network> fromString(std::string s);
};

#endif
