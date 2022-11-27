cmake_minimum_required(VERSION 3.23)
project(TransportManagementSystem)

set(CMAKE_CXX_STANDARD 17)

set(Sources
        main.cpp
        vehicle/vehicle.cpp
        vehicle/vehicle.h
        route/route.cpp
        route/route.h
        bus_stop/bus_stop.cpp
        bus_stop/bus_stop.h
        person/person.cpp
        person/person.h
        person/driver.cpp
        person/driver.h
        date/date.cpp
        date/date.h
        person/passenger.cpp
        person/passenger.h
        travel_cards/travel_card.cpp
        travel_cards/travel_card.h
        travel_cards/travel_cards_manager.cpp
        travel_cards/travel_cards_manager.h
        vehicle/vehicle.cpp
        vehicle/vehicle.h
        vehicle/bus.cpp
        vehicle/bus.h
        vehicle/e_bus.cpp
        vehicle/e_bus.h
        vehicle/tram.cpp
        vehicle/tram.h
        uid_generator/uid_generator.cpp
        uid_generator/uid_generator.h
        users/user.cpp
        users/user.h
        users/user_passenger.cpp
        users/user_passenger.h
        users/user_admin.cpp
        users/user_admin.h
        users/users_manager.cpp
        users/users_manager.h
        core/core.cpp core/core.h)

set(Directories
        route
        bus_stop
        date
        person
        vehicle
        travel_cards
        uid_generator
        users
        core)

add_executable(TransportManagementSystem main.cpp ${Sources})
target_include_directories(TransportManagementSystem PRIVATE ${Directories})
