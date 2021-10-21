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
    string countAndSay(int n) {
        return sayNumber("1", n);
    }

    string sayNumber(string s, int n)
    {
        if (n == 1)return s;

        string result = "";
        int count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
            {
                result += to_string(count) + s[i - 1];
                count = 0;
            }
            count++;
        }
        result += to_string(count) + s[s.length() - 1];
        return sayNumber(result, n - 1);
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