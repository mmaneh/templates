#include <string>
#include <iostream>
template <typename T>
int hashValue (T value) {
	return 0;
}


template <>
int hashValue<int>(int value) {
	return value;
}

template <>
int hashValue<std::string>(std::string value) {
	int hash = 0;
	for (char c : value ) {
		hash += static_cast<int>(c);
	}
} 

int main() {
	int a = 10;
	double d = 3.14;
	std::string str = "hi";
	char * cstr = "hello";
	char c = 'x';
	std::cout << "Hash of integer: " << hashValue(a) << std::endl;
	std::cout << "Hash of double: " << hashValue(d) << std::endl;
	std::cout << "Hash of string: " << hashValue(str) << std::endl;
	std::cout << "Hash of C-style string: " << hashValue(cstr) << std::endl;
	std::cout << "Hash of char: " << hashValue(c) << std::endl;
	
	return 0;
}