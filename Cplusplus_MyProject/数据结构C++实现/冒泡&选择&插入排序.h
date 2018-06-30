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

// ð������
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

// ��ѡ������
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
		// �ҵ���С��ֵ�����н���
		if (min != i) {
			swap(a, min, i);
		}
	}
}

// ֱ�Ӳ�������
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
