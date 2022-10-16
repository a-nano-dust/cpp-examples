

#include <iostream>     // for std::cout
#include <algorithm>    // for std::fill

#include "Integers.h"   // for Integers


int main(int argc, char** argv) {
    
    Integers integers;
    std::fill(integers.begin(), integers.end(), 3);
    for (const auto &item : integers) {
        std::cout << item << std::endl;
    }
    
    return 0;
}

