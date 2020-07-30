#include "resolve1107.h"
/*
	先构图
	再dfs算连通子图
*/
int resolve1107::resolve()
{
	int n = 0, total_cluster = 0;
	scanf("%d", &n);
	vector<int> *connected_peoples = new vector<int>[n + 1];
	fill(connected_peoples, connected_peoples + n + 1, vector<int>());
	vector<int> hobbies_people[1001];
	for (int i = 1; i <= n; ++i)
	{
		int k = 0;
		scanf("%d: ", &k);
		for (int j = 0; j < k; ++j)
		{
			int h = 0;
			scanf("%d", &h);
			for (int h_i = 0; h_i < hobbies_people[h].size(); h_i++)
			{
				connected_peoples[i].push_back(hobbies_people[h][h_i]);
				connected_peoples[hobbies_people[h][h_i]].push_back(i);
			}
			hobbies_people[h].push_back(i);
		}
	}
	//dfs
	bool *visited = new bool[n + 1];
	fill(visited, visited + n + 1, false);
	visited[0] = true;
	vector<int> cluster_nums;
	for (int i = 0; i < n; i++)
	{
		int u = -1, cluster_num = 0;
		for (int j = 0; j <= n; j++)
		{
			if (!visited[j])
			{
				u = j;
			}
		}
		if (u == -1)
		{
			break;
		}
		total_cluster++;
		dfs(u, connected_peoples, cluster_num, visited);
		cluster_nums.push_back(cluster_num);
	}
	sort(cluster_nums.begin(), cluster_nums.end());
	printf("%d\n", total_cluster);
	for (int i = total_cluster - 1; i >= 0; i--)
	{
		if (i != total_cluster - 1)
		{
			printf(" ");
		}
		printf("%d", cluster_nums[i]);
	}
	return 0;
}

void resolve1107::dfs(int node, vector<int>* connected_peoples, int & node_num, bool * visited)
{
	if (!visited[node])
	{
		visited[node] = true;
		node_num++;
	}
	for (int i = 0; i < connected_peoples[node].size(); ++i)
	{
		if (!visited[connected_peoples[node][i]])
		{
			dfs(connected_peoples[node][i], connected_peoples, node_num, visited);
		}
	}
}