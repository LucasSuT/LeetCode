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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int i = 0, j = 0;
        while (matrix.size() > 0)
        {
            if (i == 0 && j == 0)
            {
                for (j; j < matrix[i].size(); j++)
                {
                    result.push_back(matrix[i][j]);
                }
                matrix.erase(matrix.begin());
                j--;
            }
            else if (i == 0 && j == matrix[i].size() - 1)
            {
                for (i; i < matrix.size(); i++)
                {
                    result.push_back(matrix[i][j]);
                    matrix[i].erase(matrix[i].begin() + j);
                }
                i--;
                j--;
            }
            else if (i == matrix.size() - 1 && j == matrix[i].size() - 1)
            {
                for (j; j >= 0; j--)
                {
                    result.push_back(matrix[i][j]);
                }
                matrix.pop_back();
                j++;
                i--;
            }
            else if (i == matrix.size() - 1 && j == 0)
            {
                for (i; i >= 0; i--)
                {
                    result.push_back(matrix[i][j]);
                    matrix[i].erase(matrix[i].begin() + j);
                }
                i++;
            }
        }
        return result;
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