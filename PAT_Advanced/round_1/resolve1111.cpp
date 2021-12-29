#include "resolve1111.h"
/*
	多目标有向图dijsktra
*/
int resolve1111::resolve()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int **time_cost = new int*[n], **distance_cost = new int*[n];
	for (int i = 0; i < n; i++)
	{
		time_cost[i] = new int[n];
		fill(time_cost[i], time_cost[i] + n, -1);
		distance_cost[i] = new int[n];
		fill(distance_cost[i], distance_cost[i] + n, -1);
	}
	for (size_t i = 0; i < m; i++)
	{
		int v1 = 0, v2 = 0, one_way = 0, length = 0, time = 0;
		scanf("%d %d %d %d %d", &v1, &v2, &one_way, &length, &time);
		time_cost[v1][v2] = time;
		distance_cost[v1][v2] = length;
		if (0 == one_way)
		{
			time_cost[v2][v1] = time;
			distance_cost[v2][v1] = length;
		}
	}
	int source = 0, dest = 0;
	scanf("%d %d", &source, &dest);
	//dijsktra
	//参数初始化
	int *distance = new int[n], *time = new int[n];
	bool *visited_distance = new bool[n], *visited_time = new bool[n], need_cal_distance = true, need_cal_time = true;
	fill(distance, distance + n, -1);
	fill(time, time + n, -1);
	fill(visited_distance, visited_distance + n, false);
	fill(visited_time, visited_time + n, false);
	//从source到每个点的路径
	vector<vector<vector<int>>> paths_distacne(n), paths_time(n);
	vector<vector<int>> paths_distacne_time(n);
	for (size_t i = 0; i < n; ++i)
	{
		if (time_cost[source][i] != -1)
		{
			time[i] = time_cost[source][i];
			vector<int> path;
			path.push_back(source);
			path.push_back(i);
			paths_time[i].push_back(path);
		}
		if (distance_cost[source][i] != -1)
		{
			distance[i] = distance_cost[source][i];
			vector<int> path;
			path.push_back(source);
			path.push_back(i);
			paths_distacne[i].push_back(path);
			paths_distacne_time[i].push_back(time_cost[source][i]);
		}
	}
	visited_distance[source] = true;
	visited_time[source] = true;
	for (int i = 0; i < n && (need_cal_distance || need_cal_time); ++i)
	{
		int u_distance = -1, u_time = -1, min_distance = 0, min_time = 0;
		for (int j = 0; j < n; ++j)
		{
			if (distance[j] != -1 && !visited_distance[j] && (distance[j] < min_distance || u_distance == -1))
			{
				u_distance = j;
				min_distance = distance[j];
			}
			if (time[j] != -1 && !visited_time[j] && (time[j] < min_time || u_time == -1))
			{
				u_time = j;
				min_time = time[j];
			}
		}
		need_cal_distance = (u_distance != -1);
		need_cal_time = (u_time != -1);
		if (need_cal_distance)
		{
			visited_distance[u_distance] = true;
			for (int j = 0; j < n; j++)
			{
				if (distance_cost[u_distance][j] != -1)
				{
					//更新相邻节点
					if (distance[u_distance] + distance_cost[u_distance][j] < distance[j] || -1 == distance[j])
					{
						distance[j] = distance[u_distance] + distance_cost[u_distance][j];
						paths_distacne[j].clear();
						paths_distacne_time[j].clear();
						for (size_t k = 0; k < paths_distacne[u_distance].size(); k++)
						{
							paths_distacne[j].push_back(paths_distacne[u_distance][k]);
							paths_distacne[j].back().push_back(j);
							paths_distacne_time[j].push_back(paths_distacne_time[u_distance][k] + time_cost[u_distance][j]);
						}
					}
					else if (distance[u_distance] + distance_cost[u_distance][j] == distance[j])
					{
						for (size_t k = 0; k < paths_distacne[u_distance].size(); k++)
						{
							paths_distacne[j].push_back(paths_distacne[u_distance][k]);
							paths_distacne[j].back().push_back(j);
							paths_distacne_time[j].push_back(paths_distacne_time[u_distance][k] + time_cost[u_distance][j]);
						}
					}
				}
			}
		}
		if (need_cal_time)
		{
			visited_time[u_time] = true;
			for (int j = 0; j < n; j++)
			{
				if (time_cost[u_time][j] != -1)
				{
					//更新相邻节点
					if (time[u_time] + time_cost[u_time][j] < time[j] || -1 == time[j])
					{
						time[j] = time[u_time] + time_cost[u_time][j];
						paths_time[j].clear();
						for (size_t k = 0; k < paths_time[u_time].size(); k++)
						{
							paths_time[j].push_back(paths_time[u_time][k]);
							paths_time[j].back().push_back(j);
						}
					}
					else if (time[u_time] + time_cost[u_time][j] == time[j])
					{
						for (size_t k = 0; k < paths_time[u_time].size(); k++)
						{
							paths_time[j].push_back(paths_time[u_time][k]);
							paths_time[j].back().push_back(j);
						}
					}
				}
			}
		}
	}
	//找出距离最短/时间最短路径
	vector<int>distance_shorest_path, time_shorest_path;
	if (paths_distacne[dest].size() > 1)
	{
		int min_time = -1, min_i = -1;
		for (int i = 0; i < paths_distacne_time[dest].size(); i++)
		{
			if (paths_distacne_time[dest][i] < min_time || min_time == -1)
			{
				min_time = paths_distacne_time[dest][i];
				min_i = i;
			}
		}
		distance_shorest_path = paths_distacne[dest][min_i];
	}
	else
	{
		distance_shorest_path = paths_distacne[dest][0];
	}
	sort(paths_time[dest].begin(), paths_time[dest].end(), cmp_times);
	time_shorest_path = paths_time[dest][0];
	bool is_same = false;
	if (distance_shorest_path.size() == time_shorest_path.size())
	{
		is_same = true;
		for (size_t i = 0; i < distance_shorest_path.size(); i++)
		{
			if (distance_shorest_path[i] != time_shorest_path[i])
			{
				is_same = false;
				break;
			}
		}
	}
	if (is_same)
	{
		printf("Distance = %d; Time = %d: ", distance[dest], time[dest]);
		for (size_t i = 0; i < distance_shorest_path.size(); i++)
		{
			if (i != 0)
			{
				printf(" -> ");
			}
			printf("%d", distance_shorest_path[i]);
		}
	}
	else
	{
		printf("Distance = %d: ", distance[dest]);
		for (size_t i = 0; i < distance_shorest_path.size(); i++)
		{
			if (i != 0)
			{
				printf(" -> ");
			}
			printf("%d", distance_shorest_path[i]);
		}
		printf("\n");
		printf("Time = %d: ", time[dest]);
		for (size_t i = 0; i < time_shorest_path.size(); i++)
		{
			if (i != 0)
			{
				printf(" -> ");
			}
			printf("%d", time_shorest_path[i]);
		}
	}
	return 0;
}

bool resolve1111::cmp_times(vector<int> &p1, vector<int> &p2)
{
	return p1.size() < p2.size();
}