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
        int i = 0, j = 0;
        int temp;
        bool shift = false;
        // cout << "==================================\n" << s << "\n" << p << "\n";
        while (i != s.length() && j != p.length())
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                if (!shift)
                {
                    i++;
                    j++;
                }
                else
                {
                    temp = findWord(s.substr(i, s.length()), p.substr(j, p.length()));
                    if (temp == -1)return false;
                    else return isMatch(s.substr(i + temp, s.length()), p.substr(j, p.length()));
                }
            }
            else if (p[j] == '*')
            {
                shift = true;
                j++;
            }
            else if (s[i] != p[j])
            {
                if (shift)i++;
                else return false;
            }
            else cout << "exception!!!!!!!!!!!!!\n";
        }
        while (j < p.length() && p[j] == '*')j++;
        if (j == p.length() && j - 1 >= 0 && p[j - 1] == '*')i = s.length();
        if (i != s.length() || j != p.length())return false;
        else return true;
    }

    int findWord(string s, string p)
    {
        string target = "";
        int j = 0;
        while (j < p.length() && p[j] != '*')target += p[j++];
        if (j == p.length())return rstrStr(s, target);
        else return strStr(s, target);
    }

    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        bool flag = false;
        while (i < haystack.length() && j < needle.length())
        {
            if ((needle[j] == '?' || haystack[i] == needle[j]) && !flag)
            {
                i++;
                j++;
            }
            else if ((needle[j] == '?' || haystack[i] == needle[j]) && flag)
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

    int rstrStr(string haystack, string needle) {
        int i = haystack.length() - 1, j = needle.length() - 1;
        bool flag = false;
        while (i >= 0 && j >= 0)
        {
            if ((needle[j] == '?' || haystack[i] == needle[j]) && !flag)
            {
                i--;
                j--;
            }
            else if ((needle[j] == '?' || haystack[i] == needle[j]) && flag)
            {
                i = i + needle.length() - j - 1;
                j = needle.length() - 1;
                flag = false;
            }
            else if (haystack[i] != needle[j])
            {
                i--;
                flag = true;
            }
            else
            {
                cout << "error" << endl;
                return -1;
            }
        }
        if (j == -1)return i + 1;
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