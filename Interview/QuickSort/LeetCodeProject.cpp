// LeetCodeProject.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>

void print(int *a)
{
	for (int i = 0; i < 6; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* a, int start, int end)
{
	int i = start, j = end-1;
	printf("start = %d end = %d\n",start,end);
	while (i <= j) //確保最後J右邊都大於等於a[end]
	{
		if (a[i] > a[end])swap(a+i, a+j--);
		else
			i++;
	}
	swap(a + j+1, a + end); //將a[end]與右半區最左數交換
	print(a);
	return j;
}

void QuickSort(int* a, int start, int end)
{
	if (start >= end)return;
	int pivot = partition(a, start, end);
	printf("pivot = %d\n", pivot);
	QuickSort(a, start, pivot);
	QuickSort(a, pivot +1, end);
}

int main()
{
	int a[] = { 6,3,7,1,4,5 };
	print(a);
	QuickSort(a, 0, 5);
	print(a);
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
