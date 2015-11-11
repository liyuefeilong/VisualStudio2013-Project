#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

class Solution
{
public:
	void countingSort(int *a, int k, int len)
	{
		if (len <= 0 || k < 0) return;

		int *b = new int[len + 1];
		int *c = new int[k + 1];
		
		for (int i = 0; i <= k; ++i)	// 初始化数组c  
			c[i] = 0;

		for (int i = 0; i <= len; ++i)  // 初始化数组b  
			b[i] = 0;  		

		for (int i = 0; i < len; ++i)	// 第一步
			c[a[i]]++;

		for (int j = 1; j <= k; ++j)	// 第二步
			c[j] += c[j - 1];

		for (int j = 0; j < len; ++j)
			b[c[a[j]]--] = a[j];

		for (int j = 1; j < len + 1; ++j)
			a[j - 1] = b[j];

		delete [] b;
		delete [] c;
	}

	int * generateArray(int len, int k)    
	{    
		int i;    
		int * arr = new int[len];    
		srand((int)time(NULL));    
		for(i = 0; i < len; i++)       
			arr[i] = rand() % k;    

		return arr;    
	}   

	void showArray(int *a,int len)    
	{       
		for(int i = 0; i < len; i++)    
		{    
			cout << setw(5) << a[i] << " ";    
			if((i + 1) % 10 == 0)    
				cout << endl;        
		}    
	}

private:

};
