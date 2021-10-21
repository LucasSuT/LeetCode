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
    string minWindow(string s, string t) {
        unordered_map<char, int> umap;
        map<int, char> map;
        int count = 0;
        string result = s;
        for (int i = 0; i < t.length(); i++)umap[t[i]]++;
        for (int i = 0; i < s.length(); i++)
        {
            if (umap.find(s[i]) != umap.end())
            {
                umap[s[i]]--;
                map[i] = s[i];
                if (umap[s[i]] >= 0)count++;
                if (count == t.length())
                {
                    simplify(umap, map);
                    auto iter = --map.end();
                    if (iter->first - map.begin()->first + 1 < result.length())
                        result = s.substr(map.begin()->first, iter->first - map.begin()->first + 1);
                }
            }
        }
        if (count == t.length())return result;
        return "";
    }

    void simplify(unordered_map<char, int>& umap, map<int, char>& map)
    {
        auto iter = map.begin();
        while (iter != map.end())
        {
            if (umap[iter->second] < 0)
            {
                umap[iter->second]++;
                map.erase(iter++);
            }
            else break;
        }
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