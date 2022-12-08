#include "users_manager.h"
#include "core.h"

int main()
{

	core::load();
	users_manager umanager = users_manager();
	auto u = umanager.sign_up_passenger();
	u.buy_trips();
	core::save();
//	u.create_bus_stop();
//	u.create_driver();
//	u.create_vehicle();
//	u.create_route();


	return 0;
}
