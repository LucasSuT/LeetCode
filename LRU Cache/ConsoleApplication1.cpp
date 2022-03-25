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
};

// Definition for a Node.
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* pre;

    Node(int _val) {
        val = _val;
        next = NULL;
        pre = NULL;
    }
    Node(int _val,Node* _pre) {
        val = _val;
        next = NULL;
        pre = _pre;
    }
    Node(int _val, int _key)
    {
        key = _key;
        val = _val;
        next = NULL;
        pre = NULL;
    }
    Node(int _val, int _key, Node* _pre) {
        key = _key;
        val = _val;
        next = NULL;
        pre = _pre;
    }
};


 
class LRUCache {
public:
    Node* front = NULL;
    Node* back = NULL;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (umapNode.find(key) == umapNode.end())
            return -1;
        else
        {
            updateNode(umapNode[key]);
            return umapNode[key]->val;
        }
    }

    void put(int key, int value) {
        if (umapNode.find(key) == umapNode.end())
        {
            if (capacity > 0)
            {
                pushBack(new Node(value, key));
                umapNode[key] = back;
                capacity--;
            }
            else
            {
                pushBack(new Node(value, key));
                umapNode[key] = back;
                umapNode.erase(front->key);
                popFront();
            }
        }
        else
        {
            umapNode[key]->val = value;
            updateNode(umapNode[key]);
        }
    }

    void popFront()
    {
        front = front->next;
        delete front->pre;
        front->pre = NULL;
    }

    void pushBack(Node* node)
    {
        if (back == NULL)
        {
            back = node;
            front = back;
        }
        else
        {
            back->next = node;
            node->next = NULL;
            node->pre = back;
            back = back->next;
        }
    }

    void updateNode(Node* node)
    {
        if (back == node)return;
        else if (node->pre != NULL)
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        else
        {
            front = node->next;
            front->pre = NULL;
        }
        pushBack(node);
    }

    void printNodes(Node* node)
    {
        while (node != NULL)
        {
            cout << node->val<<" ";
            node = node->next;
        }
        cout << "\n";
    }

    void printBNodes(Node* node)
    {
        while (node != NULL)
        {
            cout << node->val << " ";
            node = node->pre;
        }
        cout << "\n";
    }

private:
    unordered_map<int, Node*> umapNode;
    int capacity;
};

int main()
{
    //vector<vector<int>> tmp{ {1, 2}, { 1,3 },{1,8},{2,6},{3,1},{3,10} };
    vector<int> tmp2{ 2,2,1 };
    vector<int> tmp3{ 4,4,1,5,1 };
    //vector<vector<char>> tmp3{ {'A', 'A', 'A', 'A','A','A'}, {'A', 'A', 'A', 'A','A','A'}};/*,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'}
    //                            ,{'A', 'A', 'A', 'A','A','A'},{'A', 'A', 'A', 'A','A','A'} };*/
    /*Solution s;
    cout << s.wordBreak("fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami", str);*/
    LRUCache lc(3);
    lc.put(1, 1);
    lc.put(2, 2);
    lc.put(3, 3);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.put(4, 4);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(4);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(3);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(2);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.get(1);
    lc.printNodes(lc.front);
    lc.printBNodes(lc.back);
    lc.put(5, 5);
    lc.printNodes(lc.front);
    lc.get(1);
    lc.printNodes(lc.front);
    lc.get(2);
    lc.printNodes(lc.front);
    lc.get(3);
    lc.printNodes(lc.front);
    lc.get(4);
    lc.printNodes(lc.front);
    lc.get(5);
    lc.printNodes(lc.front);
}
