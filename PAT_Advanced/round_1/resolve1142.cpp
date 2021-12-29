#include "resolve1142.h"
/*
	先试试暴力查询吧。。
	0
	Accepted
	4 ms	424 KB
	1
	Accepted
	4 ms	420 KB
	2
	Accepted
	4 ms	384 KB
	3
	Accepted
	15 ms	424 KB
	4
	Accepted
	4 ms	384 KB
	咦，暴力查询用时还行嘛，嘻嘻。
*/
int resolve1142::resolve()
{
	int n_v, n_e, m;
	scanf("%d %d", &n_v, &n_e);
	vector<vector<bool>>has_edge(n_v + 1);
	for (size_t i = 0; i < n_v + 1; i++)
	{
		has_edge[i].resize(n_v + 1, false);
	}
	for (size_t i = 0; i < n_e; i++)
	{
		int n_1, n_2;
		scanf("%d %d", &n_1, &n_2);
		has_edge[n_1][n_2] = true;
		has_edge[n_2][n_1] = true;
	}
	scanf("%d", &m);
	for (size_t i = 0; i < m; i++)
	{
		bool flag = true;
		int k;
		scanf("%d", &k);
		vector<int> nodes;
		vector<bool>in_set(n_v + 1, false);
		for (int j = 0; j < k; j++)
		{
			int current_node;
			scanf("%d", &current_node);
			in_set[current_node] = true;
			if (flag&&j != 0)
			{
				for (size_t jj = 0; flag&&jj < nodes.size(); jj++)
				{
					flag = has_edge[current_node][nodes[jj]];
				}
			}
			nodes.emplace_back(current_node);
		}
		if (!flag)
		{
			printf("Not a Clique\n");
		}
		else
		{
			//判定是否最大
			for (int j = 1; flag&&j <= n_v; j++)
			{
				if (!in_set[j])
				{
					bool all_connect = true;
					for (int jj = 0; all_connect&&jj < nodes.size(); jj++)
					{
						all_connect = has_edge[j][nodes[jj]];
					}
					flag = !all_connect;
				}
			}
			if (!flag)
			{
				printf("Not Maximal\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
	}
	return 0;
}