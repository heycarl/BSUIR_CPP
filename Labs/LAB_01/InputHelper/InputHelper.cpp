//
// Created by Alexandr on 9/16/2022.
//
#include <iostream>
#include <limits>

#include "InputHelper.h"

using namespace std;

const string InputHelper::m_ErrorText = "Invalid input, try again";

int InputHelper::InputInteger(const string &arg_HelpText) {
  int l_InputInt;
  do {
    cout << arg_HelpText;
    cin >> l_InputInt;

    if (cin.fail()) {
      cout << m_ErrorText << std::endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (l_InputInt <= 0) {
      cout << m_ErrorText << endl;
    } else {
      return l_InputInt;
    }
  } while (true);
}

float InputHelper::InputFloat(const string &arg_HelpText) {
  float l_InputFloat;
  do {
    cout << arg_HelpText;
    cin >> l_InputFloat;

    if (cin.fail()) {
      cout << m_ErrorText << std::endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (l_InputFloat <= 0) {
      cout << m_ErrorText << endl;
    } else {
      return l_InputFloat;
    }
  } while (true);
}

string InputHelper::InputString(const string &arg_HelpText) {
  string l_InputString;
  do {
    cout << arg_HelpText;
    cin >> l_InputString;

    if (cin.fail()) {
      cout << m_ErrorText << endl;
      cin.clear();
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    } else {
      return l_InputString;
    }
  } while (true);
}