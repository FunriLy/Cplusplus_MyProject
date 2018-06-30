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
void QuickSort(T a[], int size) {
	Quick(a, 0, size - 1);
}

template<typename T>
void Quick(T a[], int left, int right) {
	if (left < right) {
		int i = left;
		int j = right;
		int temp = a[left];
		while (i < j) {
			while (i < j && a[j] > temp) {
				j--;
			}
			while (i < j && a[i] < temp) {
				i++;
			}
			if (i < j) {
				a[j--] = a[i];
			}
		}

		if (i == j) {
			a[i] = temp;
		}
		Quick(a, left, i - 1);
		Quick(a, i + 1, right);
	}
}

template<typename T>
int BinarySearch(const T a[], int start, int end, const T &value) {
	if (start > end) {
		return -1;
	}
	int middle = (start + end) / 2;
	if (a[middle] == value) {
		return middle;
	}
	if (a[middle] < value) {
		return BinarySearch(a, middle + 1, end, vlaue);
	}
	else {
		return BinarySearch(a, start, middle - 1, value);
	}
}

template<typename T>
int BinarySearch(const T a[], int size, const T &value) {
	if (a == nullptr || size <= 0) {
		return -1;
	}
	return BinarySearch(a, 0, size - 1, value);
}

#endif