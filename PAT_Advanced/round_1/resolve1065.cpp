#include "resolve1065.h"
/*
	我太蠢了。居然真就傻傻的去逐位相加，直接用溢出判断就好了呀，c肯定是不会溢出的呀

	艹 忘写输入语句了
*/
int resolve1065::resolve()
{
	int num_of_test = 0;
	scanf("%d", &num_of_test);
	for (int i = 1; i <= num_of_test; ++i)
	{
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		long long sum = a + b;
		if (a > 0 && b > 0 && sum < 0)
		{
			printf("Case #%d: true\n", i);
		}
		else if (a < 0 && b < 0 && sum >= 0)
		{
			printf("Case #%d: false\n", i);
		}
		else if (sum > c)
		{
			printf("Case #%d: true\n", i);
		}
		else
		{
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
}