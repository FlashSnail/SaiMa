// 20170331-Test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

/*小赛要去位于 A 市的小码家。小赛来到 A 市的车站，买了一张 A 市的地图，
他发现这里的地形非常的复杂。A 市的街道一共有 N 个路口，M 条道路，
每条道路连接着两个路口，并且有各自的长度。目前，小赛所在的车站位于编号为 1 的路口，
而小码家所在的路口编号为 N，小赛准备打出租车去，当然，路程越小，付的钱就越少。
问题摆在眼前：请帮助小赛寻找一条最短路径，使得他可以花最少的钱到达小码家。

输入
第一行有两个整数 N, M (N≤1000) 分别代表路口数和街道数。
以下有 M 行用以描述各个街道，每行有三个数字 P1, P2, L，分别代表此街道起点编号，
此街道终点编号以及此街道的长度。保证所给的数据可以构成连通图。

输出
一行一个整数，说明最短路径的长度。


样例输入
6 7
1 2 1
1 3 5
1 4 2
4 6 10
2 5 3
3 5 8
5 6 7

样例输出
11*/

int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;
	int index;
	int ans= 0;
	while (cin>>n)
	{
		cin >> m;
		vector<vector<int>> route(n+1);
		for (int i = 0; i < n+1; i++)
		{
			route[i].resize(n+1);
		}
		for (int i = 0; i < n+1; i++)
		{
			for (int j = 0; j < n+1; j++)
			{
				route[i][j] = 1000;
			}
		}
		int x, y, val;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> val;
			route[x][y] = val;
		}
		vector<int>::iterator low;
		for (int i = 1; i <= n; i++)
		{
			low = std::min_element(route[i].begin(), route[i].end());
			index = std::distance(route[i].begin(), low);
			ans += route[i][index];
			if (index == n)
			{
				break;
			}
			i = index-1;
		}
		cout << ans << endl;
		route.clear();
		index = 0;
	}
	system("pause");
	return 0;
}
