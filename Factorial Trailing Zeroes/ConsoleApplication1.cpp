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
    int trailingZeroes(int n) {
        int sum = 0;
        int i = 1;
        while (n / 5)
        {
            n -= 5;
            sum++;
        }
        
        return sum;
    }
};


int main()
{
   
    system("pause");
}
