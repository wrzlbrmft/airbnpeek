#include "network.h"

#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>

#include "error.h"
#include "network_ipv4.h"

std::shared_ptr<network> network::from_string(const std::string s) {
	std::vector<std::string> splits;
	std::string ip;
	network_type type;
	int suffix;

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
			throw exception("invalid network address");
		}
	}
	catch (exception &e) {
		throw e;
	}
	catch (...) {
		throw exception("invalid network address");
	}

	try {
		suffix = std::stoi(splits[1]);
	}
	catch (...) {
		throw exception("invalid network suffix");
	}

	switch (type) {
		case network_type::ipv4:
			return new network_ipv4(ip, suffix);

		case network_type::ipv6:
			throw exception("ipv6 currently not supported");
	}
}
