#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <memory>
#include <boost/multiprecision/cpp_int.hpp>

enum class network_type {
	ipv4,
	ipv6
};

class network {
protected:
	std::string ip;
	network_type type;
	uint8_t suffix;

public:
	std::string get_ip() const;
	void set_ip(const std::string ip);

	network_type get_type() const;
	void set_type(const network_type type);

	uint8_t get_suffix() const;
	void set_suffix(const uint8_t suffix);

	virtual boost::multiprecision::uint128_t min_ip_long() const = 0;
	virtual boost::multiprecision::uint128_t max_ip_long() const = 0;

	static std::shared_ptr<network> from_string(const std::string s);
};

#endif
