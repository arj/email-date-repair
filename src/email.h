#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>

using std::string;
using std::unordered_multimap;

using headermap = unordered_multimap<string, string>;

class Email {

public:
    Email(const string& email);

    std::shared_ptr<const headermap> header() const;

    std::unique_ptr<std::unordered_set<string>> header(const string& key) const;

    std::pair<const string,string> parseHeaderLine(const string& line) const;
    void parseEmail(const string& email);

    const string& body() const;
private:
    std::shared_ptr<headermap> header_;
    string body_;
};
