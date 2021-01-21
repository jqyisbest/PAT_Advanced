#include "resolve1046.h"
/*
	累加后再大减小
	1 1+2 1+2+3 1+2+3+4 1+2+3+4+5
	2-4 = (1-4 - 1-2) 是否总里程过半？总里程-(1-4 - 1-2):(1-4 - 1-2);
	0
	运行时错误
	3 ms	508 KB
	1
	答案正确
	4 ms	440 KB
	2
	答案正确
	28 ms	896 KB
	..居然越界。。我猜是输入i=n的时候accumulative_distance[i + 1]= accumulative_distance[i]+temp_1;越界

	果然。。
	0
	答案正确
	4 ms	352 KB
	1
	答案正确
	4 ms	428 KB
	2
	答案正确
	27 ms	868 KB
*/
int resolve1046::resolve()
{
	int n = 0, m = 0, temp_1 = 0, temp_2 = 0;
	scanf("%d", &n);
	//从1开始的累计路程 accumulative_distance[0]表示总路程
	int* accumulative_distance = new int[n + 1];
	accumulative_distance[1] = 0;
	for (size_t i = 1; i <= n; i++)
	{
		scanf("%d", &temp_1);
		if (i == n)
		{
			accumulative_distance[0] = accumulative_distance[n] + temp_1;
		}
		else
		{
			accumulative_distance[i + 1] = accumulative_distance[i] + temp_1;
		}
	}
	scanf("%d", &m);
	for (size_t i = 0; i < m; ++i)
	{
		scanf("%d %d", &temp_1, &temp_2);
		if (temp_1 == temp_2)
		{
			printf("%d\n", 0);
		}
		else
		{
			int min_target = min(temp_1, temp_2), max_target = max(temp_1, temp_2);
			int distance = accumulative_distance[max_target] - accumulative_distance[min_target];
			printf("%d\n", distance > accumulative_distance[0] / 2 ? accumulative_distance[0] - distance : distance);
		}
	}
	return 0;
}
