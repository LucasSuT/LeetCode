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
    bool isValid(string s) {
        map<char, char> mapItem{ {')','('},{'}','{'},{']','['} };
        map<char, int> mapCount{ {'(',0},{'{',0},{'[',0} };
        vector<char> temp{};
        for (int i = 0; i < s.length(); i++)
        {
            if (mapCount.find(s[i]) != mapCount.end())
            {
                temp.push_back(s[i]);
                mapCount[s[i]]++;
            }
            else
            {
                if ((int)temp.size() <= 0 || mapItem[s[i]] != *(temp.end() - 1))return false;
                else
                {
                    mapCount[*(temp.end() - 1)]--;
                    temp.pop_back();
                }
            }
        }
        if (temp.size() > 0)return false;
        return true;
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