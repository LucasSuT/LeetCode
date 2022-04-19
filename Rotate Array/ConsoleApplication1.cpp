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
#include <list>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int index;
        vector<int> copy(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            index = i + k;
            nums[index % nums.size()] = copy[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 1,3,5,7,9 };
    s.rotate(vec,3);
    //system("pause");
}
