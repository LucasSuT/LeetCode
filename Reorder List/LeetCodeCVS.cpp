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
struct List* tail;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct ListNode* reverse(struct ListNode* head)
{
	struct ListNode* pre, * current, * next;
	current = head;
	if (!head)return head;
	while (current)
	{
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	return pre;
}

void merge(struct ListNode* a, struct ListNode* b)
{
	struct ListNode* head = a;
	if (!a || a == b)return;
	a = a->next;
	while (a && b)
	{
		head->next = b;
		head = head->next;
		b = b->next;
		head->next = a;
		a = a->next;
		head = head->next;
	}

	if (b)head->next = b;

}

void reorderList(struct ListNode* head) {
	struct ListNode* slow, * fast, * pre;
	pre = head;
	slow = head;
	fast = head;
	while (fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;
	slow = reverse(slow);
	merge(head, slow);
}

int main()
{
	int *n[2] = { {1,1,1},{1,1,0},{1,0,1} };

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
