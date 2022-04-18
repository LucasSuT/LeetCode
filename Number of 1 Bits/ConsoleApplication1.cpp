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
    int hammingWeight(uint32_t n) {
        int result = 0;
        int shift = 0;
        while (++shift < 32)
            result += n >> shift & 0x01;
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 34323,3432 };
    cout<<s.reverseBits(156);
    system("pause");
}
