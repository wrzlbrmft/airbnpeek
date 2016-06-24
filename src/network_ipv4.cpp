#include "network_ipv4.h"

#include "error.h"

network_ipv4::network_ipv4(const std::string ip, const uint8_t suffix) {
	try {
		this->ip = ip;
		this->type = network_type::ipv4;
		this->suffix = suffix;
		this->ip_addr = boost::asio::ip::address_v4::from_string(this->ip);
	}
	catch (...) {
		throw exception("invalid ipv4 network address");
	}
}

boost::asio::ip::address_v4 network_ipv4::get_ip_addr() const {
	return ip_addr;
}

void network_ipv4::set_ip_addr(const boost::asio::ip::address_v4 ip_addr) {
	this->ip_addr = ip_addr;
}

uint8_t network_ipv4::suffix_inv() const {
	return static_cast<uint8_t>(std::numeric_limits<uint32_t>::digits - get_suffix());
}

uint32_t network_ipv4::min_ip_long() const {
	return (static_cast<uint32_t>(get_ip_addr().to_ulong()) >> suffix_inv() << suffix_inv()) + 1;
}

uint32_t network_ipv4::max_ip_long() const {
	return (min_ip_long() | (static_cast<uint32_t>(~0) >> get_suffix())) - 1;
}
