#include <iostream>

template<typename T, typename... Types>
void print(T t) {
    std::cout << t;
}

template<typename T, typename... Types>
void print(T t, Types... args) {
    print(args...);
    std::cout << t;
}
int main() {
	print("Hello", "World", "!");
}
