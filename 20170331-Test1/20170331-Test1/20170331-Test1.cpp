// 20170331-Test1.cpp : 定义控制台应用程序的入口点。
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

/*我们称一个正整数n是完美数，如果n的所有因子的平方和f(n)是一个完全平方数。
例如n=10，那么f(n)=1+4+25+100=130,所以10不是一个完美数。
请求出小于n的所有完美数的和。
对于40%的数据n<=10000
对于100%的数据n<=1000000

输入
输入一个正整数n

输出
输出出小于n的所有完美数的和


样例输入
100

样例输出
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

