// 20170512-Test2.cpp : �������̨Ӧ�ó������ڵ㡣
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

/*��Ŀ������
��������n��ŷ��������С��n������������n���ʵ�������Ŀ����(1)=1����
�˺������������о���ŷ������(Euler'so totient function)�����ֳ�Ϊ�պ�����
�����(8)=4����Ϊ1,3,5,7����8���ʡ�
������֪phi(N)����N��
����
�������������ֱ��ʾphi(N)��K��
���
���������������������С��K��N��

��������
8 4
�������
15 16 20 24

Hint
�����ݷ�Χ��
����20%������ phi(N)<=100
����40%������ phi(N)<=10^5
����80%������ phi(N)<=10^9
����100%������ phi(N)<=10^14,K<=1000
������60%����������K=1
�������ݱ�֤�������⣬���������������������10^14*/

long long eular(long long n)
{
	long long ret = 1, i;
	for (i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			n /= i, ret *= i - 1;
			while (n%i == 0) n /= i, ret *= i;
		}
	}
	if (n>1) ret *= n - 1;
	return ret;
}

long long primNum(long long n)
{
	bool *a = new bool[n + 1];
	int i, j;
	memset(a, 1, n+1);
	a[1] = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (a[i])
		{
			for (j = 2; j <= n / i; j++)
			{
				a[i*j] = 0;
			}
		}
	}
	long long ans = n;
	for (i = 2; i < n; i++)
	{
		if (a[i] && n%i == 0){
			float num = 1.0 / i;
			ans = ceil(ans * (1 - num));
		}
	}
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	long long phi;
	long long n = 1;
	int k;
	while (cin>>phi)
	{
		cin >> k;
		while (k > 0)
		{
			while (eular(n) != phi)
			{
				n++;
			}
			cout << n << " ";
			n++;
			k--;
		}
		n = 1;
		cout << endl;
	}
	system("pause");
	return 0;
}

