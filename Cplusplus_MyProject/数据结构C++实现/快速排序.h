#pragma once
#ifndef _HEAD_D
#define _HEAD_D

template<typename T>
void print(T a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

template<typename T>
void swap(T a[], int x, int y) {
	if (x != y) {
		a[x] = a[x] + a[y];
		a[y] = a[x] - a[y];
		a[x] = a[x] - a[y];
	}
	else {
		T temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
}

// 快排(将第一个数作为基准数)
template<typename T>
void QuickSort(T a[], int left, int right) {
	if (left < right) {
		int i = left;
		int j = right;
		int temp = a[left];
		while (i < j) {
			while (i < j && a[j] >= temp) {
				j--;
			}
			if (i < j) {
				a[i++] = a[j];
			}
			while (i < j && a[i] < temp) {
				i++;
			}
			if (i < j) {
				a[j--] = a[i];
			}
		}
		a[i] = temp;
		// 调整目标左边数据
		QuickSort(a, left, i - 1);
		// 调整目标右边数据
		QuickSort(a, i + 1, right);
	}
}

#endif // !_HEAD_D
