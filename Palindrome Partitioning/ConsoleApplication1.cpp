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
      vector<vector<string>> result;
      vector<vector<string>> partition(string s) {
          vector<string> temp;
          recursive(s, temp);
          return result;
      }

      void recursive(string s, vector<string> &v)
      {
          //cout << "s = " << s << "\n";
          if (s.length() == 0)
          {
              for (string s : v)
              {
                  //cout << s << " ";
                  if (!isPalindrome(s))return;
              }
              //cout << "\n";
              result.push_back(v);
              return;
          }
          for (int i = 1; i <= s.length(); i++)
          {
              v.push_back(s.substr(0, i));
              recursive(s.substr(i), v);
              v.pop_back();
          }
      }

      bool isPalindrome(string s)
      {
          int i = 0, j = s.length() - 1;
          while (i <= j)
          {
              if (s[i] != s[j])return false;
              i += 1;
              j -= 1;
          }
          return true;
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
    //cout << s.numDecodings("111111111111111111111111111111111111111111111");
    s.partition("aab");
}