#include <string>
#include <iostream>
template <typename T>
void swapValues(T& a, T& b) {
	T temp = a;
	a =b;
	b = temp;
}
int main() {
	int a = 10, b = 20;
	double x = 3.14, y = 23.543;
	std::string str1 = "Hello", str2 = "hi"; 
	swapValues(a, b);
	swapValues(x, y);
	swapValues(str1, str2);
	std::cout << "Swapped integers: " << a << ", " << b << std::endl;
	std::cout << "Swapped doubles: " << x << ", " << y << std::endl;
	std::cout << "Swapped strings: " << str1 << ", " << str2 << std::endl;
	return 0;
}