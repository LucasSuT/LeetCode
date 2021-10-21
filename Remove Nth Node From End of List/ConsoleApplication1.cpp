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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        if (head == nullptr || n > count)return head;
        else if (count == n)return head->next;


        count -= n;

        temp = head;
        while (--count > 0 && temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
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