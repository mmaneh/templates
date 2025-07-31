#include <iostream>
template <typename T>
bool areArraysEqual(T* arr1, T* arr2, int size) {
	for (int i = 0; i < size; ++i) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 2, 3, 4, 5};
	int arr3[] = {1, 2, 3, 4, 6};
	int size = sizeof(arr1) / sizeof(arr1[0]);

	if (areArraysEqual(arr1, arr2, size)) {
		std::cout << "arr1 and arr2 are equal." << std::endl;
	} else {
		std::cout << "arr1 and arr2 are not equal." << std::endl;
	}

	if (areArraysEqual(arr1, arr3, size)) {
		std::cout << "arr1 and arr3 are equal." << std::endl;
	} else {
		std::cout << "arr1 and arr3 are not equal." << std::endl;
	}

	return 0;
}