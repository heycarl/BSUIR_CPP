#include "users_manager.h"

int main()
{

	users_manager umanager = users_manager();

	auto u = umanager.sign_up_admin();
	u.create_vehicle();
	u.create_vehicle();
	u.view_vehicles();
//	u.create_bus_stop();
//	u.view_bus_stops();
//	u.modify_bus_stop();
//	u.view_bus_stops();


	return 0;
}
