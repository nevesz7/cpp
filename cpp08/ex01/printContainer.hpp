#ifndef PRINTCONTAINER_HPP
#define PRINTCONTAINER_HPP

#include <iostream>

template<typename T>
void printContainer(T& container) {
    std::cout << "[ ";
    for (typename T::iterator iter = container.begin(); iter != container.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void printContainer(const T& container) {
    std::cout << "[ ";
    for (typename T::const_iterator iter = container.begin(); iter != container.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]" << std::endl;
}

#endif