#include <string>
#include <iostream>
template <typename T>
T findMax (T a, T b) {
	return (a > b) ? a : b;
}

template<typename T>
T findMin(T a, T b) {
	return (a < b) ? a : b;
}

int main() {
	int a = 5, b = 17;
	double x = 3.14, y = 34.5;
	std::string str1 = "hi", str2 = "hello";
	std::cout << "Max of integers: " << findMax(a, b) << std::endl;
	std::cout << "Min of integers: " << findMin(a, b) << std::endl;
	std::cout << "Max of doubles: " << findMax(x, y) << std::endl;
	std::cout << "Min of doubles: " << findMin(x, y) << std::endl;
	std::cout << "Max of strings: " << findMax(str1, str2) << std::endl;
	std::cout << "Min of strings: " << findMin(str1, str2) << std::endl;
	return 0;
	
}