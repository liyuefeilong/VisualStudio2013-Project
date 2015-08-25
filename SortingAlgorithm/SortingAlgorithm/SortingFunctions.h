#ifndef SORTINGFUNCTIONS_H
#define SORTINGFUNCTIONS_H

#include <iostream>
#include <ctime>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

class SortingFunctions
{
public:
	SortingFunctions(){};
	~SortingFunctions(){};
	void bubble(int[], int);				    // ð������(bubble sorting)
	void selectionSort(int[], int);				// ѡ������(selection sorting)
	void insertSort(int[], int);				// ��������(insert sorting)
	void shellSort(int[], int);					// ϣ������(shell sorting)
	void mergeSort(int[], int[], int, int);		// �鲢����(merge sorting)
	void quickSort(int[], int, int);			// ��������(quick sorting)
	void maxHeapSort(int[], int);				// ������(Heap sorting)

private:
	int partition(int array[], int left, int right);  // ���������е���ֵ����
	void merge(int[], int[], int, int); // ��������������ϲ���һ����������
	void maxHeapFix(int[], int, int);	// ���ֵ�ѵ�������
	void maxHeap(int[], int);			// �������ֵ��
};

#endif