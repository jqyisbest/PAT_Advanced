#include "round_2_resolve1003.h"
using namespace round_2_resolve1003;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1003::resolve()
{
	int n = 0, m = 0, start = 0, end = 0;
	scanf("%d %d %d %d", &n, &m, &start, &end);
	int *team_num = new int[n] {0}, *lengths = new int[n] {0}, *shorest_num = new int[n] {0}, *max_rescue_team_num = new int[n] {0}, *visit = new int[n] {0};
	int **roads = new int*[n];
	for (size_t i = 0; i < n; i++)
	{
		roads[i] = new int[n] {0};
		roads[i][i] = 1;
		scanf("%d", team_num + i);
	}
	for (size_t i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		scanf("%d", &roads[a][b]);
		roads[b][a] = roads[a][b];
	}
	//dijkstra start
	shorest_num[start] = 1;
	max_rescue_team_num[start] = team_num[start];
	for (size_t i = 0; i < n; i++)
	{
		int u = -1, min_length = 0;
		if (i == 0)
		{
			u = start;
		}
		else
		{
			for (size_t j = 0; j < n; j++)
			{
				if (visit[j] == 0 && lengths[j] != 0 && ((min_length == 0) || (min_length > lengths[j])))
				{
					u = j;
					min_length = lengths[j];
				}
			}
		}
		if (u == -1)
		{
			break;
		}
		visit[u] = 1;
		for (size_t j = 0; j < n; j++)
		{
			if (visit[j] == 0 && roads[u][j] != 0)
			{
				int new_length_j = min_length + roads[u][j];
				if (lengths[j] == 0 || new_length_j < lengths[j])
				{
					//出现更短的路径
					lengths[j] = new_length_j;
					shorest_num[j] = shorest_num[u];
					max_rescue_team_num[j] = max_rescue_team_num[u] + team_num[j];
				}
				else if (new_length_j == lengths[j])
				{
					//多了一条一样短的路径
					shorest_num[j] += shorest_num[u];
					int new_max_rescue_team_num = max_rescue_team_num[u] + team_num[j];
					if (new_max_rescue_team_num > max_rescue_team_num[j])
					{
						max_rescue_team_num[j] = new_max_rescue_team_num;
					}
				}
			}
		}
	}
	//dijkstra end
	printf("%d %d", shorest_num[end], max_rescue_team_num[end]);
	return 0;
}