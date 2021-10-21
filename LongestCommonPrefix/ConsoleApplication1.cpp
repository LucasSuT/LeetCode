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
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        char c;
        while (true)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                if (index < strs[i].length() && i == 0)c = strs[i][index];
                else if (index >= strs[i].length() || index < strs[i].length() && strs[i][index] != c)return strs[i].substr(0, index);
            }
            index++;
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