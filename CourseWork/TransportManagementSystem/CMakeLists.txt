cmake_minimum_required(VERSION 3.22)
project(TransportManagementSystem)

set(CMAKE_CXX_STANDARD 17)

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

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
        core/core.cpp core/core.h
        route/routes_manager.cpp
        route/routes_manager.h
        bus_stop/bus_stops_manager.cpp
        bus_stop/bus_stops_manager.h
        person/drivers_manager.cpp
        person/drivers_manager.h
        vehicle/vehicles_manager.cpp
        vehicle/vehicles_manager.h
        manager/manager.h
        interface/console/renderer.h
        interface/console/controller.h
        core/application.h)

set(Directories
        route
        bus_stop
        date
        person
        vehicle
        travel_cards
        uid_generator
        users
        core
        manager
        interface)

find_package(Boost 1.80.0 REQUIRED COMPONENTS serialization)
find_package(CryptoPP REQUIRED)

add_executable(TransportManagementSystem main.cpp ${Sources})
target_include_directories(TransportManagementSystem PRIVATE ${Directories})
target_link_libraries(TransportManagementSystem PRIVATE ${Boost_LIBRARIES} ${CryptoPP_LIBRARY})
