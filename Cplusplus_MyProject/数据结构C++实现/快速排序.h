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

// ����(����һ������Ϊ��׼��)
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
		// ����Ŀ���������
		QuickSort(a, left, i - 1);
		// ����Ŀ���ұ�����
		QuickSort(a, i + 1, right);
	}
}

#endif // !_HEAD_D
