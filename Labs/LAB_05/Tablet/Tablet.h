//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_TABLET_TABLET_H_
#define LABS_LAB_03_TABLET_TABLET_H_

#include <iostream>

#include "../Portable/Portable.h"
#include "../Serializer/Serializer.h"
class Tablet : public Portable, public Serializer{
 protected:
  std::string m_Modem;
 public:
  const std::string &GetModem() const;
  void SetModem(const std::string &arg_modem);
  std::string Serialize() override;
  std::string SerializeHeader() override;
};

#endif //LABS_LAB_03_TABLET_TABLET_H_
