// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include "Windows.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <filesystem>
#include <fstream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val;
            if (head == nullptr)
            {
                head = new ListNode((sum + carry) % 10);
                tail = head;
            }
            else
            {
                ListNode* temp = new ListNode((sum + carry) % 10);
                tail->next = temp;
                tail = temp;
            }
            carry = (sum + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            sum = l1->val + carry;
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            sum = l2->val + carry;
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }
        if (carry != 0)
        {
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
};

int main()
{
    vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 2,0,2,1,1,0 };
    Solution s;
    //cout<<s.minWindow("aa", "aa");
    //s.twoSum(tmp2,4);
}