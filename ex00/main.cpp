#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + 5);
    try {
        int found = easyfind(vec, 3);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}