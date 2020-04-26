#include "resolve1067.h"
/*
	每次交换把一个元素换到最终位置上，这应该就是最少的次数了。
	所以，要交换的次数应该就是序列中的不在其位的数字的个数。

	23333果然没这么简单

	第一行的话是对的 第二行的话是错的哈哈哈哈
	以后不能这么轻率的做结论，我的OAC/(ㄒoㄒ)/~~
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
			//0归位了==
			need_sort.erase(need_sort.find(*a));
		}
		else
		{
			//0又跑出去了==
			need_sort[0] = 1;
		}
		if (*b == loc[*b])
		{
			//成功调整了一个数至其位置
			need_sort.erase(need_sort.find(*b));
		}
	}
	printf("%d", swap_times);
	return 0;
}