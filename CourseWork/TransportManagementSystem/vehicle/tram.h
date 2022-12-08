//
// Created by Alexandr on 11/22/2022.
//

#ifndef TRANSPORTMANAGEMENTSYSTEM_TRAM_H
#define TRANSPORTMANAGEMENTSYSTEM_TRAM_H

#include "vehicle.h"
#include <boost/serialization/serialization.hpp>

class tram : public vehicle {
private:
//	friend class boost::serialization::access;
//	template<class Archive>
//	void serialize(Archive& archive, const unsigned int version)
//	{
//		archive & *this;
//	}
public:
	tram() = default;
	tram(std::string, uint8_t);
};

#endif //TRANSPORTMANAGEMENTSYSTEM_TRAM_H
