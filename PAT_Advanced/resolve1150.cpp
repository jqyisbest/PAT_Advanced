#include "resolve1150.h"
/*
	环路的判断
	按要求累和并判断即可
*/
int resolve1150::resolve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> dists;
	for (size_t i = 0; i < n + 1; i++)
	{
		vector<int> v(n + 1, 0);
		dists.push_back(v);
	}
	for (size_t i = 0; i < m; i++)
	{
		int c_1, c_2, dist;
		scanf("%d %d %d", &c_1, &c_2, &dist);
		dists[c_1][c_2] = dist;
		dists[c_2][c_1] = dist;
	}
	int num_of_path, shortest_dist = 0, shorest_i = 0;
	scanf("%d", &num_of_path);
	for (size_t i = 1; i <= num_of_path; i++)
	{
		vector<bool> exist_in_path(n + 1, false);
		bool has_cycle_in_mid = false, is_cycle = true;
		int last_city = 0, first_city = 0, total_dist = 0, has_past = 0, current_city, num_of_city;
		scanf("%d", &num_of_city);
		for (size_t j = 0; j < num_of_city; j++)
		{
			scanf("%d", &current_city);
			if (j == 0)
			{
				//第一个城市
				first_city = current_city;
				has_past++;
			}
			else if (j == num_of_city - 1)
			{
				//最后一个城市
				is_cycle = current_city == first_city;
				if (total_dist != -1)
				{
					if (dists[last_city][current_city] == 0)
					{
						//表示不是通路
						total_dist = -1;
					}
					else
					{
						total_dist += dists[last_city][current_city];
					}
				}
			}
			else
			{
				if (exist_in_path[current_city])
				{
					has_cycle_in_mid = true;
				}
				else
				{
					has_past++;
				}
				if (total_dist != -1)
				{
					if (dists[last_city][current_city] == 0)
					{
						//表示不是通路
						total_dist = -1;
					}
					else
					{
						total_dist += dists[last_city][current_city];
					}
				}
			}
			exist_in_path[current_city] = true;
			last_city = current_city;
		}
		if (total_dist == -1)
		{
			//根本不是通路
			printf("Path %d: NA (Not a TS cycle)\n", i);
		}
		else
		{
			printf("Path %d: %d ", i, total_dist);
			if (is_cycle&&has_past == n)
			{
				if (has_cycle_in_mid)
				{
					printf("(TS cycle)\n");
				}
				else
				{
					printf("(TS simple cycle)\n");
				}
				if (total_dist < shortest_dist || shortest_dist == 0)
				{
					shortest_dist = total_dist;
					shorest_i = i;
				}
			}
			else
			{
				printf("(Not a TS cycle)\n");
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", shorest_i, shortest_dist);
	return 0;
}