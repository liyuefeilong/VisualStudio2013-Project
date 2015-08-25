#include "SortingFunctions.h"

using namespace std;

// 冒泡排序(bubble sorting)
// 最大时间代价：θ(n^2)
// 最小时间代价：θ(n^2)
// 平均时间代价：θ(n^2)
void SortingFunctions::bubble(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > 1; j--)
		{
			if (array[j] < array[j - 1])
				swap(array[j], array[j - 1]);
		}
	}
}

// 选择排序(selection sorting)
// 最大时间代价：θ(n^2)
// 最小时间代价：θ(n^2)
// 平均时间代价：θ(n^2)
void SortingFunctions::selectionSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		// 内循环，每次循环时找出比array[min]小的元素，将其坐标赋给min作为新的最小元素值
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		swap(array[i], array[min]);
	}
}

// 插入排序(insert sorting)
// 最大时间代价：θ(n^2)
// 最小时间代价：θ(n)
// 平均时间代价：θ(n^2)
void SortingFunctions::insertSort(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
				swap(array[j - 1], array[j]);
			else
				break;
		}
	}
}

// 希尔排序(shell sorting)
// 平均时间代价：θ(n^1.5) 增量每次除以2的情况下
void SortingFunctions::shellSort(int array[], int n)
{
	int i, j, k, l;
	for (i = n / 2; i > 0; i /= 2)
	{
		for (j = 0; j < i; j++)
		{
			for (k = j + i; k < n; k += i)
			{
				for (l = k; l > i; )
				{
					if (array[l] < array[l - i])
					{
						swap(array[l], array[l - i]);
						l -= i;
					}

					else
					{
						l -= i; break;
					}
				}
			}
		}
	}
}

// 快速排序的一次循环子函数
// 将轴值放到数组的适当的位置
int SortingFunctions::partition(int array[], int left, int right)
{
	int pivot = (left + right) / 2;
	int tmp = array[pivot];
	swap(array[pivot], array[right]); // 把轴值放到最右
	int i = left;
	int j = right;
	while (1)
	{
		// 左边指针i向右移动，直到找到一个大于轴值tmp的值
		while (1)
		{
			// 如果i与j相遇则确定轴值位置，将当前下标返回
			if (i == j)
			{
				array[i] = tmp;
				return i;
			}
			// 若轴值左边元素大于轴值，则与轴值右边j下标元素互换
			if (array[i]>tmp) 
			{
				array[j] = array[i];
				j--;
				break;
			}
			i++;
		}
		// 右边指针j向左移动，直到找到一个小于轴值tmp的值
		while (1)
		{
			// 如果i与j相遇则确定轴值位置，将当前下标返回
			if (i == j)
			{
				array[j] = tmp;
				return j;
			}
			// 若轴值右边元素小于轴值，则与轴值坐边i下标元素互换
			if (array[j]<tmp)
			{
				array[i] = array[j];
				i++;
				break;
			}
			j--;
		}
	}
}

// 快速排序(quick sorting)
// 最大时间代价：θ(n^2)
// 最小时间代价：θ(n*logn)
// 平均时间代价：θ(n*logn)
// 最差情况下退化成冒泡排序法
void SortingFunctions::quickSort(int array[], int left, int right)
{
	if (right <= left)
		return;
	int pivot = SortingFunctions::partition(array, left, right);
	quickSort(array, left, pivot - 1);
	quickSort(array, pivot + 1, right);
}

// 归并排序子函数
// 把两个有序数组合并成一个有序数组
void SortingFunctions::merge(int array[], int temp[], int left, int right)
{
	;
}

// 归并排序(merge sorting)
// 最大时间代价：θ(n*logn)
// 最小时间代价：θ(n*logn)
// 平均时间代价：θ(n*logn)
void SortingFunctions::mergeSort(int array[], int temp[], int left, int right)
{
	int middle = (left + right) / 2;
	if (left >= right) return;
	mergeSort(array, temp, left, middle);
	mergeSort(array, temp, middle + 1, right);
	for (int i = left; i <= right; i++)
		temp[i] = array[i];
	// 分前后两部分
	int j = left; 
	int k = middle + 1;
	for (int curr = left; curr <= right; curr++)
	{
		if (j == middle + 1)
			array[curr] = temp[k++];
		else if (k > right)
			array[curr] = temp[j++];
		else if (temp[j] < temp[k])
			array[curr] = temp[j++];
		else
		{
			array[curr] = temp[k++];
		}
	}
}

// 最大值堆调整函数
// 用于插入或删除堆中的数值时重组堆的操作
void SortingFunctions::maxHeapFix(int a[], int n, int i)
{
	int j, temp;
	temp = a[i];
	j = i * 2 + 1; // 节点i的子节点为 i*2+1, i*2+2  
	while (j < n)
	{
		if (j + 1 < n && a[j] < a[j + 1])
			j++;

		if (a[j] <= temp)
			break;

		a[i] = a[j];
		i = j;
		j = i * 2 + 1;
	}
	a[i] = temp;
}

void SortingFunctions::maxHeap(int a[], int n)  // 建立最大值堆函数
{
	for (int i = n / 2 - 1; i >= 0; i--) // 数组中最多有(n / 2 - 1)个为非叶节点
		maxHeapFix(a, n, i);
}

void SortingFunctions::maxHeapSort(int a[], int n)
{
	maxHeap(a, n);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[i], a[0]);
		maxHeapFix(a, i, 0);
	}
}

