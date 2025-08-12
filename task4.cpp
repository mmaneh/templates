#include <string>
#include <vector>
#include <iostream>
#include <sstream>


std::string toString(int value) {
    return std::to_string(value);
}


std::string toString(const std::string& value) {
    return value;
}


std::string toString(const char* value) {
    return std::string(value);
}

template<typename T>
std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::vector<std::string> toStringVector(T value) {
    return { toString(value) };
}

template<typename T, typename... Args>
std::vector<std::string> toStringVector(T value, Args... args) {
    auto vec = toStringVector(value);
    auto rest = toStringVector(args...);
    vec.insert(vec.end(), rest.begin(), rest.end());
    return vec;
}

template <typename... Args>
std::string format(const std::string& fmt, Args... args) {
    std::vector<std::string> argsVec = toStringVector(args...);
    std::string result = fmt;

    size_t pos = 0;
    size_t argIdx = 0;

    while (true) {
        pos = result.find("{}", pos);

        if (argIdx >= argsVec.size()) {
            break;
        }

        result.replace(pos, 2, argsVec[argIdx]);
        pos += argsVec[argIdx].size();
        ++argIdx;
    }

    return result;
}

int main() {
    std::cout << format("Hello, {}! You have {} messages.", "Alice", 3) << "\n";
   
}

