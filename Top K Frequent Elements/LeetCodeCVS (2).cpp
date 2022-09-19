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

struct Bucket
{
	int val;
	int count;
};

int compare(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int compare2(const void* a, const void* b)
{
	return ((struct Bucket*)a)->count < ((struct Bucket*)b)->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	int* result = malloc(sizeof(int) * k);
	*returnSize = k;
	qsort(nums, numsSize, sizeof(int), compare);
	struct Bucket* bucket = calloc(numsSize, sizeof(struct Bucket));
	bucket[0].val = nums[0];
	int val = bucket[0].val, index = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (bucket[index].val != nums[i])
		{
			bucket[++index].val = nums[i];
			bucket[index].count++;
		}
		else
			bucket[index].count++;
	}
	qsort(bucket, numsSize, sizeof(struct Bucket), compare2);
	int i = 0;
	index = 0;
	result[index] = bucket[0].val;
	k--;
	while (k > 0)
	{
		if (bucket[i].val != result[index])
		{
			result[++index] = bucket[i].val;
			k--;
		}
		i++;
	}
	return nums;

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
