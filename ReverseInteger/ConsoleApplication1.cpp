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
    int reverse(int x) {
        bool flag = 0;
        long x2 = x;
        try
        {
            if (x < 0)
            {
                x2 *= -1;
                flag = 1;
            }
            string str = to_string(x2);
            string temp;
            for (int i = str.length() - 1; i >= 0; i--)
                temp += str[i];
            if (flag)x2 = stoi(temp) * -1;
            else x2 = stoi(temp);
        }
        catch (exception e)
        {
            return 0;
        }
        return x2;
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