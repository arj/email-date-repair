#include <iostream>

#include "config.h"

using std::cout;
using std::endl;

int main(int argv, char** argc) {

    cout << argc[0] << " Version: " << VERSION_MAJOR << "." << VERSION_MINOR << endl;

    return 0;
}
