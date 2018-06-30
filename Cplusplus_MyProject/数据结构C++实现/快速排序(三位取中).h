#pragma once

#ifndef _HEAD_H
#define _HEAD_H

#include<iostream>
using namespace std;

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

template<typename T>
void partation(T a[], int left, int right) {
	int mid = (left + right) / 2;
	if (a[mid] < a[left]) {
		swap(a, mid, left);
	}
	if (a[left] > a[right]) {
		// 确保左小右大
		swap(a, left, right);
	}
	if (a[mid] > a[right]) {
		swap(a, mid, right);
	}
}

template<typename T>
void QuickSort(T a[], int left, int right) {
	if (left < right) {
		int i = left;
		partation(a, left, right);
		int x = a[right - 1];
		int j = right - 2;

		while (i < j) {
			while (i < j && a[j] >= x) {
				j--;
			}
			while (i < j&&a[i] < x) {
				i++
			}
			if (i < j) {
				// 上面两个循环找到第一对不符合的坐标
				swap(a, i, j);
			}
		}

		swap(a, j + 1, right - 1);
		QuickSort(a, left, j);
		// 避开 j+1
		QuickSort(a, j + 2, right);
	}
}

template<typename T>
void QuickSort(T a[], int size) {
	if (a == nullptr) {
		return;
	}
	QuickSort(a, 0, size - 1);
}

#endif // !_HEAD_H
