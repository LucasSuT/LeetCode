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

using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root->left != nullptr)
            if (root->left->val >= root->val || !leftRecursive(root->left, root->val,NULL))return false;
        if (root->right != nullptr)
            if (root->right->val <= root->val || !rightRecursive(root->right, root->val,NULL))return false;
        return true;
    }

    bool leftRecursive(TreeNode* root, const int& val, const int& val2) {
        if (root->left != nullptr)
            if (root->left->val >= root->val || (val2!=NULL&&root->left->val<=val2) || !leftRecursive(root->left, root->val, val2))return false;
        if (root->right != nullptr)
            if (root->right->val <= root->val || root->right->val>=val || !rightRecursive(root->right, root->val, val))return false;
        return true;
    }

    bool rightRecursive(TreeNode* root, const int& val, const int& val2) {
        if (root->left != nullptr)
            if (root->left->val >= root->val || root->left->val<=val ||!leftRecursive(root->left, root->val,val))return false;
        if (root->right != nullptr)
            if (root->right->val <= root->val || (val2 != NULL && root->right->val>=val2) || !rightRecursive(root->right, root->val, val2))return false;
        return true;
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    //vector<int> tmp2{ 2,1,5,6,2,3 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    TreeNode* n = new TreeNode(98,new TreeNode(-57,nullptr,new TreeNode(58,new TreeNode(31),nullptr)),nullptr);
    /*TreeNode* n2 = new TreeNode(-57);
    TreeNode* n3 = new TreeNode(58);*/
    cout << n->val << "\n";
    cout << n->left->val << "\n";
    //cout << n->right->val << "\n";
    //cout << n->left->left->val << "\n";
    cout << n->left->right->val << "\n";
    //cout << n->right->left->val << "\n";
    cout<<s.isValidBST(n);
}