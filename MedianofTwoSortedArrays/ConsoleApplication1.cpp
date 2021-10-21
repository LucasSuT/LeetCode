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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int f1 = 0, f2 = 0;
        while (f1 != nums1.size() && f2 != nums2.size())
        {
            if (nums1[f1] < nums2[f2])result.push_back(nums1[f1++]);
            else result.push_back(nums2[f2++]);
        }
        while (f1 != nums1.size())
        {
            result.push_back(nums1[f1++]);
        }
        while (f2 != nums2.size())
        {
            result.push_back(nums2[f2++]);
        }
        if (result.size() % 2 == 0)
        {
            return (result[result.size() / 2] + result[result.size() / 2 - 1]) / 2.0;
        }
        else return result[result.size() / 2];
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