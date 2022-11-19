// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

//class Solution {
//public:
//    set<TreeNode*> set_;
//    TreeNode* ancestor_;
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        set_.insert(p);
//        set_.insert(q);
//        return FindAncestor(root, set_);
//    }
//
//    TreeNode* FindAncestor(TreeNode* root, set<TreeNode*>& set_)
//    {
//        if (!root )return NULL;
//        if (set_.count(root))
//        {
//            if (set_.size() == 1)return ancestor_;
//            ancestor_ = root;
//            set_.erase(root);
//        }
//
//        if (FindAncestor(root->left, set_))return ancestor_;
//        if (!ancestor_ && set_.size() == 1)ancestor_ = root;
//        if (FindAncestor(root->right, set_))return ancestor_;
//        if (ancestor_ == root)ancestor_ == NULL;
//        return NULL;
//    }
//};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) {
            if (p == root || q == root) return root;
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (left && right) return root;
            if (left) return left;
            if (right) return right;
            return NULL;
        }
        return root;
    }
};

int main()
{
    printf("Hello World!\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
