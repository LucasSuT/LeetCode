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
#include <list>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    recursive(grid, i, j);
                    sum++;
                }
            }
        }
        return sum;
    }

    void recursive(vector<vector<char>>& grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0')return;
        else
        {
            grid[i][j] = '0';
            recursive(grid, i, j + 1);
            recursive(grid, i + 1, j);
            recursive(grid, i, j - 1);
            recursive(grid, i - 1, j);
        }
    }

    void print(vector<vector<char>>& grid)
    {
        for (vector<char>& first : grid)
        {
            for (char& second : first)
                cout << second << " ";
            cout << "\n";
        }
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
    s.numIslands(vec2);
    //system('pause');
}
