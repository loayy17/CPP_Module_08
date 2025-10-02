#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"
#include <algorithm>
#include <stdexcept>
// the t is container type 
// value is the integer to find
// kinds of containers: unsorted, sorted, associative, Sequence 
// 1) Sequence containers: array , vector, deque, forward_list, list
// 2) Associative containers: set, map, multiset, multimap
// 3) Unordered associative containers: unordered_set, unordered_map, unordered_multiset, unordered_multimap
// 4) Container adaptors: stack, queue, priority_queue

template <typename T> 
typename T::iterator easyfind(T& container , int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}
#endif