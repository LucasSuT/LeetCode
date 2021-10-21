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
    void sortColors(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
    }
    void quicksort(vector<int>& nums, int left, int right)
    {
        if (left >= right || left < 0)return;
        int swapIndex = left;
        int pivot = nums[(left + right) / 2];
        swap(nums[(left + right) / 2], nums[right]);
        for (int i = left; i < right; i++)
            if (nums[i] <= pivot)
            {
                swap(nums[swapIndex++], nums[i]);
            }
        swap(nums[swapIndex], nums[right]);
        quicksort(nums, left, swapIndex - 1);
        quicksort(nums, swapIndex + 1, right);
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