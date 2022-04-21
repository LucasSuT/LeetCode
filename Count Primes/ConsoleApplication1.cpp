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
    int countPrimes(int n) {
        int result = 0;
        vector<int> set(n, 1);
        int temp;

        if (n < 2)return 0;

        for (int i = 2; i < n ; i++)
        {
            temp = 2*i;
            if (set[i] == 1)
            {
                result++;
                while (temp < n)
                {
                    if (set[temp] == 1)
                    {
                        set[temp] = 0;
                    }
                    temp += i;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 1,3,5,7,9 };
    vector<vector<char>> vec2{ {'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'} };
    cout<<s.countPrimes(10);
    //system('pause');
}
