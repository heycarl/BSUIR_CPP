//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_LAPTOP_LAPTOP_H_
#define LABS_LAB_03_LAPTOP_LAPTOP_H_

#include "../Portable/Portable.h"
#include "../Serializer/Serializer.h"
class Laptop : public Portable, public Serializer{
 protected:
  int m_KeyNum = 30;
 public:
  int GetKeyNum() const;
  void SetKeyNum(int arg_key_num);
  std::string Serialize() override;
  std::string SerializeHeader() override;
};

#endif //LABS_LAB_03_LAPTOP_LAPTOP_H_
