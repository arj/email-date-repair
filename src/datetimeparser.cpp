#include "datetimeparser.h"

#include <chrono>

using std::chrono::system_clock;

DateTimeParser::DateTimeParser(const std::string& text) {
    parse(text);
}

system_clock::time_point DateTimeParser::chrono() const {
    return system_clock::now();
}

void DateTimeParser::parse(const std::string& text) {
}
