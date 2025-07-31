#include <iostream>
template <typename T>
void reverseArray(T* arr, int size) {
	for(int i = 0; i < size / 2; ++i){
		T temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}
template <typename T>
void printArray(T * arr, int size) {
	for( int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main () {
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	reverseArray(arr,size);
	double arr2[] = {1.567, 22.457, 3.23456, 234.3456, 34.987};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	reverseArray(arr2, size2);
	char arr3[] = {'a', 'b', 'c', 'd'};
	int size3 = sizeof(arr3) /sizeof(arr3[0]);
	reverseArray(arr3, size3);
	std::cout << "Reversed integer array: " << std::endl;
	printArray(arr, size);
	std::cout << "Reversed double array: " << std::endl;
	printArray(arr2, size2);
	std::cout << "Reversed char array: " << std::endl; 
	printArray(arr3, size3);
	return 0;
}