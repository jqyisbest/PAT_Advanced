#include "round_2_resolve1005.h"
using namespace round_2_resolve1005;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1005::resolve()
{
	int sum = 0;
	char *digits = new char[100];
	string *numbers = new string[10]{ "zero","one","two","three","four","five","six","seven","eight","nine" };
	scanf("%s", digits);
	for (size_t i = 0; i < 100; i++)
	{
		if (digits[i] == '\0')
		{
			break;
		}
		sum += digits[i] - '0';
	}
	if (sum == 0)
	{
		printf("zero");
	}
	else
	{
		int i = 0, *result = new int[100];
		fill(result, result + 100, -1);
		while (sum != 0)
		{
			result[i++] = sum % 10;
			sum /= 10;
		}
		for (int k = 99; k > 0; k--)
		{
			if (result[k] > -1)
			{
				//ע��printf stringʱ��Ҫ���string.c_str()
				//��Ϊstring�����ǻ������󣬲����ַ�������׵�ַ
				printf("%s ", numbers[result[k]].c_str());
			}
		}
		printf("%s", numbers[result[0]].c_str());
	}
	return 0;
}