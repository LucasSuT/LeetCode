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
    int maxSubArray(vector<int>& nums) {
        int max = -123456789;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max < nums[i])max = nums[i];
            if (nums[i] >= 0)
            {
                if (sum + nums[i] < nums[i])sum = nums[i];
                else sum += nums[i];
            }
            else if (nums[i] < 0)
            {
                if (max < sum && i>0)max = sum;
                sum += nums[i];
            }
        }
        if (max < sum)max = sum;
        return max;
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