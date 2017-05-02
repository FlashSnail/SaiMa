// 20170331-Test1.cpp : �������̨Ӧ�ó������ڵ㡣
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

/*���ǳ�һ��������n�������������n���������ӵ�ƽ����f(n)��һ����ȫƽ������
����n=10����ôf(n)=1+4+25+100=130,����10����һ����������
�����С��n�������������ĺ͡�
����40%������n<=10000
����100%������n<=1000000

����
����һ��������n

���
�����С��n�������������ĺ�


��������
100

�������
43*/

int _tmain(int argc, _TCHAR* argv[])
{
	vector<long long> factor;
	int ans = 0;
	int sum=0;
	int n;
	int m;
	while (cin>>n)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (i%j == 0)
				{
					sum += j*j;
				}
			}
			if ((int)sqrt(sum)*(int)sqrt(sum) == sum)
			{
				ans += i;
			}
			sum = 0;
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}

