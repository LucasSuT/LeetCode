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
    bool canJump(vector<int>& nums) {
        if (!findIndex(nums, nums.size() - 1))return true;
        return false;
    }

    int findIndex(vector<int>& nums, int length)
    {
        if (length == 0)return length;
        for (int i = 0; i < length; i++)
        {
            if (nums[i] >= length - i)
                return findIndex(nums, i);
        }
        return -1;
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