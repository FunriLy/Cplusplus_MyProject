#pragma once
#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
void print(T a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

template<typename T>
void swap(T n[], int a, int b) {
	n[a] = n[a] + n[b];
	n[b] = n[a] - n[b];
	n[a] = n[a] - n[b];
}

// 冒泡排序
template<typename T>
void BubbleSort(T a[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a, j, j + 1);
			}
		}
	}
}

// 简单选择排序
template<typename T>
void SelectSort(T a[], int size) {
	int i, j, min;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		// 找到最小的值并进行交换
		if (min != i) {
			swap(a, min, i);
		}
	}
}

// 直接插入排序
template<typename T>
void InsertSort(T a[], int size) {
	int i, j;
	for (i = 1; i < size; i++) {
		if (a[i] < a[i - 1]) {
			int temp = a[i];
			for (j = i - 1; a[j] > temp; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}
	}
}


#endif // !_HEAD_H
