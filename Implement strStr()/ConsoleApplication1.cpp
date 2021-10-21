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
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        bool flag = false;
        while (i < haystack.length() && j < needle.length())
        {
            if (haystack[i] == needle[j] && !flag)
            {
                i++;
                j++;
            }
            else if (haystack[i] == needle[j] && flag)
            {
                i = i - j;
                j = 0;
                flag = false;
            }
            else if (haystack[i] != needle[j])
            {
                i++;
                flag = true;
            }
            else
            {
                cout << "error" << endl;
                return -1;
            }
        }
        if (j == needle.length())return i - j;
        return -1;
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