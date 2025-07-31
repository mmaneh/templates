#include <iostream>
#include <iomanip>
template <typename T>
void printArray(T * arr, int size) {
	for( int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<>
void printArray<int> (int * arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";	
	}
	std::cout << std::endl;
}

template<>
void printArray<double> (double * arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
	}
	std::cout << std::endl;
}
template<>
void printArray<char> (char * arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);
	
	double arr2[] = {1.567, 22.457, 3.23456, 234.3456, 34.987};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	printArray(arr2, size2);
	
	char arr3[] = {'a', 'b', 'c', 'd'};
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	printArray(arr3, size3);
	
	return 0;
}