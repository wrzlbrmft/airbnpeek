#include "network.h"

#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>

#include "error.h"

std::shared_ptr<network> network::from_string(std::string s) {
	std::vector<std::string> splits;
	boost::split(splits, s, boost::is_any_of("/"));

	if (2 != splits.size()) {
		throw exception("invalid network");
	}

	try {
		auto ip_addr = boost::asio::ip::address::from_string(splits[0]);

		if (ip_addr.is_v4()) {
		}
		else if (ip_addr.is_v6()) {
			throw exception("ipv6 currently not supported");
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
		std::stoi(splits[1]);
	}
	catch (...) {
		throw exception("invalid network suffix");
	}

	return nullptr;
}
