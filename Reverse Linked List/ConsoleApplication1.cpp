// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>
#include <fstream>
#include <list>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next;
        while (head->next != NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
            print(*pre);
        }
        head->next = pre;
        return head;
    }

    void print(ListNode temp)
    {
        while (temp.next != NULL)
        {
            cout << temp.val << " ";
            temp = *(temp.next);
        }
        cout << temp.val<<"\n";
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 1,3,5,7,9 };
    vector<vector<char>> vec2{ {'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'} };
    s.reverseList(new ListNode(1,new ListNode(2)));
    //system('pause');
}


 
