#include "resolve1117.h"
/*
	��map��¼ÿ�������ֵĴ���
	����map keyֵ�Զ�������������ԣ��Ӻ���ǰ����

	���⾿��ɶ��˼������e�����о��볬����e miles��������e
	�Ҵ����о����Ŀ�ʼͳ�ƣ�ÿ��ѭ�����Գ�����ǰ���������more_than_days

	�������ˣ�����ʵʵ���������ǵ�˼·���ɡ���д���˶���

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
