#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <string>

class network {
public:
	static std::shared_ptr<network> from_string(std::string s);
};

#endif
