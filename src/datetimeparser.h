#pragma once

#include <string>
#include <chrono>

using std::string;
using std::chrono::system_clock;

class DateTimeParser {

    DateTimeParser(const std::string& text);

    system_clock::time_point chrono() const;
    int day() const { return day_; }
    int month() const { return month_; }
    int year() const { return year_; }
    int hour() const { return hour_; }
    int minute() const { return minute_; }
    int second() const { return second_; }

private:
    int day_;
    int month_;
    int year_;
    int hour_;
    int minute_;
    int second_;

    void parse(const std::string& text);
};
