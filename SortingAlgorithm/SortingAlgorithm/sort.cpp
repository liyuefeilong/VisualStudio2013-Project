#include "SortingFunctions.h"

using namespace std;

int main()
{
	SortingFunctions sort;  // 定义一个实体
	srand(time(NULL));
	int num = 50000;		// 待排序数组大小
	int a[50000];
	int b[50000];
	for (int i = 0; i < num; ++i)
	{
		a[i] = rand() % 100000; // 随机生成待排序样本
		b[i] = 0;
	}

	// 排序算法计时
	long start = clock();
	//sort.bubble(a, num);
	//sort.selectionSort(a, num);
	//sort.insertSort(a, num);
	//sort.shellSort(a, num);
	//sort.mergeSort(a, b, 0, num - 1);
	//sort.quickSort(a, 0, num - 1);
	sort.maxHeapSort(a, num);

	long finish = clock();
	double totaltime = (double)(finish - start) / CLOCKS_PER_SEC; // 算法耗时计算
	for (int i = 0; i<num; i++)
		cout << a[i] << "  ";
	cout << endl;
	cout << "算法耗时：" << totaltime << 's';
	cout << endl;
	getchar();
	return 0;
}