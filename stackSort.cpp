#include<iostream>
#include<vector>
using namespace std;

void creatstack(vector<int> *arr) {
	int n = arr->size();
	int tail = n / 2 - 1;   //最后一个非叶节点的索引；
	int i;
	for (i = tail; i >= 0; i--) {
		int j = i;
		while (j <= tail) {
			int maxchi;
			if (2 * j + 2 < n) {
				maxchi = (*arr)[2 * j + 1] > (*arr)[2 * j + 2] ? (*arr)[2 * j + 1] : (*arr)[2 * j + 2];
			}
			else maxchi = (*arr)[2 * j + 1];
			if ((*arr)[j] < maxchi) {
				int temp = (*arr)[j];
				if (2 * j + 2 < n && (*arr)[2 * j + 1] < (*arr)[2 * j + 2]) {
					(*arr)[j] = (*arr)[2 * j + 2];
					(*arr)[2 * j + 2] = temp;
					j = 2 * j + 2;
				}
				else {
						(*arr)[j] = (*arr)[2 * j + 1];
						(*arr)[2 * j + 1] = temp;
						j = 2 * j + 1;
					}
					
				}
			else break;
			}		
		}
	}

//堆排序 大顶堆
vector<int> stacksort(vector<int> arr){
	int n = arr.size();
	if (n <= 1) return arr;
	creatstack(&arr);  //建堆
	int i,j,len;
	for (i = 0; i < n - 1 ; i++) {
		//swap head and tail
		int temp = arr[0];
		arr[0] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;    
		len = n - 1 - i;
		//下滤
		for (j = 0; j <= len / 2 - 1;) {
			int maxchi;
			if (2 * j + 2 < len) {
				maxchi = arr[2 * j + 1] > arr[2 * j + 2] ? arr[2 * j + 1] : arr[2 * j + 2];
			}
			else maxchi = arr[2 * j + 1];
			if (arr[j] < maxchi) {
				int temp = arr[j];
				if (2 * j + 2 < len && arr[2 * j + 1] < arr[2 * j + 2]) {
				    arr[j] = arr[2 * j + 2];
					arr[2 * j + 2] = temp;
					j = 2 * j + 2;
				}
				else {
				    arr[j] = arr[2 * j + 1];
					arr[2 * j + 1] = temp;
					j = 2 * j + 1;
				}
			}
			else break;
		}
	}
	return arr;
}


void showarr(vector<int> arr) {
	vector<int>::iterator i;
	for (i = arr.begin(); i != arr.end(); i++) {
		cout << *i<<" ";
	}
	cout << endl;
}

int main() {
	int n;  //length of arr
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Ending input.";
	cout << "The arr before is:" << endl;
	showarr(arr);
	vector<int> sort_arr = stacksort(arr);
	cout << "The arr sorted is:" << endl;
	showarr(sort_arr);
	system("pause");
	return 0;
}