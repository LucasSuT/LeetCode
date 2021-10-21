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
    bool isMatch(string s, string p) {
        int f1 = 0, f2 = 0;
        simplification(s);
        simplification(p);
        while (f1 != s.length() && f2 != p.length())
        {
            if (s[f1] == '.' || p[f2] == '.' || s[f1] == p[f2])
            {
                if (f1 + 2 < s.length() && s[f1 + 1] == '*' && isMatch(s.substr(f1 + 2, s.length()), p.substr(f2, p.length())))return true;
                if (f2 + 2 < p.length() && p[f2 + 1] == '*' && isMatch(s.substr(f1, s.length()), p.substr(f2 + 2, p.length())))return true;
                f1++;
                f2++;
            }
            else if (s[f1] == '*')
            {
                f1--;
            }
            else if (p[f2] == '*')
            {
                f2--;
            }
            else
            {
                if (f1 + 2 < s.length() && s[f1 + 1] == '*' && isMatch(s.substr(f1 + 2, s.length()), p.substr(f2, p.length())))return true;
                if (f2 + 2 < p.length() && p[f2 + 1] == '*' && isMatch(s.substr(f1, s.length()), p.substr(f2 + 2, p.length())))return true;
                return false;
            }
        }
        while (f1 != s.length())
        {
            if (s[f1] == '*')f1++;
            else if (f1 + 1 < s.length() && s[f1 + 1] == '*')f1++;
            else break;
        }
        while (f2 != p.length())
        {
            if (p[f2] == '*')f2++;
            else if (f2 + 1 < p.length() && p[f2 + 1] == '*')f2++;
            else break;
        }
        if (f1 == s.length() && f2 == p.length())
            return true;
        return false;
    }

    void simplification(string& s)
    {
        int i = 0, j = 0;
        while (i != s.length())
        {
            if (i + 1 < s.length() && s[i + 1] == '*')
            {
                j = i + 2;
                if (j + 1 < s.length() && s[i] == s[j] && s[j + 1] == '*')s.erase(j, 2);
                else i++;
            }
            else
                i++;
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