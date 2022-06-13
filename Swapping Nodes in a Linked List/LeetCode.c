#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
      int val;
      struct ListNode *next;
  };

  void swap(struct ListNode *current, struct ListNode *target)
  {
      int temp = current->val;
      current->val = target->val;
      target->val = temp;
  }

  struct ListNode *swapNodes(struct ListNode *head, int k)
  {
      struct ListNode *first_head = head;
      struct ListNode *first = NULL;
      struct ListNode *second = head;
      while (head != NULL)
      {
          k--;
          if (k == 0)
          {
              first = head;
          }
          else if (k < 0)
              second = second->next;
          head = head->next;
      }
      swap(first, second);
      return first_head;
  }

int main()
{
    // int array[] = {0, 1, 0, 3, 12};
    // moveZeroes(array,5);
    // print(array,5);
    printf("ergerg");
}