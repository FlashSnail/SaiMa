// 20170331-Test2.cpp : �������̨Ӧ�ó������ڵ㡣
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

/*С��Ҫȥλ�� A �е�С��ҡ�С������ A �еĳ�վ������һ�� A �еĵ�ͼ��
����������ĵ��ηǳ��ĸ��ӡ�A �еĽֵ�һ���� N ��·�ڣ�M ����·��
ÿ����·����������·�ڣ������и��Եĳ��ȡ�Ŀǰ��С�����ڵĳ�վλ�ڱ��Ϊ 1 ��·�ڣ�
��С������ڵ�·�ڱ��Ϊ N��С��׼������⳵ȥ����Ȼ��·��ԽС������Ǯ��Խ�١�
���������ǰ�������С��Ѱ��һ�����·����ʹ�������Ի����ٵ�Ǯ����С��ҡ�

����
��һ������������ N, M (N��1000) �ֱ����·�����ͽֵ�����
������ M ���������������ֵ���ÿ������������ P1, P2, L���ֱ����˽ֵ�����ţ�
�˽ֵ��յ����Լ��˽ֵ��ĳ��ȡ���֤���������ݿ��Թ�����ͨͼ��

���
һ��һ��������˵�����·���ĳ��ȡ�


��������
6 7
1 2 1
1 3 5
1 4 2
4 6 10
2 5 3
3 5 8
5 6 7

�������
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
