// 20170512-Test2.cpp : 定义控制台应用程序的入口点。
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

/*题目描述：
对正整数n，欧拉函数是小于n的正整数中与n互质的数的数目（φ(1)=1）。
此函数以其首名研究者欧拉命名(Euler'so totient function)，它又称为φ函数。
例如φ(8)=4，因为1,3,5,7均和8互质。
现在已知phi(N)，求N。
输入
两个正整数，分别表示phi(N)和K。
输出
按升序输出满足条件的最小的K个N。

样例输入
8 4
样例输出
15 16 20 24

Hint
【数据范围】
对于20%的数据 phi(N)<=100
对于40%的数据 phi(N)<=10^5
对于80%的数据 phi(N)<=10^9
对于100%的数据 phi(N)<=10^14,K<=1000
其中有60%的数据满足K=1
输入数据保证符合题意，且满足答案中最大的数不超过10^14*/

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

