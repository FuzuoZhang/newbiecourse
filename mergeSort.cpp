//πÈ≤¢≈≈–Ú

#include<iostream>
#include<vector>
using namespace std;

void show(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

vector<int> mergesort(vector<int> arr) {
	int n = arr.size();
	if (n <= 1) return arr;
	int mid = n / 2 - 1;
	vector<int> arrbe(mid+1);
	vector<int> arraf(n - mid - 1);
	copy(arr.begin(), arr.begin() + mid+1, arrbe.begin());
	copy(arr.begin() + mid + 1, arr.end(), arraf.begin());
	arrbe = mergesort(arrbe);
	arraf = mergesort(arraf);
	int i, j, k;
	for (i = 0, j = 0, k = 0; i <= mid && j <= n - mid - 2;) {
		if (arrbe[i] < arraf[j]) {
			arr[k] = arrbe[i];
			i++;
		}
		else {
			arr[k] = arraf[j];
			j++;
		}
		k++;
	}
	if (i <= mid) copy(arrbe.begin() + i, arrbe.end(), arr.begin() + k);
	if (j <= n - mid - 2) copy(arraf.begin() + j, arraf.end(), arr.begin() + k);
	return arr;
}

int main() {
	int n;
	cin >> n;
	int i;
	vector<int> arr(n);
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "The arr before is: ";
	show(arr);
	vector<int> arr_sort = mergesort(arr);
	cout << "The arr sorted is: ";
	show(arr_sort);
	system("pause");
	return 0;
}