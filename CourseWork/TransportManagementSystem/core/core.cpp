//
// Created by Alexandr on 11/27/2022.
//

#include "core.h"

travel_cards_manager core::tcm = travel_cards_manager();
routes_manager core::rm = routes_manager();
bus_stops_manager core::bsm = bus_stops_manager();
drivers_manager core::dm = drivers_manager();
vehicles_manager core::vm = vehicles_manager();

#define TCM_DB_FILE "travel_cards.dat"
#define VM_DB_FILE "vehicles.dat"

void core::load()
{
	tcm.load_db(TCM_DB_FILE);
	vm.load_db(VM_DB_FILE);
}
void core::save()
{
	tcm.save_db(TCM_DB_FILE);
	vm.save_db(VM_DB_FILE);
}
