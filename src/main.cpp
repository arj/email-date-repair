#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <streambuf>

#include <sys/stat.h>
#include <cstdio>
#include <time.h>
#include <utime.h>

#include "config.h"
#include "email.h"

using std::cout;
using std::endl;

void printSet(const std::unordered_set<string> set) {
    for (auto it = set.begin(); it != set.end(); ++it) {
        std::cout << *it << std::endl;
    }
}


void setTime(const char* filename) {
    struct stat fstat;
    struct utimbuf new_times;

    if (stat(filename, &fstat) < 0) {
        perror(filename);
        return;
    }

    new_times.actime = fstat.st_atime;
    new_times.modtime = time(NULL);
    if (utime(filename, &new_times) < 0) {
        perror(filename);
        return;
    }
}


int main(int argv, char** argc) {

    if (argv < 2) {
        std::cerr << "Please give filename" << std::endl;
        return -1;
    }

    std::string filename(argc[1]);

    std::ifstream t(filename);

    if (!t.good()) {
        std::cerr << "Could not open file \"" + filename << "\"" << std::endl;
        return -1;
    }

    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    Email email(str);

    cout << "Date:";
    printSet(*(email.header("Date")));

    setTime(filename.c_str());

    return 0;
}
