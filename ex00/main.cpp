#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <iostream>

template <typename Container>
void run_container(size_t len, int valueToFind){
    Container container;
    for (size_t i = 0; i < len; ++i)
        container.push_back(static_cast<int>(i));
    try{
        typename Container::iterator it = easyfind(container, valueToFind);
        std::cout << "The value found in container: " << *it << std::endl;
    } catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }   
}

int main(int ac, char** av) {
    if (ac != 4) {
        std::cout << "Usage: " << av[0] << " <container type> <len> <find>" << std::endl;
        std::cout << "Container types: vector, list, deque" << std::endl;
        return 1;
    }
    std::string containerType = av[1];
    size_t      len           = strtol(av[2], 0, 10);
    int         valueToFind   = strtol(av[3], 0, 10);
    if (containerType == "vector") 
        run_container<std::vector<int> >(len, valueToFind);
     else if (containerType == "list") 
        run_container<std::list<int> >(len, valueToFind);
     else if (containerType == "deque") 
        run_container<std::deque<int> >(len, valueToFind);

    return 0;
}