#include "network.h"

#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>

#include "error.h"
#include "network_ipv4.h"

std::string network::get_ip() const {
	return ip;
}

void network::set_ip(const std::string ip) {
	this->ip = ip;
}

uint8_t network::get_suffix() const {
	return suffix;
}

void network::set_suffix(const uint8_t suffix) {
	this->suffix = suffix;
}

std::shared_ptr<network> network::from_string(const std::string s) {
	std::vector<std::string> splits;
	std::string ip;
	network_type type;
	uint8_t suffix;

	boost::split(splits, s, boost::is_any_of("/"));
	if (2 != splits.size()) {
		throw exception("invalid network");
	}

	try {
		ip = splits[0];
		auto ip_addr = boost::asio::ip::address::from_string(ip);

		if (ip_addr.is_v4()) {
			type = network_type::ipv4;
		}
		else if (ip_addr.is_v6()) {
			type = network_type::ipv6;
		}
		else {
			throw exception("unknown network type");
		}
	}
	catch (exception &e) {
		throw e;
	}
	catch (...) {
		throw exception("invalid network address");
	}

	try {
		suffix = static_cast<uint8_t>(std::stoi(splits[1]));
	}
	catch (...) {
		throw exception("invalid network suffix");
	}

	switch (type) {
		case network_type::ipv4:
			return std::shared_ptr<network>(new network_ipv4(ip, suffix));
			break;

		case network_type::ipv6:
			throw exception("ipv6 currently not supported");
			break;
	}

	return nullptr;
}
