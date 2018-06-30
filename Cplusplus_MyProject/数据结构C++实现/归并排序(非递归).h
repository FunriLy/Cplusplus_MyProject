#pragma once

#include<iostream>
using namespace std;

// todo:������һ�������

template<typename T>
void print(T *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a++ << "  ";
	}
	cout << endl;
}

template<typename T>
void Merge(T *a, int left, int mid, int right, T *temp) {
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		// �ϲ���������
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		// �����һ������ʣ�ಿ��
		temp[k++] = a[i++];
	}
	while (j <= right) {
		// ����ڶ�������ʣ�ಿ��
		temp[k++] = a[j++];
	}
	// ���鸴��
	for (j = 0; j < k; j++) {
		a[left++] = temp[j++];
	}
}

template<typename T>
void MergeN(T *a, int skip, int size, T *temp) {
	int i = 0;
	while (i + 2 * skip - 1 < size) {
		Merge(a, i, i + skip - 1, i + 2 * skip - 1, temp);
		i = i + 2 * skip;
	}
	// ����ʣ�ಿ��
	if (i + skip - 1 < size) {
		Merge(a, i, i + skip - 1, size - 1, temp);
	}
}

template<typename T>
bool MergeNoRecursion(T *a, int size) {
	int skip = 1;
	T *temp = new T[size];
	if (a == nullptr || temp == nullptr) {
		return false;
	}
	while (skip < size) {
		MergeN(a, skip, size, temp);
		skip *= 2;
	}
	delete[] temp;
	return true;
}
