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
    string longestPalindrome(string s) {
        int current = 0;
        int move;
        int maxIndex[2] = { 0,-1 };
        while (current < s.length())
        {
            move = 1;
            while (current - move >= 0 && current + move < s.length() && s[current - move] == s[current + move])
            {
                move++;
            }
            if (maxIndex[1] - maxIndex[0] + 1 < 2 * (move - 1) + 1)
            {
                maxIndex[0] = current - move + 1;
                maxIndex[1] = current + move - 1;
            }
            move = 1;
            while (current - move + 1 >= 0 && current + move < s.length() && s[current - move + 1] == s[current + move])
            {
                move++;
            }
            if (maxIndex[1] - maxIndex[0] + 1 < 2 * (move - 1))
            {
                if (move == 1)
                {
                    maxIndex[0] = current;
                    maxIndex[1] = current;
                }
                else
                {
                    maxIndex[0] = current - (move - 1) + 1;
                    maxIndex[1] = current + (move - 1);
                }
            }
            current++;
        }
        return s.substr(maxIndex[0], maxIndex[1] - maxIndex[0] + 1);
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