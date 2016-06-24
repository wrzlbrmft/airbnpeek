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
	std::string get_ip() const;
	void set_ip(const std::string ip);

	uint8_t get_suffix() const;
	void set_suffix(const uint8_t suffix);

	virtual uint8_t suffix_inv() const = 0;

	virtual uint32_t min_ip_long() const = 0;
	virtual std::string min_ip() const = 0;

	static std::shared_ptr<network> from_string(const std::string s);
};

#endif
