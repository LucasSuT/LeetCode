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

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> l1{ 2 };
        vector<long> l2{ 3 };
        vector<long> l3{ 5 };
        vector<int> result{1};
        vector<int> index{ 0,0,0 };
        for (int i = 0; i < n; i++)
        {
            result.push_back(min(l1, l2, l3, index));
            l1.push_back(result[result.size() - 1] * l1[0]);
            l2.push_back(result[result.size() - 1] * l2[0]);
            l3.push_back(result[result.size() - 1] * l3[0]);
            /*for (int n : index)cout << n << " ";
            cout << "\n\n";*/
        }

        //for (int n : result)cout << n << " ";
        return result[n-1];
    }

    int min(vector<long>& first,vector<long>& second, vector<long>& third,vector<int>& index)
    {
        int min = 0;
        vector<long>* minTemp;
        int indexTemp;
        //cout << first[index[0]] << " " << second[index[1]] <<" "<< third[index[2]] << "\n";
        if (first[index[0]] < second[index[1]])
        {
            minTemp = &first;
            indexTemp = 0;
        }
        else
        {
            minTemp = &second;
            indexTemp = 1;
        }
        if ((*minTemp)[index[indexTemp]] < third[index[2]])
        {
            min = (*minTemp)[index[indexTemp]];
        }
        else min = third[index[2]];

        if (first[index[0]] == min)index[0]++;
        if (second[index[1]] == min)index[1]++;
        if (third[index[2]] == min)index[2]++;

        return min;
    }
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 2,2,1 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    s.nthUglyNumber(10);
}