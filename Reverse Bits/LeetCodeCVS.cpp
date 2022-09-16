﻿#include <stdio.h>
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

void clearBit(int* n, int bit_index)
{
	*n = *n & ~(0x1 << bit_index);
}

int reverseBits(int n) {
	int i = 0, j = 31;
	int left,right;
	while (i < j)
	{
		left = n >> j & 0x1;
		right = n >> i & 0x1;
		clearBit(&n, i);
		clearBit(&n, j);
		n = n | left << i;
		n = n | right << j;
		i++;
		j--;
	}
	return n;
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
