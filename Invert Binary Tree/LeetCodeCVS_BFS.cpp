#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Definition for singly-linked list.
struct List {
	struct TreeNode* tree_node;
	struct List* next;
};
struct List* tail;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void PushBack(struct TreeNode* tree_node)
{
	if (!tree_node)return;
	tail->next = calloc(1,sizeof(struct List));
	tail->next->tree_node = tree_node;
	tail = tail->next;
}

void SwapChild(struct TreeNode* root)
{
	struct TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

struct TreeNode* invertTree(struct TreeNode* root) {
	struct List* head = calloc(1,sizeof(struct List));
	head->tree_node = root;
	tail = head;
	while (head)
	{
		printf("%p ", head);
		printf("%d\n", head->tree_node->val);
		SwapChild(head->tree_node);
		PushBack(head->tree_node->left);
		PushBack(head->tree_node->right);
		head = head->next;
	}
	return root;
}

int main()
{
	char c[] = "W4f4 ,w";
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
