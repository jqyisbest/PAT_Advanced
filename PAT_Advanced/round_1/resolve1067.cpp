#include "resolve1067.h"
/*
	ÿ�ν�����һ��Ԫ�ػ�������λ���ϣ���Ӧ�þ������ٵĴ����ˡ�
	���ԣ�Ҫ�����Ĵ���Ӧ�þ��������еĲ�����λ�����ֵĸ�����

	23333��Ȼû��ô��

	��һ�еĻ��ǶԵ� �ڶ��еĻ��Ǵ�Ĺ�������
	�Ժ�����ô���ʵ������ۣ��ҵ�OAC/(��o��)/~~
	0
	Accepted
	4 ms	424 KB
	1
	Accepted
	73 ms	5540 KB
	2
	Accepted
	37 ms	2944 KB
	3
	Accepted
	3 ms	512 KB
	4
	Accepted
	3 ms	424 KB
	5
	Accepted
	3 ms	384 KB
*/
int resolve1067::resolve()
{
	int n = 0, temp = 0, *loc, swap_times = 0;
	map<int, int> need_sort;
	scanf("%d", &n);
	loc = new int[n];
	for (size_t i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		loc[temp] = i;
		if (temp != i)
		{
			need_sort[temp] = 1;
		}
	}
	while (need_sort.size() > 0)
	{
		int	*a = &loc[0], *b = &loc[loc[0]];
		if (*a == *b)
		{
			b = &loc[need_sort.begin()->first];
		}
		swap(*a, *b);
		swap_times++;
		if (*a == loc[*a])
		{
			//0��λ��==
			need_sort.erase(need_sort.find(*a));
		}
		else
		{
			//0���ܳ�ȥ��==
			need_sort[0] = 1;
		}
		if (*b == loc[*b])
		{
			//�ɹ�������һ��������λ��
			need_sort.erase(need_sort.find(*b));
		}
	}
	printf("%d", swap_times);
	return 0;
}