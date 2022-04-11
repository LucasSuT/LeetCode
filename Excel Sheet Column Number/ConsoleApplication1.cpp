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
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++)
            result += (columnTitle[i]-'A'+1) * pow(26, columnTitle.length() - i - 1);
        cout << result;
        return result;
    }
};


int main()
{
   
    system("pause");
}
