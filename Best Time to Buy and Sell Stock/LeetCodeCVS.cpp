#include <stdio.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Definition for singly-linked list.
typedef struct ListNode {
	char val;
	struct ListNode* next;
}node;

int maxProfit(int* prices, int pricesSize) {
	int sum = 0;
	int min= *prices;

	for (int i = 1; i < pricesSize; i++)
	{
		if (sum < prices[i] - min)sum = prices[i] - min;
		if (prices[i] < min)min = prices[i];
	}
	return sum;
}

int main()
{
	/*char str[] = "(){}}{";
	printf("%d\n",isValid(str));*/
	//test();
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
