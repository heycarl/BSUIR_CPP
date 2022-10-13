//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_DESKTOP_DESKTOP_H_
#define LABS_LAB_03_DESKTOP_DESKTOP_H_

#include <iostream>

#include "../Computer/Computer.h"

class Desktop : public Computer{
 protected:
  std::string m_Case;
 public:
  const std::string &GetCase() const;
  void SetCase(const std::string &arg_case);
};

#endif //LABS_LAB_03_DESKTOP_DESKTOP_H_
