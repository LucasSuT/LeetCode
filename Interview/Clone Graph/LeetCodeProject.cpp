// LeetCodeProject.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
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

class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	unordered_map<int,Node*> umap;
	int count = 1;
	Node* cloneGraph(Node* node) {
		if (!node)return node;
		VisitNode(node);
		for (int i = 1; i < umap.size()+1; i++)
		{
			for (int j=0;j<umap[i]->neighbors.size();j++)
			{
				umap[i]->neighbors[j] = umap[umap[i]->neighbors[j]->val];
			}
		}
		return umap[0];
	}
	void VisitNode(Node* node)
	{
		if (umap.count(node->val))return;
		umap[node->val] = new Node(node->val,node->neighbors);
		for (Node* n : node->neighbors)
		{
			VisitNode(n);
		}
	}
};


int main()
{
	//cout << (((unsigned)(-1)) >> 1);
	printf("%x", ~((unsigned)~0 >> 1));
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
