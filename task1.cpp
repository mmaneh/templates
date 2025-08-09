#include <iostream>

auto max_variadic() {
    return 0.0;
}

template<typename T, typename... Types>
auto max_variadic(T first, Types... args) {
    using Common = typename std::common_type<T, Types...>::type;
    Common val = first;
    ((val = (val > args ? val : args)), ...);
    return val;
}

int main() {
    std::cout << max_variadic(1, 2.3, 5, 4, 6.8) << std::endl;
    return 0;
}
