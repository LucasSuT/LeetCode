#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int;
#define true 1;
#define false 0;

//  * Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode list_node;

void toString(list_node *n)
{
	while(n)
	{
		printf("%d ",n->val);
		n=n->next;
	}
	printf("\n");
}

int GetLength(list_node *n)
{
	int count=0;
	while (n)
	{
		count++;
		n = n->next;
	}
	return count;
}

list_node* ReverseHalf(list_node *n,int length)
{
	list_node *pre;
	list_node *next;
	int mid=length/2;
	while(length-->mid)
	{
		pre=n;
		n=n->next;
	}
	while(n)
	{
		next=n->next;
		n->next=pre;
		pre=n;
		n=next;
	}
	return pre;
}

bool isPalindrome(struct ListNode *head)
{
	list_node *tail;
	int length,mid;
	mid=length/2;
	toString(head);
	length = GetLength(head);
	tail = ReverseHalf(head, length);
	while(length-->mid)
	{
		if(head->val!=tail->val)return false;
		head=head->next;
		tail=tail->next;
	}
	return true;
}

int main(int argc, char *argv[])
{
	struct ListNode n = {.val = 1};
	struct ListNode n2 = {.val = 2};
	struct ListNode n3 = {.val = 3};
	struct ListNode n4 = {.val = 1};
	n.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	printf("------------- %d\n",isPalindrome(&n));
	return 0;
}


