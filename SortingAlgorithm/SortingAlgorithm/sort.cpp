#include "SortingFunctions.h"

using namespace std;

int main()
{
	SortingFunctions sort;  // ����һ��ʵ��
	srand(time(NULL));
	int num = 50000;		// �����������С
	int a[50000];
	int b[50000];
	for (int i = 0; i < num; ++i)
	{
		a[i] = rand() % 100000; // ������ɴ���������
		b[i] = 0;
	}

	// �����㷨��ʱ
	long start = clock();
	//sort.bubble(a, num);
	//sort.selectionSort(a, num);
	//sort.insertSort(a, num);
	//sort.shellSort(a, num);
	//sort.mergeSort(a, b, 0, num - 1);
	//sort.quickSort(a, 0, num - 1);
	sort.maxHeapSort(a, num);

	long finish = clock();
	double totaltime = (double)(finish - start) / CLOCKS_PER_SEC; // �㷨��ʱ����
	for (int i = 0; i<num; i++)
		cout << a[i] << "  ";
	cout << endl;
	cout << "�㷨��ʱ��" << totaltime << 's';
	cout << endl;
	getchar();
	return 0;
}