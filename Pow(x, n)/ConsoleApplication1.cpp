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
    double myPow(double x, int n) {
        bool negative = false;
        double result = 1;
        if (n < 0 && n>-2147483648)
        {
            n *= -1;
            negative = !negative;
        }
        else if (n < 0 && n == -2147483648)
        {
            n += 1;
            result *= x;
            n *= -1;
            negative = !negative;
        }
        while (n > 0)
            result *= multiplication(x, n, 2);
        cout << result << "\n";
        if (!negative)
            return result;
        else return 1.0 / result;
    }

    double multiplication(double sum, int& toalcount, long currentCount)
    {
        if (toalcount > 0 && toalcount >= currentCount)
        {
            return multiplication(sum * sum, toalcount, currentCount * 2);
        }
        else
        {
            toalcount -= currentCount / 2;
            return sum;
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