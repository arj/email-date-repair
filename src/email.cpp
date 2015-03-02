#include "email.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using std::string;
using std::unordered_multimap;

using headermapval = headermap::value_type;

Email::Email(const string& email) {
    parseEmail(email);
}

bool isPrefix(string const& prefix, std::string const& str )
{
    return std::equal(
            prefix.begin(),
            prefix.begin() + std::min(prefix.size(), str.size() ),
            str.begin());
}

std::string trim(const std::string &s)
{
    auto wsfront = std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
    auto wsback  = std::find_if_not(s.rbegin(),s.rend(),[](int c){return std::isspace(c);}).base();
    return (wsback <= wsfront ? std::string() : std::string(wsfront,wsback));
}

std::pair<const string,string> Email::parseHeaderLine(const string& line) const {
    auto colon = line.find(":");

    if (colon == std::string::npos) {
        std::cerr << line << std::endl;
        throw std::domain_error("Header contains invalid line without colon: " + line);
    }

    string key = line.substr(0, colon);
    string val = trim(line.substr(colon+1, line.length()));

    return std::make_pair(key, val);
}

void Email::parseEmail(const string& email) {
    header_ = std::make_shared<headermap>();

    std::istringstream emailstream(email);

    string lastline;
    string line;

    while (std::getline(emailstream, line)) {
        if (line.length() == 0) {
            break;
        } else {
            if (line.front() == ' ' || line.front() == '\t') {
                lastline = lastline + " " + line;
            } else {
                if (lastline.length() > 0) {
                    header_->insert(parseHeaderLine(lastline));
                }
                lastline = line;
            }
        }
    }

    if (lastline.length() > 0) {
        header_->insert(parseHeaderLine(lastline));
    }

    body_ = email.substr(emailstream.tellg(), email.length());
}

std::unique_ptr<std::unordered_set<string>> Email::header(const string& key) const {
    auto result = header_->equal_range(key);

    auto p = new std::unordered_set<string>();

    for_each(result.first, result.second, [&](headermapval& x){p->emplace(x.second);});

    return std::unique_ptr<std::unordered_set<string> > (p);
}

std::shared_ptr<const headermap> Email::header() const {
    return header_;
}

const string& Email::body() const {
    return body_;
}
