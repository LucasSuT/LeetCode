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
    int divide(int dividend, int divisor) {
        long dividendtemp = dividend;
        long divisortemp = divisor;
        bool negative = false;
        long result = 0;
        if (dividendtemp < 0)
        {
            dividendtemp = 0 - dividendtemp;
            negative = !negative;
        }
        if (divisortemp < 0)
        {
            divisortemp = 0 - divisortemp;
            negative = !negative;
        }
        // cout << negative << endl;
        // cout << dividendtemp << "   " << divisortemp << endl;
        // cout << "===================================\n";

        while (dividendtemp >= divisortemp)
        {
            result += subQuotient(dividendtemp, divisortemp);
        }

        if (negative)return 0 - result;
        else if (!negative && result > 2147483647)return --result;
        else return result;
    }

    int subQuotient(long& dividendtemp, long divisortemp)
    {
        int shift = 0;
        int multiple = 1;
        while (divisortemp << shift < dividendtemp)
        {
            shift++;
        }
        if (shift)shift--;
        // cout << shift << endl;
        divisortemp = divisortemp << shift;
        dividendtemp -= divisortemp;
        for (int i = 0; i < (int)shift; i++)
        {
            multiple += multiple;
        }
        return multiple;
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