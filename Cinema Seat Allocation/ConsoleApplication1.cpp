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
      int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
          int max = 0;
          int row;
          vector<int> reserveNo;
          sort(reservedSeats.begin(), reservedSeats.end());
          row = reservedSeats[0][0];
          max += 2 * (reservedSeats[0][0] - 1);
          for (int i = 0; i < reservedSeats.size(); i++)
          {
              if (row == reservedSeats[i][0])reserveNo.push_back(reservedSeats[i][1]);
              else
              {
                  max += 2 * (reservedSeats[i][0] - row - 1);
                  max += maxGroupOfRow(10, reserveNo);
                  cout << "max = "<<max<<"\n";
                  reserveNo.clear();
                  row = reservedSeats[i][0];
                  reserveNo.push_back(reservedSeats[i][1]);
              }
          }

          max += maxGroupOfRow(10, reserveNo);
          max += 2 * (n - row );
          cout << "final = "<<max << "\n";
          return max;
      }

      int maxGroupOfRow(int rowSeat,vector<int > &reservedNo)
      {
          sort(reservedNo.begin(), reservedNo.end());
          for (int i : reservedNo)cout << i << " ";
          cout << "\n";
          int max = 0;
          int linkCount = 0;
          int reserveIndex = 0;
          for (int i = 1; i <= rowSeat; i++)
          {
              if (reserveIndex< reservedNo.size() && reservedNo[reserveIndex] == i)
              {
                  reserveIndex++;
                  linkCount = 0;
              }
              else if (i == 4 || i == 8)
              {
                  if (linkCount < 2)linkCount = 1;
                  else if (linkCount >= 2)linkCount = 3;
              }
              else
              {
                  linkCount++;
              }

              if (linkCount == 4)
              {
                  max++;
                  linkCount = 0;
              }
          }
          return max;
      }
  };

int main()
{
    vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 0,0,0,0,0 };
    vector<int> tmp3{ 1,2,3,4,5 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    s.maxNumberOfFamilies(3, tmp);
}