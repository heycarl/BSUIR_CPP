//
// Created by Alexandr on 9/16/2022.
//

#ifndef LABS_INPUTHELPER_INPUTHELPER_H_
#define LABS_INPUTHELPER_INPUTHELPER_H_

#include <iostream>

class InputHelper {
 public:
  static int InputInteger(const std::string &arg_HelpText);
  static float InputFloat(const std::string &arg_HelpText);
  static std::string InputString(const std::string &arg_HelpText, int arg_req_min_len, int arg_req_max_len);
  static std::string InputString(const std::string &arg_HelpText, int arg_req_max_len);
 private:
  static const std::string m_ErrorText;
};

#endif //LABS_INPUTHELPER_INPUTHELPER_H_
