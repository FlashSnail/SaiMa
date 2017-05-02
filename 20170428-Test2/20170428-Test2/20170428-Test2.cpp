// 20170428-Test2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
/*��������n��ŷ��������С��n������������n���ʵ�������Ŀ����(1)=1����
�˺������������о���ŷ������(Euler'so totient function)�����ֳ�Ϊ�պ�����
�����(8)=4����Ϊ1,3,5,7����8���ʡ�
��֪n����phi(n)��
����
������n
���
���phi(n)

��������
8
�������
4

Hint
�����ݷ�Χ��
����100%������,N<=10^9*/
int _tmain(int argc, _TCHAR* argv[])
{
	long long n;
	long long ans;
	long long x;
	long long y;
	long long z;
	while (cin>>n)
	{
		ans = 1;
		for (int i = 2; i < n; i++)
		{	
			x = n;
			y = i;
			while (x%y != 0)
			{
				z = x%y;
				x = y;
				y = z;
			}
			if (x%y == 0)
			{
				continue;
			}
			ans++;
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}

