﻿// LeetCodeProject.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>
#include <stdlib.h>

void Merge(int* nums, int start, int mid, int end)
{
	int len = end - start + 1;
	int* temp = malloc(sizeof(int) * len);
	int index=0;
	int left = start, right = mid + 1;
	while (left <= mid && right <= end)
	{
		temp[index++] = nums[left] < nums[right] ? nums[left++] : nums[right++];
	}

	while (left <= mid)
		temp[index++] = nums[left++];
	while(right<=end)
		temp[index++] = nums[right++];

	for (int i = 0; i < len; i++)
	{
		nums[start + i] = temp[i];
	}
}

void MergeSort(int* nums, int start, int end)
{
	int mid = (start + end) / 2;
	if (start >= end)return;
	MergeSort(nums, start, mid);
	MergeSort(nums, mid + 1, end);
	Merge(nums, start, mid, end);
}

void Sort(int* nums1, int numsSize) {
	MergeSort(nums1, 0, numsSize - 1);
}

//void compare(void* a, void* b)
//{
//	return *(int*)a > *(int*)b;
//}

int main()
{
	/*for (int i = 0; i < 9; i++)
	{
		printf("%d ",i);
	}
	printf("\n");*/
	int a[] = { 1,6,4,3,8,9 };
	Sort(a, sizeof(a) / sizeof(int));
	//qsort(a, sizeof(a) / sizeof(int),sizeof(int), compare);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
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