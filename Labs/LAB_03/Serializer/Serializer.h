//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_SERIALIZER_SERIALIZER_H_
#define LABS_LAB_03_SERIALIZER_SERIALIZER_H_

#include <iostream>

class Serializer {
 public:
  virtual std::string Serialize() = 0;
  virtual std::string SerializeHeader() = 0;
};

#endif //LABS_LAB_03_SERIALIZER_SERIALIZER_H_
