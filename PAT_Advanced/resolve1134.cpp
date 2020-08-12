#include "resolve1134.h"
/*
	利用set做消消乐

	卧槽，柳神用邻接表存储边效率是我的3倍
	最后两个测试点答案只要100ms，我要300ms==
*/
int resolve1134::resolve()
{
	int n, m, k;
	scanf("%d %d", &n, &m);
	map<int, vector<edge>> adjacent_edge;
	for (size_t i = 0; i < m; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adjacent_edge[n1].emplace_back(edge{ n1,n2 });
		adjacent_edge[n2].emplace_back(edge{ n1,n2 });
	}
	scanf("%d", &k);
	set<edge> involve_edge;
	for (size_t i = 0; i < k; i++)
	{
		int set_num;
		scanf("%d", &set_num);
		involve_edge.clear();
		for (size_t i = 0; i < set_num; i++)
		{
			int node;
			scanf("%d", &node);
			involve_edge.insert(adjacent_edge[node].begin(), adjacent_edge[node].end());
		}
		printf(involve_edge.size() == m ? "Yes\n" : "No\n");
	}
	return 0;
}

bool resolve1134::edge::operator<(const edge & e) const
{
	return this->n1 == e.n1 ? this->n2 < e.n2 : this->n1 < e.n1;
}