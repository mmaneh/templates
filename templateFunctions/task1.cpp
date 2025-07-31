#include <iostream>
#include <cctype> 
template <typename T>
void printValue(T value) {
	std::cout << "Unknown type"<< std::endl;
}

template<>
void printValue<int>(int value) {
	std::cout << "Integer value: " << value << std::endl;
}

template<>
void printValue<const char*>(const char* value) {
	std::cout << "String value: ";
	for(int i = 0; value[i] != '\0'; ++i) {
		std::cout << (char)toupper(value[i]);
	}
	std::cout << std::endl;
}

int main() {
	printValue(15);
	printValue("hello world");
	//double d = 67.909;
	//printValue(d);

	return 0;
}