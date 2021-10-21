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
    int firstMissingPositive(vector<int>& nums) {
        int n = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 1 && i > 0 && nums[i] == nums[i - 1])continue;
            else if (nums[i] >= 1 && nums[i] != n++)return n - 1;
        }
        return n;
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