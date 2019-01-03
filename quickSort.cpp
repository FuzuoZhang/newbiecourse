#include<iostream>
using namespace std;

int boundary(int array[], int startIndex, int endIndex) {
	int standard = array[startIndex]; // 定义标准
	int leftIndex = startIndex; // 左指针
	int rightIndex = endIndex; // 右指针

	while (leftIndex < rightIndex) {
		while (leftIndex < rightIndex && array[rightIndex] >= standard) {
			rightIndex--;
		}
		array[leftIndex] = array[rightIndex];

		while (leftIndex < rightIndex && array[leftIndex] <= standard) {
			leftIndex++;
		}
		array[rightIndex] = array[leftIndex];
	}

	array[leftIndex] = standard;
	return leftIndex;
}

void sortCore(int array[], int startIndex, int endIndex) {
	if (startIndex >= endIndex) {
		return;
	}
	int bounda = boundary(array, startIndex, endIndex);
	sortCore(array, startIndex, bounda - 1);
	sortCore(array, bounda + 1, endIndex);
}

int main() {
	int * arr;
	arr = (int*) malloc(sizeof(int[7]));
	//int arr[7] = { 8,5,3,1,1,4,9 };
	for (int i = 0; i < 7; i++) {
		arr[i] = 7 - i;
	}
	sortCore(arr, 0, 6);
	for (int i = 0; i < 7; i++) cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;

}
