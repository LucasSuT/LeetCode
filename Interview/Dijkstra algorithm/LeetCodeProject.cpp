// LeetCodeProject.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int climbStairs(int n) {
	int* a = new int(1);
	return *a;
}


int ShortestPath(vector<vector<int>>&table,int target)
{
	queue<int> temp;
	for (int i = 0; i < table[target].size(); i++)
	{
		if (table[target][i] > 0)
			temp.push(i);
	}

	while (temp.size())
	{
		int visit = temp.front();
		cout << "visit = " << visit << "\n";
		temp.pop();
		for (int i = 0; i < table[visit].size(); i++)
		{
			if (table[visit][i] <= 0)continue;
			cout << "table " << visit << " " << i << " = " << table[visit][i]<<"\n";
			int  distance = table[target][visit] + table[visit][i];
			if (table[target][i] <0 || distance < table[target][i] )
			{
				temp.push(i);
				table[target][i] = distance;
			}
		}
	}
}


int main()
{
	//int (*distance)[6] = { {0,1,12,0,0,0},{0,0,9,3,0,0},{0,0,0,0,5,0},{0,0,4,0,13,15},{0,0,0,0,0,4},{0,0,0,0,0,0}};
	vector<vector<int>> distance{ {0,1,12,-1,-1,-1},{-1,0,9,3,-1,-1},{-1,-1,0,-1,5,-1},{-1,-1,4,0,13,15},{-1,-1,-1,-1,0,4},{-1,-1,-1,-1,-1,0} };
	ShortestPath(distance, 0);
	for (vector<int>& n : distance)
	{
		for (int i : n)
			cout << i << " ";
		cout << "\n";
	}
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
