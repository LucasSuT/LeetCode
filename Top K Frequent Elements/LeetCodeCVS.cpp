#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	int* result = malloc(sizeof(int) * k);
	int bucket[20002] = { 0 };
	int max_index;
	for (int i = 0; i < numsSize; i++)
	{
		if (*(nums + i) < 0)
			bucket[10001 - *(nums + i)]++;
		else
			bucket[*(nums + i)]++;
	}
	for (int j = 0; j < k; j++)
	{
		max_index = 0;
		for (int i = 1; i < 20002; i++)
		{
			if (bucket[i] > bucket[max_index])
			{
				max_index = i;
			}
		}
		if (max_index <= 10001)
			*(result + j) = max_index;
		else
			*(result + j) = 10001 - max_index;
		bucket[max_index] = 0;
	}
	*returnSize = k;
	return result;
	
}

int main()
{
	struct ListNode l1;

	return 0;
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
