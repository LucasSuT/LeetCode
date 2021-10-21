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
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> map{ {},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
        vector<int> digit;
        vector<int> digitIndex;
        vector<string> result;
        digitIndex.assign(10, 0);
        string s;
        int i = 0, number, mapItemIndex;
        if (digits.length() == 0)return result;
        for (int i = 0; i < digits.length(); i++)
            digit.push_back(digits[i] - 48);
        while (i != digits.length())
        {
            number = digit[i];
            mapItemIndex = digitIndex[i];
            s += map[number][mapItemIndex];
            // cout << map[number][mapItemIndex] << " " << endl;
            if (i == digits.length() - 1)
            {
                result.push_back(s);
                // cout << s << endl;
                s = "";
                if (++digitIndex[i] >= map[number].size())
                {
                    for (int i = digit.size() - 1; i >= 0; i--)
                    {
                        if (digitIndex[i] >= map[digit[i]].size() && i != 0)
                        {
                            digitIndex[i] = 0;
                            digitIndex[i - 1]++;
                        }
                        else if (digitIndex[i] >= map[digit[i]].size() && i == 0)return result;
                        else break;
                    }
                }
                i = 0;
            }
            else i++;

        }
        return result;
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