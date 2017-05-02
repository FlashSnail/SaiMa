// 20170428-Test2.cpp : 定义控制台应用程序的入口点。
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
/*对正整数n，欧拉函数是小于n的正整数中与n互质的数的数目（φ(1)=1）。
此函数以其首名研究者欧拉命名(Euler'so totient function)，它又称为φ函数。
例如φ(8)=4，因为1,3,5,7均和8互质。
已知n，求phi(n)。
输入
正整数n
输出
输出phi(n)

样例输入
8
样例输出
4

Hint
【数据范围】
对于100%的数据,N<=10^9*/
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

