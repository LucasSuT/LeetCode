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
    int romanToInt(string s) {
        int topPriority = -1;
        int curretnPriority = 0;
        int sum = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            switch (s[i])
            {
            case 'I':
                curretnPriority = 0;
                if (curretnPriority >= topPriority)
                {
                    sum += 1;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 1;
                    topPriority = -1;
                }
                break;
            case 'V':
                curretnPriority = 1;
                if (curretnPriority >= topPriority)
                {
                    sum += 5;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 5;
                    topPriority = -1;
                }
                break;
            case 'X':
                curretnPriority = 2;
                if (curretnPriority >= topPriority)
                {
                    sum += 10;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 10;
                    topPriority = -1;
                }
                break;
            case 'L':
                curretnPriority = 3;
                if (curretnPriority >= topPriority)
                {
                    sum += 50;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 50;
                    topPriority = -1;
                }
                break;
            case 'C':
                curretnPriority = 4;
                if (curretnPriority >= topPriority)
                {
                    sum += 100;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 100;
                    topPriority = -1;
                }
                break;
            case 'D':
                curretnPriority = 5;
                if (curretnPriority >= topPriority)
                {
                    sum += 500;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 500;
                    topPriority = -1;
                }
                break;
            case 'M':
                curretnPriority = 6;
                if (curretnPriority >= topPriority)
                {
                    sum += 1000;
                    topPriority = curretnPriority;
                }
                else
                {
                    sum -= 1000;
                    topPriority = -1;
                }
                break;
            }
        }
        return sum;
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