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
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          int shift = nums1.size() - m;
          int i = m, j = 0;
          int index = 0;
          for (int i = m-1; i >= 0; i--)
          {
              swap(nums1[i],nums1[i+shift]);
          }
          i = shift;

          while (i < nums1.size() && j < nums2.size())
          {
              cout << nums1[i] << " " << nums2[j] << "\n";
              if (nums1[i] < nums2[j])nums1[index++] = nums1[i++];
              else nums1[index++] = nums2[j++];
              cout << "nums1[" << index - 1 << "] = " << nums1[index - 1]<<"\n";
          }
          //cout << nums1[i];
          while (i < nums1.size())
              nums1[index++] = nums1[i++];
          while(j < nums2.size())
              nums1[index++] = nums2[j++];
          for (int n : nums1)cout << n << " ";
      }
  };

int main()
{
    //vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 0,0,0,0,0 };
    vector<int> tmp3{ 1,2,3,4,5 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    s.merge(tmp2, 0, tmp3,5);
}