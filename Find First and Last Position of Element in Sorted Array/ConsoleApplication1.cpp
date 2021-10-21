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
    vector<int> searchRange(vector<int>& nums, int target) {
        int tmp;
        vector<int>tmp2;
        if (nums.size() <= 0)return vector<int>{-1, -1};
        tmp = qiuckSearch(nums, target, 0, nums.size() - 1);
        if (tmp == -1)return vector<int>{-1, -1};
        else
        {
            while (tmp >= 0 && nums[tmp] == target)
            {
                tmp--;
            }
            tmp2.push_back(++tmp);
            while (tmp < nums.size() && nums[tmp] == target)
            {
                tmp++;
            }
            tmp2.push_back(--tmp);
        }
        return tmp2;
    }

    int qiuckSearch(vector<int>& nums, int target, int start, int end)
    {
        int index = (end + start) / 2;
        // cout << index << " " << start << " " << end << endl;
        if (nums[index] < target && index + 1 <= end)return qiuckSearch(nums, target, index + 1, end);
        else if (nums[index] > target && index - 1 >= start)return qiuckSearch(nums, target, start, index - 1);
        else if (nums[index] == target)return index;
        else return -1;
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