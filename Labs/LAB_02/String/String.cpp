//
// Created by Alexandr on 9/22/2022.
//

#include "String.h"

String::String() {
  m_Length = 0;
  m_String = new char[m_Length];
}
String::String(const String &arg_string) {
  m_Length = arg_string.GetLength();
  m_String = new char[m_Length];
  strcpy(m_String, arg_string.GetString());
}
String::String(char *arg_string) {
  m_Length = strlen(arg_string);
  m_String = new char[m_Length];
  strcpy(m_String, arg_string);
}

String &String::operator=(char *arg_string) {
  m_Length = strlen(arg_string);
  m_String = arg_string;
  return *this;
}
String &String::operator=(const String &arg_string) {
  if (&arg_string != this) {
    m_Length = arg_string.GetLength();
    m_String = arg_string.GetString();
  }
  return *this;
}
char String::operator[](int arg_index) {
  if (!(arg_index < 0 || arg_index > m_Length)) {
    return m_String[arg_index];
  }
  return 0;
}
char *String::operator()(const int arg_left_index, const int arg_right_index) {
  int l_length = arg_right_index - arg_left_index + 1;
  if (l_length < 1 || arg_left_index < 0 || arg_right_index > m_Length)
    return (char *) "";

  char *new_slice = new char[l_length];
  strncpy(new_slice, m_String + arg_left_index, l_length);
  return new_slice;
}
String &String::operator+(const String &arg_string) {
//  size_t new_length = m_Length + arg_string.GetLength();
//  char *new_char_ptr = new char[new_length];
//
//  strcpy(new_char_ptr, m_String);
//  strcpy(new_char_ptr + m_Length, arg_string.GetString());
//
//  return *(new String(new_char_ptr));
  return operator+=(arg_string);
}
String &String::operator+=(const String &arg_string) {
  size_t new_length = m_Length + arg_string.GetLength();
  char *new_char_ptr = new char[new_length];
  strcpy(new_char_ptr, m_String);
  strcpy(new_char_ptr + m_Length, arg_string.GetString());

  m_String = new_char_ptr;
  m_Length = new_length;
//  delete []m_delete;

  return *this;
}
char *String::GetString() const {
  return m_String;
}
int String::GetLength() const {
  return (int) m_Length;
}

String::~String() {
//  delete []m_String;
}
bool String::operator==(const String &arg_string) {
  return (m_Length == arg_string.GetLength() || strcmp(m_String, arg_string.GetString()) == 0);
}
bool String::operator!=(const String &arg_string) {
  return !(operator==(arg_string));
}
void String::Append(const String& arg_string) {
  operator+=(arg_string);
}
