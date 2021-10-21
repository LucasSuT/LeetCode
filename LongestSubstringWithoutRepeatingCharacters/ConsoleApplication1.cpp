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
    int lengthOfLongestSubstring(string s) {
        // string s="";
        int flag = 0;
        int count, maxCount = 0;
        for (int i = 0; i < s.length(); i++)
        {
            count = 1;
            for (int j = flag; j < i; j++)
            {
                if (s[i] == s[j])
                {
                    flag = j + 1;
                    count = i - flag + 1;
                    break;
                }
                else count++;
            }
            if (count > maxCount)maxCount = count;
        }
        return maxCount;
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