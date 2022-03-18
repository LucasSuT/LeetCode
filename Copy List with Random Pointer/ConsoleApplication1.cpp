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
    Node* copyRandomList(Node* head) {
        Node* result = new Node(0);
        Node* original = head;
        Node* current = result;
        while (head != nullptr)
        {
            current->next = new Node(head->val);
            current = current->next;
            head = head->next;
        }

        current = result->next;
        head = original;
        Node* temp = result->next;
        while (head != nullptr)
        {
            insertToNode(&current, result->next, IndexOfNode(head->random, original));
            current = current->next;
            head = head->next;
        }
        return result->next;
    }

    int IndexOfNode(Node* random, Node* original)
    {
        int index = 0;
        while (original != nullptr)
        {
            if (original == random)
                break;
            else
            {
                original = original->next;
                index++;
            }
        }
        return index;
    }

    void insertToNode(Node** current, Node* head, int index)
    {
        for (int i = 0; i < index; i++)
            head = head->next;
        (*current)->random = head;
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
    //s.singleNumber(tmp2);
}