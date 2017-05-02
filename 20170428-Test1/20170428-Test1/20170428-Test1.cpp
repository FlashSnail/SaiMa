// 20170428-Test1.cpp : 定义控制台应用程序的入口点。
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
/*在计算机上安装或者注册某些软件时，要求输入序列号。序列号一般是一串有字母和数字组成的字符串，
也有一些是单纯由数字组成的字符串。当输入序列号时，需要验证序列号是否合法，
如果合法则允许继续安装或者显示注册成功；如果不通过，则不能继续安装或者注册失败。
现在假设改软件的序列号是由16位数字组成的，验证规则如下：
1、从序列号最后一位数字开始，逆向将奇数位(1、3、5等等)相加。
2、从序列号最后一位数字开始，逆向将偶数位数字，先乘以2（如果乘积为两位数，则将其减去9），再求和。
3、将奇数位总和加上偶数位总和，结果可以被10整除。
输入
输入由16位数字构成的字符串，表示序列号
输出
输出“ok”或者“error”

样例输入
5432123456788881
样例输出
ok*/

int _tmain(int argc, _TCHAR* argv[])
{
	string key;
	int even;
	int odd;
	int temp;
	int sum;
	string ans;
	while (cin>>key)
	{
		ans = "error";
		even = 0;
		odd = 0;
		temp = 0;
		for (int i = 15; i >= 0; i--)
		{
			if ((i+1)%2 == 0)
			{
				temp = (key[i] - '0') * 2;
				even += (temp > 10 ? (temp - 9) : temp);
			}
			else
			{
				odd += (i + 1);
			}
		}
		sum = odd + even;
		if (sum % 10 == 0)
		{
			ans = "ok";
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}

