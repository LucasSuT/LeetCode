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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)return result;
        sort(nums.begin(), nums.end());
        vector<int> map;
        map.assign(200000, 0);
        int sum;

        for (int i : nums)
        {
            if (i < 0)
                map[100000 - i]++;
            else
                map[i]++;
        }

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i && nums[i] == nums[i - 1])continue;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])continue;

                sum = nums[i] + nums[j];
                if (sum > 0)break;
                else if (sum < -100000)continue;
                else if (map[sum * -1] && sum * -1 > nums[j])
                {
                    result.push_back(vector<int>{nums[i], nums[j], sum * -1});
                }
                else if (map[sum * -1] && sum * -1 == nums[j])
                {
                    if (nums[i] == nums[j] && map[sum * -1] < 3)continue;
                    else if (nums[i] != nums[j] && map[sum * -1] < 2)continue;
                    result.push_back(vector<int>{nums[i], nums[j], sum * -1});
                }
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