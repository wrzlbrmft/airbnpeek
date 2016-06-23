#include <iostream>
#include <boost/program_options.hpp>

using namespace boost;

#define APP_NAME "airbnpeek"
#define APP_VERSION "0.0.0"

void print_version_info() {
	std::cout << APP_NAME << " " << APP_VERSION << std::endl;
}

void print_help_message(program_options::options_description &desc) {
	print_version_info();
	std::cout << desc << std::endl;
}

int main(int argc, char** argv) {
	try {
		program_options::options_description desc("options");
		desc.add_options()
			("version", "print version info and exit")
			("help,h", "print this help message and exit");

		program_options::variables_map vm;
		program_options::store(program_options::parse_command_line(argc, argv, desc), vm);
		program_options::notify(vm);

		if (vm.count("version")) {
			print_version_info();
			return 0;
		}

		if (vm.count("help")) {
			print_help_message(desc);
			return 0;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	catch (...) {
		std::cerr << "unknown error" << std::endl;
		return -1;
	}

	return 0;
}
