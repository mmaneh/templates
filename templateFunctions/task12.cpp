#include <iostream>
template <typename T>
void sortArray(T* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for(int j = 0;  j < size - i - 1; ++j) {
			if(arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;	
			}
		}
	}
}
template <typename T>
void printArray(T * arr, int size) {
	for( int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[] = {5, 2, 9, 1, 5, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	sortArray(arr, size);
	std::cout << "Sorted integer array: ";
	printArray(arr, size);

	char arr2[] = {'d', 'a', 'c', 'b'};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	sortArray(arr2, size2);
	std::cout << "Sorted char array: ";
	printArray(arr2, size2);
	
	return 0;
}