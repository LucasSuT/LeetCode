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
    int myAtoi(string s) {
        while (s[0] == ' ')s.erase(s.begin());
        try {
            return stoi(s);
        }
        catch (out_of_range e)
        {
            if (s[0] == '-')
                return INT32_MIN;
            else return INT32_MAX;
        }
        catch (exception e) { cout << "error" << endl; }
        return 0;
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