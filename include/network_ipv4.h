#ifndef NETWORK_IPV4_H
#define NETWORK_IPV4_H

#include <boost/asio.hpp>

#include "network.h"

class network_ipv4 : public network {
protected:
	boost::asio::ip::address_v4 ip_addr;

public:
	network_ipv4(const std::string ip, const int suffix);
};

#endif