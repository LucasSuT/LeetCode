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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        getCombinations(results, result, nums);
        return results;
    }

    void getCombinations(vector<vector<int>>& results, vector<int>& result, vector<int> ele)
    {
        if (ele.size() == 1)
        {
            result.push_back(ele[0]);
            results.push_back(result);
            result.pop_back();
            return;
        }
        for (int i = 0; i < ele.size(); i++)
        {
            result.push_back(ele[i]);
            vector<int> temp = ele;
            temp.erase(temp.begin() + i);
            getCombinations(results, result, temp);
            result.pop_back();
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