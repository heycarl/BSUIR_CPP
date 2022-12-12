//
// Created by Alexandr on 12/12/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_CONTROLLER_H
#define TRANSPORTMANAGEMENTSYSTEM_CONTROLLER_H

#include "renderer.h"

class controller {
public:
	explicit controller(users_manager& u);
	void run()
	{
		renderer::render_boot_screen();
		while (true) { // user login loop
			renderer::render_message("You want to login as admin (1) or passenger (2)?");
			int ch;
			std::cin >> ch;
			switch (ch) {
			case 1: {
				try {
					user_admin& admin = umanager.sign_in_admin();
					admin_ui(admin);
				}
				catch (std::runtime_error& e) {
					renderer::render_error(e.what());
				}
				break;
			}
			case 2: {
				try {
					user_passenger& passenger = umanager.sign_in_passenger();
					passenger_ui(passenger);
				}
				catch (std::runtime_error& e) {
					renderer::render_error(e.what());
				}
				break;
			}
			default: {
				continue;
			}
			}
		}
	}
private:
	void admin_ui(user_admin& a);
	void passenger_ui(user_passenger& p);
	users_manager& umanager;
	struct func_admin {
		std::string description;
		std::_Mem_fn<void (user_admin::*)()> function;
	};
	static std::map<int, struct func_admin> admin_functions;
	struct func_passenger {
		std::string description;
		std::_Mem_fn<void (user_passenger::*)()> function;
	};
	static std::map<int, struct func_passenger> passenger_functions;
};
controller::controller(users_manager& u)
		:umanager(u) { };

std::map<int, struct controller::func_admin> controller::admin_functions = {
		{ 1, { "Create driver", std::mem_fn(&user_admin::create_driver) }},
		{ 2, { "View drivers", std::mem_fn(&user_admin::view_drivers) }},
		{ 3, { "Modify drivers", std::mem_fn(&user_admin::modify_driver) }},
		{ 4, { "Create vehicle", std::mem_fn(&user_admin::create_vehicle) }},
		{ 5, { "View vehicles", std::mem_fn(&user_admin::view_vehicles) }},
		{ 6, { "Create bus stop", std::mem_fn(&user_admin::create_bus_stop) }},
		{ 7, { "View bus stops", std::mem_fn(&user_admin::view_bus_stops) }},
		{ 8, { "Modify bus stop", std::mem_fn(&user_admin::modify_bus_stop) }},
		{ 9, { "Create route", std::mem_fn(&user_admin::create_route) }},
		{ 10, { "Serialize route stats", std::mem_fn(&user_admin::route_serialize_stats) }},
		{ 11, { "Serialize route information", std::mem_fn(&user_admin::route_serialize_information) }},
};
void controller::admin_ui(user_admin& a)
{
	int ch;
	while (true) {
		for (auto& func : admin_functions) {
			renderer::render_message(std::to_string(func.first)+". "+func.second.description);
		}
		renderer::render_message("0. Exit");
		std::cin >> ch;
		auto selected_function = admin_functions.find(ch);
		if (selected_function!=admin_functions.end()) {
			auto method = std::bind(selected_function->second.function, &a);
			try {
				method();
			}
			catch (std::exception& e) {
				renderer::render_error(e.what());
			}

		}
		else if (ch==0) {
			break;
		}
	}
}
std::map<int, struct controller::func_passenger> controller::passenger_functions = {
		{ 1, { "Buy trips", std::mem_fn(&user_passenger::buy_trips) }},
		{ 2, { "View remaining trips", std::mem_fn(&user_passenger::view_remaining_trips) }},
		{ 3, { "Enter bus", std::mem_fn(&user_passenger::enter_bus) }},
		{ 4, { "Get arrival time", std::mem_fn(&user_passenger::get_arrival_time) }},
};
void controller::passenger_ui(user_passenger& p)
{
	int ch;
	while (true) {
		for (auto& func : passenger_functions) {
			renderer::render_message(std::to_string(func.first)+". "+func.second.description);
		}
		renderer::render_message("0. Exit");
		std::cin >> ch;
		auto selected_function = passenger_functions.find(ch);
		if (selected_function!=passenger_functions.end()) {
			auto method = std::bind(selected_function->second.function, &p);
			try {
				method();
			}
			catch (std::exception& e) {
				renderer::render_error(e.what());
			}

		}
		else if (ch==0) {
			break;
		}
	}
}

#endif //TRANSPORTMANAGEMENTSYSTEM_CONTROLLER_H
