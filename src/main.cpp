#include <iostream>
#include <boost/program_options.hpp>

#include "version.h"

namespace po = boost::program_options;

void print_version_info() {
	std::cout << APP_NAME << " " << APP_VERSION << std::endl;
}

void print_help_message(po::options_description &desc) {
	print_version_info();
	std::cout << desc << std::endl;
}

int main(int argc, char** argv) {
	std::string po_interface;
	std::vector<std::string> po_networks;

	try {
		po::options_description desc("options");
		desc.add_options()
			("network,N", po::value<std::vector<std::string>>(&po_networks), "which network(s) to scan, e.g. 192.168.0.0/24")
			("interface,I", po::value<std::string>(&po_interface), "which interface to use")
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
		return -1;
	}
	catch (...) {
		std::cerr << "error: unknown error" << std::endl;
		return -1;
	}

	if (po_interface.empty()) {
		std::cerr << "error: no interface" << std::endl;
		return 1;
	}

	if (po_networks.empty()) {
		std::cerr << "error: no network(s)" << std::endl;
		return 1;
	}

	std::cout << po_interface << std::endl;
	for (auto po_network : po_networks) {
		std::cout << po_network << std::endl;
	}

	return 0;
}
