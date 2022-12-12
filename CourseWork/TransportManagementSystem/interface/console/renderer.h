//
// Created by Alexandr on 12/12/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_RENDERER_H
#define TRANSPORTMANAGEMENTSYSTEM_RENDERER_H

#include <iostream>

class renderer {
public:
	static void render_boot_screen()
	{
		std::cout << R"( _________  ____    ____   ______       )" "\n"
					 R"("|  _   _  ||_   \\  /   _|.' ____ \\   )" "\n"
					 R"("|_/ | | \\_|  |   \\/   |  | (___ \\_| )" "\n"
					 R"("    | |      | |\\  /| |   _.____`.    )" "\n"
					 R"("   _| |_    _| |_\\/_| |_ | \\____) |  )" "\n"
					 R"("  |_____|  |_____||_____| \\______.'   )" "\n"
				  << std::endl;
	}
	static void render_message(const std::string& msg)
	{
		std::cout << msg << std::endl;
	}
	static void render_error(const std::string& err)
	{
		std::cerr << "Error happend: \"" << err << "\"" << std::endl;
	}
	static void render_headline(const std::string& headline)
	{
		std::cout << "** " << headline << " **" << std::endl;
	}
};

#endif //TRANSPORTMANAGEMENTSYSTEM_RENDERER_H
