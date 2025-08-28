#include <iostream>
#include "list.hpp"  

int main() {
    XorLinkedList<int> list;

 
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.push_front(0);
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    list.pop_back();
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    list.pop_front();
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
