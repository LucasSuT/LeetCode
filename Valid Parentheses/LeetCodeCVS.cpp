#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Definition for singly-linked list.
#define bool int
#define true 1
#define false 0

typedef struct stack {
	char val;
	struct ListNode* next;
}stack;

stack* add(stack* top, char val)
{
	stack* s = malloc(sizeof(*s));
	s->val = val;
	s->next = top;
	return s;
}


bool isValid(char* s) {
	if (s == NULL)return false;
	stack dummy;
	stack* top = (stack*)malloc(sizeof(*top));
	top->val = *s;
	top->next = &dummy;
	s++;
	while (*s)
	{
		switch (*s)
		{
		case ')':
			if (top->val != '(')return false;
			top = top->next;
			break;
		case ']':
			if (top->val != '[')return false;
			top = top->next;
			break;
		case '}':
			if (top->val != '{')return false;
			top = top->next;
			break;
		default:
			top = add(top, *s);
			break;
		}
		s++;
	}
	if (top != &dummy)return false;
	else return true;
}


int main()
{
	char str[] = "(){}}{";
	/*char* s = &str[0];
	while (*s)
	{
		printf("%c ", *s);
		s++;
	}*/
	printf("%d\n",isValid(str));
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
