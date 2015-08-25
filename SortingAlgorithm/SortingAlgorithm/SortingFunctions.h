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
	void bubble(int[], int);				    // 冒泡排序(bubble sorting)
	void selectionSort(int[], int);				// 选择排序(selection sorting)
	void insertSort(int[], int);				// 插入排序(insert sorting)
	void shellSort(int[], int);					// 希尔排序(shell sorting)
	void mergeSort(int[], int[], int, int);		// 归并排序(merge sorting)
	void quickSort(int[], int, int);			// 快速排序(quick sorting)
	void maxHeapSort(int[], int);				// 堆排序(Heap sorting)

private:
	int partition(int array[], int left, int right);  // 快速排序中的轴值操作
	void merge(int[], int[], int, int); // 把两个有序数组合并成一个有序数组
	void maxHeapFix(int[], int, int);	// 最大值堆调整函数
	void maxHeap(int[], int);			// 建立最大值堆
};

#endif