#include <iostream>
#include <boost/program_options.hpp>

#include "version.h"

using namespace boost;

void print_version_info() {
	std::cout << APP_NAME << " " << APP_VERSION << std::endl;
}

void print_help_message(program_options::options_description &desc) {
	print_version_info();
	std::cout << desc << std::endl;
}

int main(int argc, char** argv) {
	std::string interface;
	std::vector<std::string> networks;

	try {
		program_options::options_description desc("options");
		desc.add_options()
			("network,N", program_options::value<std::vector<std::string>>(&networks), "which network(s) to scan, e.g. 192.168.0.0/24")
			("interface,I", program_options::value<std::string>(&interface), "which interface to use")
			("version", "print version info and exit")
			("help,h", "print this help message and exit");

		program_options::variables_map vm;
		program_options::store(program_options::parse_command_line(argc, argv, desc), vm);
		program_options::notify(vm);

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

	if (interface.empty()) {
		std::cerr << "error: no interface" << std::endl;
		return 1;
	}

	if (networks.empty()) {
		std::cerr << "error: no network(s)" << std::endl;
		return 1;
	}

	std::cout << interface << std::endl;
	for (auto network : networks) {
		std::cout << network << std::endl;
	}

	return 0;
}
