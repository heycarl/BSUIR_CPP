//
// Created by Alexandr on 11/6/2022.
//

#ifndef TRAVELCARDSMANAGER_H_
#define TRAVELCARDSMANAGER_H_

#include <iostream>
#include <list>

#include "manager.h"
#include "travel_card.h"

class travel_cards_manager : public manager {
private:
	std::list<travel_card> travel_cards;
public:
	void create_if_not_exists(UID);
	travel_card& find_travel_card(UID);
	static bool validator(travel_card&);
	void load_db(const std::string&) override;
	void save_db(const std::string&) override;
};

#endif //TRAVELCARDSMANAGER_H_
