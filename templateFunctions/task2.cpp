#include <cstring>
#include <string>
#include <iostream>
template <typename T>
int compareValues(T a, T b) {
	return (a > b) ? 1 : (a < b) ? -1 : 0;
}

template <>
int compareValues<const char*>(const char* a, const char* b) {
	return strcmp(a, b) < 0 ? -1 : strcmp(a, b) > 0 ? 1 : 0;
}

template <>
int compareValues<std::string>(std::string a, std::string b) {
	return a.compare(b) < 0 ? -1 : a.compare(b) > 0 ? 1 : 0;
}

int main() {
	int a = 15;
	int b = 20;
	const char * str1 = "hi";
	const char * str2 = "hello";
	std::string s1 = "academy";
	std::string s2 = "university";
	std::cout << "Comparing integers: " << compareValues(a, b) << std::endl;	
	std::cout << "Comparing c-type strings: " << compareValues(str1, str2) << std::endl;
	std::cout << "Comparing strings: " << compareValues(s1, s2) << std::endl;
	return 0;
}	