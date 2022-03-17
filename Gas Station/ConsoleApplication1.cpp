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
      int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          bool positive;
          vector<int> remain;

          for (int i = 0; i < gas.size(); i++)
              remain.push_back(gas[i] - cost[i]);

          int posIndex;
          int sum = remain[0];
          if (remain[0] < 0)positive = false;
          else
          {
              posIndex = 0;
              positive = true;
          }

          for (int i = 1; i < remain.size(); i++)
          {
              sum += remain[i];
              if (positive)
              {
                  remain[posIndex] += remain[i];
                  if (remain[posIndex] < 0)positive = !positive;
              }
              else if (remain[i] >= 0)
              {
                  posIndex = i;
                  positive = !positive;
              }
          }

          if (sum >= 0)
              return posIndex;
          else
              return -1;
      }
  };

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 5,1,2,3,4 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    s.canCompleteCircuit(tmp2, tmp3);
}