//
// Created by Alexandr on 12/8/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_MANAGER_H
#define TRANSPORTMANAGEMENTSYSTEM_MANAGER_H

#include <fstream>

#include <boost/serialization/list.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class manager {
public:
	virtual void save_db(const std::string&) = 0;
	virtual void load_db(const std::string&) = 0;
};

#endif //TRANSPORTMANAGEMENTSYSTEM_MANAGER_H
