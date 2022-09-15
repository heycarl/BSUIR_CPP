#pragma once

#include <string>

class Date
{
private:
    std::string date;
public:
    Date() = default;
    void SetDate(std::string date);
    std::string GetDate();
    ~Date() = default;
};