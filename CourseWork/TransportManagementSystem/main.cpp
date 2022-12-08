#include "users_manager.h"

int main()
{

	core::load();
	users_manager umanager = users_manager();
	umanager.load_db("users.dat");
	auto& a = umanager.sign_in_admin();
	a.view_vehicles();
	umanager.save_db("users.dat");
	core::save();
//	u.create_bus_stop();
//	u.create_driver();
//	u.create_vehicle();
//	u.create_route();


	return 0;
}
