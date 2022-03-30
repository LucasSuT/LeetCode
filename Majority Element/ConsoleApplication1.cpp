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
#include <unordered_map>
#include <map>

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

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty())return 0;
        int result = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (result == nums[i])count++;
            else
            {
                count--;
                if (count == 0)result = nums[i];
            }
        }
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 3,1,2 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    cout << s.fractionToDecimal(4,333);
}
