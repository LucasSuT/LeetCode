// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>
#include <fstream>
#include <list>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        string s;
        while (n != 1)
        {
            if (uset.count(n))return false;
            else if (n == 1)return true;
            uset.insert(n);
            s = to_string(n);
            n = 0;
            for (int i = 0; i < s.length(); i++)
            {
                n += pow(s[i]-'0', 2);
            }
        }
    }
private:
    unordered_set<int> uset;
};

int main()
{
    Solution s;
    vector<int> vec{ 1,3,5,7,9 };
    vector<vector<char>> vec2{ {'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'} };
    s.isHappy(19);
    //system('pause');
}
