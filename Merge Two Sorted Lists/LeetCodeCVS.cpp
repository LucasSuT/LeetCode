#include <stdio.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Definition for singly-linked list.
//#define bool int
//#define true 1
//#define false 0

typedef struct ListNode {
	char val;
	struct ListNode* next;
}node;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	node* dummy = malloc(sizeof(node));
	node* result = dummy;
	while (list1 && list2)
	{
		if (list1->val <= list2->val)
		{
			dummy->next = list1;
			list1 = list1->next;
		}
		else
		{
			dummy->next = list2;
			list2 = list2->next;
		}
		dummy = dummy->next;
	}
	if (list1)
	{
		dummy->next = list1;
	}
	else
		dummy->next = list2;
	return result->next;
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
