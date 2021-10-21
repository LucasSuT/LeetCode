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
    int search(vector<int>& nums, int target) {
        return qiuckSearch(nums, target, 0, nums.size() - 1);
    }

    int qiuckSearch(vector<int>& nums, int target, int start, int end)
    {
        int index = (end + start) / 2;
        int result = -1;
        if (start == end && nums[start] != target)return result;
        else if (nums[index] == target)return index;
        else
        {
            if (index - 1 >= start)
                result = qiuckSearch(nums, target, start, index - 1);
            if (result == -1 && index + 1 <= end)
                return qiuckSearch(nums, target, index + 1, end);
            else return result;
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