// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
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
    int maxProfit(vector<int>& prices) {
        int low = 0;
        int max = 0;
        int profit = 0;
     
        for (int i = 1; i < prices.size(); i++)
        {
            profit = prices[i] - prices[low];
            if (profit > max)max = profit;
            if (prices[i] < prices[low])low = i;
        }

        return max;
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 7,1,5,3,6,4 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    //cout << s.numDecodings("111111111111111111111111111111111111111111111");
    cout << s.maxProfit(tmp2);
}