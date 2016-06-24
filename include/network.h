#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <string>

enum class network_type {
	ipv4,
	ipv6
};

class network {
protected:
	std::string ip;
	uint8_t suffix;

public:
	static std::shared_ptr<network> from_string(const std::string s);
};

#endif
