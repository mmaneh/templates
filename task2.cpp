#include <iostream>

template <typename T,typename ... Types>
void printWithSeperation(std::string sep, T first, Types ... args) {
	std::cout << first;
	if constexpr ((sizeof...(args)) > 0) {
		std::cout << sep;
		printWithSeperation(sep, args...);
	}else  return;
	std::cout << std::endl;
}

std::string upper(const std::string& s) {
    std::string result = s;
    for (std::size_t i = 0; i < result.size(); ++i) {
        result[i] = std::toupper(result[i]);
    }
    return result;
}

std::string compress(const std::string& s) {
    std::string result;
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            result += s[i];
        }
    }
    return result;
}
void printWithUppercase(const std::string& s) {
	std::cout << upper(s) << std::endl;
}
void printTheCompressed(const std::string& s) {
    std::cout << compress(s) << std::endl;
}

int main() {
	printWithSeperation(" ", "hello", "world");
	printTheCompressed("     hello   wold    !!!!!");
	printWithUppercase( "Hello World");
}
