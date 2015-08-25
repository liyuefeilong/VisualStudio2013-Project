#include "SortingFunctions.h"

using namespace std;

// ð������(bubble sorting)
// ���ʱ����ۣ���(n^2)
// ��Сʱ����ۣ���(n^2)
// ƽ��ʱ����ۣ���(n^2)
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

// ѡ������(selection sorting)
// ���ʱ����ۣ���(n^2)
// ��Сʱ����ۣ���(n^2)
// ƽ��ʱ����ۣ���(n^2)
void SortingFunctions::selectionSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		// ��ѭ����ÿ��ѭ��ʱ�ҳ���array[min]С��Ԫ�أ��������긳��min��Ϊ�µ���СԪ��ֵ
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		swap(array[i], array[min]);
	}
}

// ��������(insert sorting)
// ���ʱ����ۣ���(n^2)
// ��Сʱ����ۣ���(n)
// ƽ��ʱ����ۣ���(n^2)
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

// ϣ������(shell sorting)
// ƽ��ʱ����ۣ���(n^1.5) ����ÿ�γ���2�������
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

// ���������һ��ѭ���Ӻ���
// ����ֵ�ŵ�������ʵ���λ��
int SortingFunctions::partition(int array[], int left, int right)
{
	int pivot = (left + right) / 2;
	int tmp = array[pivot];
	swap(array[pivot], array[right]); // ����ֵ�ŵ�����
	int i = left;
	int j = right;
	while (1)
	{
		// ���ָ��i�����ƶ���ֱ���ҵ�һ��������ֵtmp��ֵ
		while (1)
		{
			// ���i��j������ȷ����ֵλ�ã�����ǰ�±귵��
			if (i == j)
			{
				array[i] = tmp;
				return i;
			}
			// ����ֵ���Ԫ�ش�����ֵ��������ֵ�ұ�j�±�Ԫ�ػ���
			if (array[i]>tmp) 
			{
				array[j] = array[i];
				j--;
				break;
			}
			i++;
		}
		// �ұ�ָ��j�����ƶ���ֱ���ҵ�һ��С����ֵtmp��ֵ
		while (1)
		{
			// ���i��j������ȷ����ֵλ�ã�����ǰ�±귵��
			if (i == j)
			{
				array[j] = tmp;
				return j;
			}
			// ����ֵ�ұ�Ԫ��С����ֵ��������ֵ����i�±�Ԫ�ػ���
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

// ��������(quick sorting)
// ���ʱ����ۣ���(n^2)
// ��Сʱ����ۣ���(n*logn)
// ƽ��ʱ����ۣ���(n*logn)
// ���������˻���ð������
void SortingFunctions::quickSort(int array[], int left, int right)
{
	if (right <= left)
		return;
	int pivot = SortingFunctions::partition(array, left, right);
	quickSort(array, left, pivot - 1);
	quickSort(array, pivot + 1, right);
}

// �鲢�����Ӻ���
// ��������������ϲ���һ����������
void SortingFunctions::merge(int array[], int temp[], int left, int right)
{
	;
}

// �鲢����(merge sorting)
// ���ʱ����ۣ���(n*logn)
// ��Сʱ����ۣ���(n*logn)
// ƽ��ʱ����ۣ���(n*logn)
void SortingFunctions::mergeSort(int array[], int temp[], int left, int right)
{
	int middle = (left + right) / 2;
	if (left >= right) return;
	mergeSort(array, temp, left, middle);
	mergeSort(array, temp, middle + 1, right);
	for (int i = left; i <= right; i++)
		temp[i] = array[i];
	// ��ǰ��������
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

// ���ֵ�ѵ�������
// ���ڲ����ɾ�����е���ֵʱ����ѵĲ���
void SortingFunctions::maxHeapFix(int a[], int n, int i)
{
	int j, temp;
	temp = a[i];
	j = i * 2 + 1; // �ڵ�i���ӽڵ�Ϊ i*2+1, i*2+2  
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

void SortingFunctions::maxHeap(int a[], int n)  // �������ֵ�Ѻ���
{
	for (int i = n / 2 - 1; i >= 0; i--) // �����������(n / 2 - 1)��Ϊ��Ҷ�ڵ�
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

