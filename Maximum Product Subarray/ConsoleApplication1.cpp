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


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int negative_product = nums[0];
        int start = 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        if (nums[0] == 0)
        {
            start++;
            negative_product = 1;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] * nums[i], nums[i]);
            if (dp[i] > result)result = dp[i];

            if (nums[i] == 0)
            {
                if (helper(nums, negative_product, start, i - 1) && negative_product > result)result = negative_product;
                start = i + 1;
                negative_product = 1;
            }
            else
            {
                negative_product *= nums[i];
                if (negative_product > result)result = negative_product;
            }
        }
        if(*(nums.end()-1)!=0 && helper(nums, negative_product, start, nums.size()-1) && negative_product > result)result = negative_product;
        return result;
    }

    bool helper(vector<int>& nums,int &product, int start, int end)
    {
        int temp1 = product;
        int temp2 = product;
        if (product > 0)return true;
        else if (start > end)return false;
        else if (start == end)return true;

        while (nums[start] > 0)
        {
            temp1 /= nums[start++];
        }
        temp1 /= nums[start];

        while (nums[end] > 0)
        {
            temp2 /= nums[end--];
        }
        temp2 /= nums[end--];

        product = temp1 > temp2 ? temp1 : temp2;

        return true;
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 2,3,-2,4 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    cout << s.maxProduct(tmp2);
}
