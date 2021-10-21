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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> indexs;
        int i = 0, j = 0;
        for (i = 0; i < matrix.size(); i++)
            for (j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == 0)
                    indexs.push_back(vector<int>{i, j});
        for (vector<int> temp : indexs)
            setZero(matrix, temp);
    }

    void setZero(vector<vector<int>>& matrix, vector<int>& index)
    {
        int colume = index[0], row = index[1];
        while (--colume >= 0)
        {
            matrix[colume][row] = 0;
        }
        colume = index[0], row = index[1];
        while (++colume < matrix.size())
        {
            matrix[colume][row] = 0;
        }
        colume = index[0], row = index[1];
        while (--row >= 0)
        {
            matrix[colume][row] = 0;
        }
        colume = index[0], row = index[1];
        while (++row < matrix[colume].size())
        {
            matrix[colume][row] = 0;
        }
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