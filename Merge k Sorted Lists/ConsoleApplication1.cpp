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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* result = nullptr;
        if (lists.size() == 1)return lists[0];
        while (lists.size() > 0)
        {
            if (result == nullptr && lists.size() >= 2)
            {
                result = merge(lists[lists.size() - 1], lists[lists.size() - 2]);
                lists.pop_back();
                lists.pop_back();
            }
            else if (lists.size() >= 1)
            {
                result = merge(lists[lists.size() - 1], result);
                lists.pop_back();
            }
        }
        return result;
    }
    ListNode* merge(ListNode* n1, ListNode* n2)
    {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        while (n1 != nullptr && n2 != nullptr)
        {
            if (n1->val < n2->val)
            {
                temp->next = n1;
                n1 = n1->next;
            }
            else
            {
                temp->next = n2;
                n2 = n2->next;
            }
            temp = temp->next;
        }
        if (n1)
            temp->next = n1;
        else
            temp->next = n2;
        return result->next;
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