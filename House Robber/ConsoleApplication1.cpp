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
#include <list>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if (dp.size() <= 1)return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = (nums[i] + dp[i - 2]) > dp[i - 1] ? nums[i] + dp[i - 2] : dp[i - 1];
        }
        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 1,3,5,7,9 };
    s.rob(vec);
    //system("pause");
}
