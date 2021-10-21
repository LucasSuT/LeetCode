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
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int result = 0;
        int count = 1;
        int tmp = 0;

        for (int i = l + 1; i < height.size(); i++)
        {
            if (height[i] >= height[l])
            {
                result += getWater(height, l, i);
                l = i;
            }
        }
        for (int i = l; i < (height.size() + l) / 2; i++)
        {
            tmp = height[i];
            height[i] = height[height.size() - count];
            height[height.size() - count++] = tmp;
        }
        //for (int tmp : height)cout << tmp << " ";
        for (int i = l + 1; i < height.size(); i++)
        {
            if (height[i] >= height[l])
            {
                result += getWater(height, l, i);
                l = i;
            }
        }
        return result;
    }


    int getWater(vector<int>& height, int l, int r)
    {
        //cout << l << " " << r<<endl;
        int volume = 0;
        if (r - l <= 1)return 0;
        else
        {
            for (int i = 1; i < r - l; i++)
            {
                volume += height[l] - height[l + i];
            }
        }
        //cout << volume << endl;
        return volume;
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