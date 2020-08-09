#include "resolve1126.h"
/*
	ŷ��ͼ���ж�
	���ȵ�����ͨͼ
	1��ÿ���ڵ�Ķȶ���ż����һ������ŷ����·�����Ϊŷ��ͼ
	2��ֻ�������ڵ�Ķ��������������ڵ�ĶȾ���ż������һ������ŷ��·������������ŷ����·����Ϊ��ŷ��ͼ
	3�������������ŷ��ͼ
*/
int resolve1126::resolve()
{
	int n, m, visit_num = 0, even = 0;
	scanf("%d %d", &n, &m);
	vector<bool> visit(n + 1);
	vector<vector<int>>adjacent_node(n + 1);
	for (size_t i = 0; i < m; i++)
	{
		int node_1 = 0, node_2 = 0;
		scanf("%d %d", &node_1, &node_2);
		adjacent_node[node_1].push_back(node_2);
		adjacent_node[node_2].push_back(node_1);
	}
	for (size_t i = 1; i <= n; i++)
	{
		if (i != 1)
		{
			printf(" ");
		}
		printf("%d", adjacent_node[i].size());
		if (adjacent_node[i].size() % 2 == 0)
		{
			even++;
		}
	}
	dfs(1, visit_num, visit, adjacent_node);
	if (visit_num == n&&even == n)
	{
		printf("\nEulerian");
	}
	else if (visit_num == n&&even == n - 2)
	{
		printf("\nSemi-Eulerian");
	}
	else
	{
		printf("\nNon-Eulerian");
	}
	return 0;
}

void resolve1126::dfs(int root, int & visit_num, vector<bool>& visit, vector<vector<int>>& adjacent_node)
{
	visit[root] = true;
	visit_num++;
	for (size_t i = 0; i < adjacent_node[root].size(); i++)
	{
		if (!visit[adjacent_node[root][i]])
		{
			dfs(adjacent_node[root][i], visit_num, visit, adjacent_node);
		}
	}
}