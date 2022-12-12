//
// Created by Alexandr on 12/12/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_APPLICATION_H
#define TRANSPORTMANAGEMENTSYSTEM_APPLICATION_H

#include "users_manager.h"
#include "console/controller.h"

class application {
public:
	void run();
	void quit();
	~application();
	users_manager umanager;
};
void application::run()
{
	core::load();
	umanager = users_manager();
	controller ctrl = controller(umanager);
	umanager.load_db("users.dat");
	ctrl.run();
}
void application::quit()
{
	umanager.save_db("users.dat");
	core::save();
	std::cout << "Bye!" << std::endl;
}
application::~application()
{
	quit();
}

#endif //TRANSPORTMANAGEMENTSYSTEM_APPLICATION_H
