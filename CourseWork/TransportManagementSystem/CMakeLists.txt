cmake_minimum_required(VERSION 3.23)
project(TransportManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransportManagementSystem
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
        travel_cards/travelCard.cpp
        travel_cards/travelCard.h
        travel_cards/travelCardsManager.cpp
        travel_cards/travelCardsManager.h
        tms/tms.cpp
        tms/tms.h
        tms/tui/tui.cpp
        tms/tui/tui.h)

target_include_directories(TransportManagementSystem PRIVATE bus_stop date person tms vehicle travel_cards)
