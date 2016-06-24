#include <iostream>
#include <boost/program_options.hpp>

#include "version.h"
#include "network.h"

namespace po = boost::program_options;

void print_version_info() {
	std::cout << APP_NAME << " " << APP_VERSION << std::endl;
}

void print_help_message(po::options_description &desc) {
	print_version_info();
	std::cout << desc << std::endl;
}

int main(const int argc, const char** argv) {
	std::string po_interface;
	std::vector<std::string> po_networks;

	try {
		po::options_description desc("options");
		desc.add_options()
			("interface,I", po::value<std::string>(&po_interface), "which interface to use")
			("network,N", po::value<std::vector<std::string>>(&po_networks), "which network(s) to scan, e.g. 192.168.0.0/24")
			("version", "print version info and exit")
			("help,h", "print this help message and exit");

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);

		if (vm.count("version")) {
			print_version_info();
			return 0;
		}
		else if (vm.count("help")) {
			print_help_message(desc);
			return 0;
		}
	}
	catch (std::exception &e) {
		std::cerr << "error: " << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		std::cerr << "error: unknown error" << std::endl;
		return 1;
	}

	if (po_interface.empty()) {
		std::cerr << "error: no interface" << std::endl;
		return 1;
	}

	if (po_networks.empty()) {
		std::cerr << "error: no network(s)" << std::endl;
		return 1;
	}

	for (auto po_network : po_networks) {
		try {
			auto network = network::from_string(po_network);
			std::cout << network->min_ip() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "error: " << e.what() << std::endl;
			return 1;
		}
	}

	return 0;
}
