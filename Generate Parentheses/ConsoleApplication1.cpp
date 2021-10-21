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
    vector<string> result{};
    vector<string> generateParenthesis(int n) {
        string s = "";
        generate(n, n, s);
        return result;
    }

    void generate(int i, int j, string s)
    {
        if (i == 0 && j == 0)
        {
            // cout << s << endl;
            result.push_back(s);
            return;
        }
        else if (i == j && i > 0)generate(i - 1, j, s + '(');
        else if (i < j && i>0)
        {
            generate(i - 1, j, s + '(');
            generate(i, j - 1, s + ')');
        }
        else if (i < j && i == 0)generate(i, j - 1, s + ')');
        else
        {
            cout << "error" << endl;
        }
        return;
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