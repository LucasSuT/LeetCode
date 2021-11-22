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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        recursive(result, nums, sub, 0);
        return result;
    }

    void recursive(vector<vector<int>>& result, vector<int>& nums, vector<int>& sub, int index)
    {
        if (index == nums.size())result.push_back(sub);
        else
        {
            recursive(result, nums, sub, index + 1);
            sub.push_back(nums[index]);
            recursive(result, nums, sub, index + 1);
            sub.pop_back();
        }
    }
};

int main()
{
    vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 1,2,3 };
    Solution s;
    //cout<<s.minWindow("aa", "aa");
    s.subsets(tmp2);
}