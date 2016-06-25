#include "network_ipv6.h"

#include "error.h"

network_ipv6::network_ipv6(const std::string ip, const uint8_t suffix) {
	try {
		set_ip(ip);
		set_type(network_type::ipv6);
		set_suffix(suffix);

		set_ip_addr(boost::asio::ip::address_v6::from_string(get_ip()));
	}
	catch (...) {
		throw exception("invalid ipv6 network address");
	}
}

boost::asio::ip::address_v6 network_ipv6::get_ip_addr() const {
	return ip_addr;
}

void network_ipv6::set_ip_addr(const boost::asio::ip::address_v6 ip_addr) {
	this->ip_addr = ip_addr;
}

boost::multiprecision::uint128_t network_ipv6::min_ip_long() const {
	return 0;
}

boost::multiprecision::uint128_t network_ipv6::max_ip_long() const {
	return 0;
}
