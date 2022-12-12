#include "core/application.h"

int main()
{
	application app = application();
	try {
		app.run();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled error happend. Bye!" << std::endl;
	}
	return 0;
}
