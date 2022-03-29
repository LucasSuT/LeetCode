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
#include <unordered_set>

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
    int evalRPN(vector<string>& tokens) {
        int flag = true;
        int result;
        for (string& s : tokens)
        {
            if (s == "+")
            {
                result = stoi(st.top());
                st.pop();
                result += stoi(st.top());
                st.pop();
                st.push(to_string(result));
            }
            else if (s == "-")
            {
                result = stoi(st.top());
                st.pop();
                result = stoi(st.top()) - result;
                st.pop();
                st.push(to_string(result));
            }
            else if (s == "*")
            {
                result = stoi(st.top());
                st.pop();
                result = stoi(st.top()) * result;
                st.pop();
                st.push(to_string(result));
            }
            else if (s == "/")
            {
                result = stoi(st.top());
                st.pop();
                result = stoi(st.top()) / result;
                st.pop();
                st.push(to_string(result));
            }
            else st.push(s);
        }
        return stoi(st.top());
    }
private:
    stack<string> st;
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 2,2,1 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    Solution s;
    cout << s.evalRPN(NULL);
}
