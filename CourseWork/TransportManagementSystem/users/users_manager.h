//
// Created by Alexandr on 11/26/2022.
//

#ifndef _USERS_MANAGER_H_
#define _USERS_MANAGER_H_

#include "user_passenger.h"
#include "user_admin.h"
#include "manager.h"

class users_manager : public manager {
private:
	std::list<user_passenger> l_passengers;
	std::list<user_admin> l_admins;
public:
	user_passenger& sign_up_passenger();
	user_admin& sign_up_admin();
	user_passenger& sign_in_passenger();
	user_admin& sign_in_admin();
	void ask_credentials(std::string, std::string&, std::string&);
	void save_db(const std::string&) override;
	void load_db(const std::string&) override;
};

#endif //_USERS_MANAGER_H_
