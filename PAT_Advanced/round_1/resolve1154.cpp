#include "resolve1154.h"
/*
	保存每组序列并检查全部边
*/
int resolve1154::resolve()
{
	vector<edge> all_edge;
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (size_t i = 0; i < m; i++)
	{
		int node_1, node_2;
		scanf("%d %d", &node_1, &node_2);
		all_edge.emplace_back(edge{ node_1,node_2 });
	}
	scanf("%d", &k);
	for (size_t i = 0; i < k; i++)
	{
		set<int>differ_color;
		vector<int> node_color(n, 0);
		for (size_t j = 0; j < n; j++)
		{
			scanf("%d", &node_color[j]);
			differ_color.insert(node_color[j]);
		}
		bool ok = true;
		for (size_t j = 0; ok&& j < m; j++)
		{
			ok = node_color[all_edge[j].node_1] != node_color[all_edge[j].node_2];
		}
		if (ok)
		{
			printf("%d-coloring\n", differ_color.size());
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}