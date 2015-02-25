#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

typedef unordered_map<string, string> headermap;

class Email {

public:
    Email(const string& email);

    const headermap header1() const;
private:
    headermap header;
    string body;
};
