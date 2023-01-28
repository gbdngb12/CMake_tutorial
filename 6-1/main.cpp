#include <rapidfuzz/fuzz.hpp>
#include <iostream>

int main() {
    // score is 100
    double score = rapidfuzz::fuzz::partial_ratio("this is a test", "this is a test!");
    std::cout << "rapidfuzz score" << score << std::endl;
    return 0;
}