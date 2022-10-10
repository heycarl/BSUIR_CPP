//
// Created by Alexandr on 9/22/2022.
//

#ifndef LABS_LAB_02_STRING_STRING_H_
#define LABS_LAB_02_STRING_STRING_H_

#include <cstring>
#include <iostream>

class String {
 public:
  String();
  String(const String& arg_string);
  explicit String(char *arg_string);

  String &operator=(char *arg_string);
  String &operator=(const String &arg_string);
  char operator[](int arg_index);
  char *operator()(int arg_left_index, int arg_right_index);
  String &operator+(const String &arg_string);
  String &operator+=(const String &arg_string);
  bool operator==(const String &arg_string);
  bool operator!=(const String &arg_string);

  [[nodiscard]] char *GetString() const;
  [[nodiscard]] int GetLength() const;
  void Append(const String &arg_string);

  ~String();

 public:
 private:
  char *m_String;
  size_t m_Length = 0;
};

#endif //LABS_LAB_02_STRING_STRING_H_
