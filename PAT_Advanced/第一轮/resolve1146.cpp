#include "resolve1146.h"
/*
	拓补排序判定
	看每个节点的前驱是否都已被访问
*/
int resolve1146::resolve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> pre_nodes(n + 1);
	for (size_t i = 0; i < m; i++)
	{
		int n_1, n_2;
		scanf("%d %d", &n_1, &n_2);
		pre_nodes[n_2].emplace_back(n_1);
	}
	bool first_one = true;
	int k;
	scanf("%d", &k);
	for (size_t i = 0; i < k; i++)
	{
		bool flag = true;
		vector<bool> visited(n + 1, false);
		for (size_t j = 0; j < n; j++)
		{
			int node;
			scanf("%d", &node);
			for (size_t jj = 0; !visited[node] && flag&&jj < pre_nodes[node].size(); jj++)
			{
				flag = visited[pre_nodes[node][jj]];
			}
			visited[node] = true;
		}
		if (!flag)
		{
			if (!first_one)
			{
				printf(" ");
			}
			printf("%d", i);
			first_one = false;
		}
	}
	return 0;
}