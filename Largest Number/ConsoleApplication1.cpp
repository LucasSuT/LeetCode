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

bool myfunction(const int& n1, const int& n2)
{
    string str1, str2;
    int length, i = 0;
    str1 = to_string(n1);
    str2 = to_string(n2);
    str1.append(to_string(n2));
    str2.append(to_string(n1));
    cout << str1 << " " << str2 << "\n";
    length = str1.length();
    while (i < length)
    {
        if (str1[i] > str2[i])return true;
        else if (str1[i] < str2[i])return false;
        i++;
    }
    return true;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string str="";
        sort(nums.begin(), nums.end(), myfunction);
        for (int n : nums)
        {
            cout << n << " ";
            str.append(to_string(n));
        }
        if (str[0]=='0')
        {
            return "0";
        }
        return str;
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 34323,3432 };
    s.largestNumber(vec);
    system("pause");
}
