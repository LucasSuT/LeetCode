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
    bool exist(vector<vector<char>>& board, string word) {
        reverse(word);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                    if (recursive(board, word, i, j, 0))return true;
            }
        }
        return false;
    }

    bool recursive(vector<vector<char>>& board, string& word, int i, int j, int index)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())return false;
        else if (board[i][j] == word[index])
        {
            char temp = board[i][j];
            board[i][j] = '*';
            if (index == word.length() - 1)return true;
            if (recursive(board, word, i + 1, j, index + 1))return true;
            if (recursive(board, word, i - 1, j, index + 1))return true;
            if (recursive(board, word, i, j + 1, index + 1))return true;
            if (recursive(board, word, i, j - 1, index + 1))return true;
            board[i][j] = temp;
        }
        return false;
    }

    void reverse(string& word)
    {
        int count = 0, count2 = 0;
        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == word[0])count++;
            else break;
        }
        for (int i = word.length() - 2; i >= 0; i--)
        {
            if (word[i] == word[i + 1])count2++;
            else break;
        }
        if (count > count2)
        {
            for (int i = 0; i < word.length() / 2; i++)
            {
                swap(word[i], word[word.length() - i - 1]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> tmp{ {1,1,1},{1,0,1},{1,1,1} };
    vector<int> tmp2{ 1,2,3 };
    vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
                                ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    //cout<<s.minWindow('aa', 'aa');
    cout<<s.exist(tmp3, "AAAAAAAAAAAAAAB");
}