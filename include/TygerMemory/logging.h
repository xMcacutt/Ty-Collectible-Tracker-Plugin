#pragma once

#include <string>

class Logging {
public:
    static void del();
    static void log(const std::string& message);
};
