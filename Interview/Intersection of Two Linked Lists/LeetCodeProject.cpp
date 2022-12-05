// LeetCodeProject.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node {
	int val;
	Node* next;
	Node() {}
	Node(int val):val(val),next(NULL) {
	}
	Node(Node* node)
	{
		val = 0;
		next = node;
	}
};

struct Node {
    int val;
    Node* next;
    Node* pre;
    Node() {}
    Node(int value, Node* n, Node* p) :val(value), next(n), pre(p) {}
};

//class FrontMiddleBackQueue {
//public:
//    FrontMiddleBackQueue() {
//        count = 0;
//    }
//
//    void pushFront(int val) {
//        l.push_front(val);
//        count++;
//    }
//
//    void pushMiddle(int val) {
//        auto it = l.begin();
//        if(count>1)
//            for (int i = 0; i < count / 2 + count % 2; i++)
//                it++;
//        l.insert(it, val);
//        count++;
//    }
//
//    void pushBack(int val) {
//        l.push_back(val);
//        count++;
//    }
//
//    int popFront() {
//        int val = -1;
//        if (l.empty())return val;
//        val = l.front();
//        l.pop_front();
//        count--;
//        return val;
//    }
//
//    int popMiddle() {
//        auto it = l.begin();
//        int val = -1;
//        if (l.empty())return val;
//        if (count > 1)
//        {
//            for (int i = 0; i < count / 2 + count % 2; i++)
//                it++;
//            val = *it;
//        }
//        l.erase(it);
//        count--;
//        return val;
//    }
//
//    int popBack() {
//        int val = -1;
//        if (l.empty())return val;
//        val = l.back();
//        l.pop_back();
//        count--;
//        return val;
//    }
//private:
//    list<int> l;
//    int count;
//};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* head_first = headA, * head_second = headB;
		if (headA == headB)return headA;
		while (headA && headB)
		{
			headA = headA->next;
			headB = headB->next;
			if (headA == headB)break;
			if (headA == NULL)headA = head_second;
			if (headB == NULL)headB = head_first;
			if (headA == headB)break;
		}
		return headA;
	}
};


int main()
{
	/*stack<int> stack_;
	queue<int> queue_;
	list<int> list_;
	unordered_map<int, int> t;
	map<int, int> ma;
	ma.insert(pair<int, int>(1, 2));*/
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
