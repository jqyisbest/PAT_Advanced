#include "resolve1117.h"
/*
	用map记录每个数出现的次数
	利用map key值自动递增排序的特性，从后往前遍历

	这题究竟啥意思，，有e天骑行距离超过了e miles，求最大的e
	我从骑行距离多的开始统计，每轮循环都对超过当前距离的天数more_than_days

	哎放弃了，老老实实按柳神他们的思路做吧。。写的人恶心

int resolve1117::resolve()
{
	int n = 0, more_than_days = 0, current_min_miles = 0;
	map<int, int> distance;
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		int dist = 0;
		scanf("%d", &dist);
		if (distance.count(dist) != 0)
		{
			distance[dist]++;
		}
		else
		{
			distance[dist] = 1;
		}
	}
	for (map<int, int>::iterator it = --distance.end(); ; )
	{
		more_than_days += it->second;
		current_min_miles = it->first;
		if (more_than_days < current_min_miles)
		{
			it--;
		}
		else
		{
			more_than_days -= it->second;
			printf("%d", max(, it->first));
			break;
		}
	}
	return 0;
}
*/

int resolve1117::resolve()
{
	int a[1000000];
	int n, e = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, cmp_int);
	while (e < n && a[e] > e + 1) e++;
	printf("%d", e);
	return 0;
}

bool resolve1117::cmp_int(int a, int b)
{
	return a > b;
}
