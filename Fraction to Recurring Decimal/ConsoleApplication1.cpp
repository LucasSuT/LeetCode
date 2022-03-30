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
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* pre;

    Node(int _val) {
        val = _val;
        next = NULL;
        pre = NULL;
    }
};

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result="";
        long remain;
        long long_numerator, long_denominator;
        unordered_map<int,int> map;
        bool negative_numerator = false;
        bool negative_denominator = false;

        long_numerator = numerator;
        long_denominator = denominator;

        if (long_numerator == 0)return "0";

        if (long_numerator < 0)
        {
            negative_numerator = true;
            long_numerator *= -1;
        }
        if (long_denominator < 0)
        {
            negative_denominator = true;
            long_denominator *= -1;
        }
        remain = long_numerator;
        result += to_string(remain / long_denominator);
        remain = remain % long_denominator * 10;
        if (remain)result += ".";
        map[remain] = result.length();
        cout << result << " " << remain<<"\n";
        while (remain != 0)
        {
            result += to_string(remain / long_denominator);
            remain = remain % long_denominator *10;
            if (map.count(remain))
            {
                result = result.substr(0, map[remain]) + "(" + result.substr(map[remain]) + ")";
                if (negative_numerator ^ negative_denominator)result = "-" + result;
                return result;
            }
            map[remain]=result.length();
            cout << result << " " << remain << "\n";
        }
        cout << "end\n";
        if (negative_numerator ^ negative_denominator)result = "-" + result;
        return result;
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 3,1,2 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    cout << s.fractionToDecimal(4,333);
}
