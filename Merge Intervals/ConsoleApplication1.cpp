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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < intervals.size(); j++)
            {
                if (i != j && intervals[j][0] <= intervals[i][1] && intervals[j][1] >= intervals[i][0])
                {
                    intervals[i][0] = intervals[i][0] < intervals[j][0] ? intervals[i][0] : intervals[j][0];
                    intervals[i][1] = intervals[i][1] > intervals[j][1] ? intervals[i][1] : intervals[j][1];
                    if (i > j)i--;
                    intervals.erase(intervals.begin() + j--);
                    flag = true;
                }
            }
            if (flag)i--;
        }
        return intervals;
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