// 20170428-Test1.cpp : �������̨Ӧ�ó������ڵ㡣
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
/*�ڼ�����ϰ�װ����ע��ĳЩ���ʱ��Ҫ���������кš����к�һ����һ������ĸ��������ɵ��ַ�����
Ҳ��һЩ�ǵ�����������ɵ��ַ��������������к�ʱ����Ҫ��֤���к��Ƿ�Ϸ���
����Ϸ������������װ������ʾע��ɹ��������ͨ�������ܼ�����װ����ע��ʧ�ܡ�
���ڼ������������к�����16λ������ɵģ���֤�������£�
1�������к����һλ���ֿ�ʼ����������λ(1��3��5�ȵ�)��ӡ�
2�������к����һλ���ֿ�ʼ������ż��λ���֣��ȳ���2������˻�Ϊ��λ���������ȥ9��������͡�
3��������λ�ܺͼ���ż��λ�ܺͣ�������Ա�10������
����
������16λ���ֹ��ɵ��ַ�������ʾ���к�
���
�����ok�����ߡ�error��

��������
5432123456788881
�������
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

