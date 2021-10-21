// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include "Windows.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <filesystem>
#include <fstream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            vector<int> tmp(10, 0);
            vector<int> tmp2(10, 0);
            vector<int> tmp3(10, 0);
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.' && tmp[(int)board[i][j] - '0']++)return false;
                if (board[j][i] != '.' && tmp2[(int)board[j][i] - '0']++)return false;
                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.' && tmp3[(int)board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0']++)return false;
            }
        }

        return true;
    }
};


int main()
{
    vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 2,0,2,1,1,0 };
    Solution s;
    //cout<<s.minWindow("aa", "aa");
    //s.twoSum(tmp2,4);
}