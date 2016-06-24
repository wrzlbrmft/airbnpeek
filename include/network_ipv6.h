#ifndef NETWORK_IPV6_H
#define NETWORK_IPV6_H

#include <boost/asio.hpp>

#include "network.h"

class network_ipv6 : public network {
protected:
	boost::asio::ip::address_v6 ip_addr;

public:
	network_ipv6(const std::string ip, const uint8_t suffix);

	boost::asio::ip::address_v6 get_ip_addr() const;
	void set_ip_addr(const boost::asio::ip::address_v6 ip_addr);

	virtual boost::multiprecision::uint128_t min_ip_long() const;
	virtual boost::multiprecision::uint128_t max_ip_long() const;
};

#endif
