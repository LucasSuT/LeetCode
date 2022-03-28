// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* pre;

    Node(int _val) {
        val = _val;
        next = NULL;
        pre = NULL;
    }
};


 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> vec;
    ListNode* sortList(ListNode* head) {
        ListNode* result = new ListNode(0);

        if (!head)return head;
        while (head)
        {
            vec.push_back(head);
            head = head->next;
        }
        MergeSort(vec, 0, vec.size() - 1);
        PrintVector(vec);
        for (ListNode*& n : vec)
        {
            result->next = n;
            result = result->next;
        }
        result->next = NULL;
        PrintNode(vec[0]);
        return vec[0];
    }

    void MergeSort(vector<ListNode*>& vec, int start, int end)
    {
        //cout <<"start = "<< start << " end = " << end << "\n";
        int mid;
        vector<ListNode*> left;
        vector<ListNode*> right;
        if (start < end)
        {
            mid = (start + end) / 2;
            MergeSort(vec, start, mid);
            MergeSort(vec, mid+1, end);
            //cout << "------------start = " << start << " end = " << end << "\n";
            left.assign(vec.begin() + start, vec.begin() + mid + 1);
            right.assign(vec.begin() + mid + 1, vec.begin() + end + 1);
            Merge(vec, left, right, start);
        }
    }

    void Merge(vector<ListNode*>& vec, vector<ListNode*>& left, vector<ListNode*>& right, int start)
    {
        /*PrintVector(left);
        PrintVector(right);*/
        int left_Index = 0, right_index = 0;
        while (left_Index < left.size() && right_index<right.size())
        {
            if (left[left_Index]->val < right[right_index]->val)
            {
                vec[start++] = left[left_Index];
                left_Index++;
            }
            else
            {
                vec[start++] = right[right_index];
                right_index++;
            }
        }
        while (left_Index < left.size())vec[start++] = left[left_Index++];
        while (right_index < right.size())vec[start++] = right[right_index++];
        //PrintVector(vec);
    }

    void PrintVector(vector<ListNode*> vec)
    {
        for (ListNode*& n : vec)cout << n->val << " ";
        cout << "\n";
    }

    void PrintNode(ListNode* temp)
    {
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 2,2,1 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    cout << s.sortList(new ListNode(5,new ListNode(4,new ListNode(3,new ListNode(2,new ListNode(1,new ListNode(0)))))));
}
