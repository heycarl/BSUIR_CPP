//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_COMPUTER_COMPUTER_H_
#define LABS_LAB_03_COMPUTER_COMPUTER_H_

#include <iostream>

class Computer {
 private:
 public:
  const std::string &GetBrand() const;
  void SetBrand(const std::string &arg_brand);
  const std::string &GetModel() const;
  void SetModel(const std::string &arg_model);
 protected:
  std::string m_Brand;
  std::string m_Model;
};

#endif //LABS_LAB_03_COMPUTER_COMPUTER_H_
