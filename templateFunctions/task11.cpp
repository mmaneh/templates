#include <iostream>
template <typename T>
T summary (T* arr, int size) {
	T sum = 0;
	for (int i = 0; i < size; ++i){ 
		sum += arr[i];
	}
	return sum;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Sum of integers: " << summary(arr, size) << std::endl;

	double arr2[] = {1.5, 2.5, 3.5, 4.5, 5.5};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "Sum of doubles: " << summary(arr2, size2) << std::endl;
	
	float arr3[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	std::cout << "Sum of floats: " << summary(arr3, size3) << std::endl;
	return 0;
}