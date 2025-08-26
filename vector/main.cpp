#include <iostream>
#include "vector.hpp"
int main() {
    MyVector<int> vec;
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    std::cout << vec.size_() << std::endl;
    vec.insert(2, 7);
    for (MyVector<int>::size_type i = 0; i < vec.size_(); ++i) {
        std::cout << vec[i] << std::endl;
    }
}
