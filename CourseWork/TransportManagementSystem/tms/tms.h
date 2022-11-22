//
// Created by Alexandr on 11/15/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_TMS_H
#define TRANSPORTMANAGEMENTSYSTEM_TMS_H

#include <list>

#include "passenger.h"
#include "driver.h"
#include "bus_stop.h"
#include "travel_cards_manager.h"
#include "route.h"

class tms {
private:
    std::list<passenger> passengers;
    std::list<driver> drivers;
    std::list<vehicle> vehicles;
    std::list<bus_stop> bus_stops;
    std::list<travelCard> travel_cards;
    std::list<route> routes;
    travelCardsManager tcm;

public:
    void create_passenger();
    void create_driver();
    void create_vehicle();
    void create_bus_stop();
    void create_travel_card(); // asks for user login and pass
    void create_route();


    void passenger_login();
    void passenger_add_trips();
    void passenger_logout();

    void start_route();
    void route_next_stop();

    void route_serialize_stats();
    void route_serialize_information();

};


#endif //TRANSPORTMANAGEMENTSYSTEM_TMS_H
