#include "adder.h"
#include <iostream>

int main() {
    std::cout << "1 + 2 = " << NewMath::add(1, 2) << std::endl;
    std::cout << "3.0 + 4.0 = " << NewMath::add(3.0f, 4.0f) << std::endl;
    return 0;
}