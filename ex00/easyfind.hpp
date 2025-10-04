#ifndef EASYFIND_HPP
#define EASYFIND_HPP
// include
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value);
// Implementation files
#include "easyfind.tpp"
#endif