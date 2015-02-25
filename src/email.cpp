#include "email.h"

using std::string;
using std::unordered_map;

Email::Email(const string& email) {
    header.emplace("From","test@example.com");
    body = "Empty";
}

const headermap Email::header1() const {
    return header;
}
