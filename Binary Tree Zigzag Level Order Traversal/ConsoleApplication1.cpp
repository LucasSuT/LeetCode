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
      list<TreeNode*> invit;
      list<TreeNode*> nextLevel;
      vector<vector<int>> result;
      bool reverse = true;
      vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<int> temp;
          invit.push_back(root);
          while (invit.size() != 0)
          {
              if (reverse)
              {
                  TreeNode* node = invit.front();
                  if (node != nullptr)
                  {
                      temp.push_back(node->val);
                      nextLevel.push_back(node->left);
                      nextLevel.push_back(node->right);
                  }
                  invit.pop_front();
                  if (invit.size() == 0 && temp.size() > 0)
                  {
                      result.push_back(temp);
                      temp = vector<int>();
                      invit = nextLevel;
                      nextLevel.clear();
                      reverse = !reverse;
                  }
              }
              else if (!reverse)
              {
                  TreeNode* node = invit.back();
                  if (node != nullptr)
                  {
                      temp.push_back(node->val);
                      nextLevel.push_front(node->right);
                      nextLevel.push_front(node->left);
                  }
                  invit.pop_back();
                  if (invit.size() == 0 && temp.size() > 0)
                  {
                      result.push_back(temp);
                      temp = vector<int>();
                      invit = nextLevel;
                      nextLevel.clear();
                      reverse = !reverse;
                  }
              }
              
          }
          return result;
      }
  };

int main()
{
    //vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 7,1,5,3,6,4 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    //cout << s.numDecodings("111111111111111111111111111111111111111111111");
    s.zigzagLevelOrder(new TreeNode(3,new TreeNode(9),new TreeNode(20,new TreeNode(15),new TreeNode(7))));
}