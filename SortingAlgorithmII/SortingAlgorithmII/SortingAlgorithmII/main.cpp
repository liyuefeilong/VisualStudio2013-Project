#include "SortingAlgorithm.h"

int main()
{
	int len, k;  
    cout <<	"Please input the length of Array: " << endl;  
    cin >> len;  
    cout << "Please input the of range the Number(k <= len): " << endl;  
    cin >> k;

	Solution s;
    int * arr = s.generateArray(len, k);    
    cout << "The unsort array is: " << endl;    
    s.showArray(arr, len);  

    s.countingSort(arr, k, len);  
    cout << "\nThe sorted result is: " << endl;    
    s.showArray(arr, len);

	system("pause");
	return 0;
}