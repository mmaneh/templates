#include <string>
#include <cmath>
#include <iostream>
template <typename T>
T multiply(T a, T b) {
	return a * b;
}

template <>
double multiply<double>(double a, double b) {
	double res = a * b;
	return std::round(res * 100) / 100;
}
template <>
std::string multiply<std::string>(std::string a, std::string b) {
	int repeatCount = std::stoi(b);
	std::string result;
	for (int i = 0; i < repeatCount; ++i) {
		result += a;
	}
	return result;
}	

int main() {
	int a = 5, b = 10;
	double x = 3.14159, y = 2.71828;
	std::string str1 = "Hello", str2 = "4"; 

	std::cout << "Multiplying integers: " << multiply(a, b) << std::endl;	
	std::cout << "Multiplying doubles: " << multiply(x, y) << std::endl;
	std::cout << "Multiplying strings: " << multiply(str1, str2) << std::endl;

	return 0;
}
