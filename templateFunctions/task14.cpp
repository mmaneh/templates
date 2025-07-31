#include <iostream>

template <typename T>
void generateMultiplicationTable(T value, int n) {
	for (int i = 1; i <= n; ++i) {
		std::cout << value << " * " << i << " = " << value * i << std::endl;
	}
}

int main() {
	int n = 10; 
	int a = 5;
	double d = 3.14;

	generateMultiplicationTable(a, n);
	generateMultiplicationTable(d, n);

	return 0;
}