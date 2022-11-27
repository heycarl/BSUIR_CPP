#include <iostream>

#include "users_manager.h"

int main()
{

	users_manager umanager = users_manager();

	auto u = umanager.sign_up_passenger();
	u.buy_trips();
	return 0;
}
