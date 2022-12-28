#include "round_2_resolve1163.h"
using namespace round_2_resolve1163;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1163::resolve()
{
	int num_v = 0, num_e = 0;
	cin >> num_v >> num_e;
	vector<vector<int>> weight;
	weight.resize(num_v + 1);
	for (size_t i = 0; i <= num_v; i++)
	{
		weight[i].resize(num_v + 1);
		fill(weight[i].begin(), weight[i].end(), -1);
		weight[i][i] = 0;
	}
	for (size_t i = 0; i < num_e; i++)
	{
		int a = 0, b = 0, w = 0;
		cin >> a >> b >> w;
		weight[a][b] = w;
		weight[b][a] = w;
	}
	int num_q = 0;
	cin >> num_q;
	for (size_t i = 0; i < num_q; i++)
	{
		bool flag = true, stop = false;
		vector<bool> has_visited;
		has_visited.resize(num_v + 1);
		fill(has_visited.begin(), has_visited.end(), false);
		vector<int>dist;
		for (size_t j = 0; j < num_v; j++)
		{
			int v = 0;
			cin >> v;
			if (!stop)
			{
				if (j == 0)
				{
					//起点
					dist = weight[v];
					has_visited[v] = true;
				}
				else
				{
					set<int> u;
					int min_dist = -1;
					for (size_t k = 1; k <= num_v; k++)
					{
						if (!has_visited[k] && dist[k] != -1)
						{
							if (min_dist == -1 || dist[k] < min_dist)
							{
								u.clear();
								u.insert(k);
								min_dist = dist[k];
							}
							else if (dist[k] == min_dist)
							{
								u.insert(k);
							}
						}
					}
					if (u.find(v) == u.end())
					{
						flag = false;
						stop = true;
					}
					else
					{
						//选中v，更新dist
						has_visited[v] = true;
						for (size_t k = 1; k <= num_v; k++)
						{
							if (!has_visited[k] && weight[v][k] != -1)
							{
								if (dist[k] == -1 || dist[k] > dist[v] + weight[v][k])
								{
									dist[k] = dist[v] + weight[v][k];
								}
							}
						}
					}
				}
			}
		}
		cout << (flag ? "Yes\n" : "No\n");
	}
	return 0;
}