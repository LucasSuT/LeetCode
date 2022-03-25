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
    int max = 0;
    int maxDepth(TreeNode* root) {
        if (!root)return max;
        int depth = 1;
        recursive(root, depth);
        return max;
    }
    int recursive(TreeNode* root, int& depth)
    {
        if (root->left != NULL)
            recursive(root->left, ++depth);
        if (root->right != NULL)
            recursive(root->right, ++depth);
        if (max < depth)max = depth;
        return --depth;
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 2,2,1 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    /*Solution s;
    cout << s.wordBreak("fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami", str);*/
    LRUCache lc(3);
    lc.put(1, 1);
    lc.put(2, 2);
    lc.put(3, 3);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.put(4, 4);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(4);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(3);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(2);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(1);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.put(5, 5);
    lc.printNodes(lc.front);
    lc.get(1);
    lc.printNodes(lc.front);
    lc.get(2);
    lc.printNodes(lc.front);
    lc.get(3);
    lc.printNodes(lc.front);
    lc.get(4);
    lc.printNodes(lc.front);
    lc.get(5);
    lc.printNodes(lc.front);
}
