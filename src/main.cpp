#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
using namespace boost;

int main(int argc, char** argv) {
	program_options::options_description desc("options");
	desc.add_options()
		("help,h", "print this help message and exit");

	program_options::variables_map vm;
	program_options::store(program_options::parse_command_line(argc, argv, desc), vm);
	program_options::notify(vm);

	if (vm.count("help")) {
		cout << desc << endl;
		return 0;
	}

	cout << "airbnpeek" << endl;
	return 0;
}
