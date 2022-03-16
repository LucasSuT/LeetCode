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

  class Solution {
  public:
      TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          TreeNode* result = new TreeNode(preorder[0]);
          vector<TreeNode*> v;
          v.resize(preorder.size() + 1);
          v[0] = result;
          for (int i = 1; i < preorder.size(); i++)
          {
              TreeNode* temp = new TreeNode(preorder[i]);
              for (int j = 0; j < inorder.size(); j++)
              {
                  if (preorder[i] == inorder[j])
                  {
                      v[i - 1]->left = temp;
                      v[i] = temp;
                      // cout << v[i - 1]->val<<"\n";
                      // cout << v[i]->val << "\n";
                      break;
                  }
                  else if (preorder[i - 1] == inorder[j])
                  {
                      // cout << i << " " << j << "\n";
                      // cout<<"index = "<<findNodeRight(preorder, inorder, i, j)<<"\n";
                      v[findNodeRight(preorder, inorder, i, j)]->right = temp;
                      v[i] = temp;
                      break;
                  }
              }
          }
          return result;
      }

      int findNodeRight(vector<int>& preorder, vector<int>& inorder, int preIndex, int inIndex)
      {
          while (inorder[inIndex] != preorder[preIndex])inIndex++;
          for (int i = inIndex - 1; i >= 0; i--)
          {
              for (int j = 0; j < preIndex; j++)
              {
                  if (inorder[i] == preorder[j])return j;
              }
          }
          return NULL;
      }
  };

int main()
{
    //vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 3,9,20,15,7 };
    vector<int> tmp3{ 9,3,15,20,7 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    s.buildTree(tmp2, tmp3);
}