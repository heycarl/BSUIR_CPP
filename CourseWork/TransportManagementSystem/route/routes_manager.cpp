//
// Created by Alexandr on 11/27/2022.
//

#include "routes_manager.h"
route& routes_manager::add_route(UID vehicle, UID driver, std::string src_point, std::string dst_point)
{
	auto new_route = route(0, 0, src_point, dst_point);
	l_routes.push_front(new_route);
	return l_routes.front();
}
route& routes_manager::find_route(UID uid_to_find)
{
	for (auto& route : l_routes) {
		if (route.get_uid()==uid_to_find)
			return route;
	}
	throw std::runtime_error("No such stop_list");
}
std::string routes_manager::serialize_all_routes_path()
{
	std::stringstream ss;
	ss << "--------------------------\n";
	for (auto& route : l_routes) {
		ss << route.serialize_route() << std::endl;
	}
	ss << "--------------------------\n";
	return ss.str();
}
void routes_manager::save_db(const std::string& db)
{
	std::ofstream ofs(db);
	if (!ofs.is_open())
		return;
	boost::archive::text_oarchive oa(ofs);
	oa & l_routes;
	ofs.close();
}
void routes_manager::load_db(const std::string& db)
{
	std::ifstream ifs(db);
	if (!ifs.is_open())
		return;
	boost::archive::text_iarchive ia(ifs);
	ia & l_routes;
	ifs.close();
}
