#include "resolve1122.h"
/*
	注意，此题不是求普通的环路，而是哈密顿环路，只能有一个精确的环，不能有多余的步骤
*/
int resolve1122::resolve()
{
	int n = 0, m = 0, k = 0;
	scanf("%d %d", &n, &m);
	bool **has_edge = new bool*[n + 1];
	for (size_t i = 0; i < n + 1; i++)
	{
		has_edge[i] = new bool[n + 1];
		fill(has_edge[i], has_edge[i] + n + 1, false);
	}
	for (size_t i = 0; i < m; i++)
	{
		int v1 = 0, v2 = 0;
		scanf("%d %d", &v1, &v2);
		has_edge[v1][v2] = true;
		has_edge[v2][v1] = true;
	}
	scanf("%d", &k);
	map<int, int>appear_index;
	for (size_t i = 0; i < k; i++)
	{
		int node_num = 0, node_1 = 0, node_2 = 0;
		scanf("%d", &node_num);
		bool flag = node_num == (n + 1);
		appear_index.clear();
		for (size_t j = 0; j < node_num; j++)
		{
			scanf("%d", &node_2);
			//找到了/此路不通，无需再判断
			if (flag)
			{
				if (j != 0 && !has_edge[node_1][node_2])
				{
					//这条路根本走不通
					flag = false;
				}
				if (appear_index.count(node_2) != 0)
				{
					if (flag && (j - appear_index[node_2] + 1) <= n)
					{
						//不存在符合要求的环
						flag = false;
					}
				}
				appear_index[node_2] = j;
				node_1 = node_2;
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}