#include "../2-2/adder.h"
#include <iostream>

int main() {
    std::cout << "1 + 2 = " << MyMath::add(1,2) << std::endl;
    std::cout << "3.0 + 4.5 = " << MyMath::add(3.0f, 4.5f) << std::endl;
    return 0;
}