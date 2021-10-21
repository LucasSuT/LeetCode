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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> umap = parse(strs);
        for (auto v = umap.begin(); v != umap.end(); v++)
            result.push_back(v->second);
        return result;
    }

    unordered_map<string, vector<string>> parse(vector<string>& strs)
    {
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = sortString(strs[i]);
            addUnmap(umap, s, strs[i]);
        }
        return umap;
    }

    void addUnmap(unordered_map<string, vector<string>>& umap, string& key, string value)
    {
        if (umap.find(key) != umap.end())
            umap[key].push_back(value);
        else
            umap[key] = vector<string>{ value };
    }

    string sortString(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[i] > str[j])swap(str[i], str[j]);
            }
        }
        return str;
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