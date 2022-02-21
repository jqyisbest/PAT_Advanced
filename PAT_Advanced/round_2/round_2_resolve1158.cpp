#include "round_2_resolve1158.h"
using namespace round_2_resolve1158;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1158::find_father(int a, map<int, int>& father)
{
	return father[a] == a ? a : (father[a] = find_father(father[a], father));
}
void round_2_resolve1158::union_gang(int a, int b, map<int, int>& father)
{
	int a_f = find_father(a, father);
	int b_f = find_father(b, father);
	if (a_f < b_f)
	{
		father[b_f] = a_f;
	}
	else if (a_f > b_f)
	{
		father[a_f] = b_f;
	}
}
int round_2_resolve1158::resolve()
{
	int k = 0, n = 0, m = 0;
	scanf("%d %d %d", &k, &n, &m);
	vector<int>short_calls_num(n + 1);
	fill(short_calls_num.begin(), short_calls_num.end(), 0);
	vector<int>short_call_callback_num(n + 1);
	fill(short_call_callback_num.begin(), short_call_callback_num.end(), 0);
	vector<vector<int>>calls(n + 1);
	for (size_t i = 0; i <= n; i++)
	{
		calls[i].resize(n + 1);
		fill(calls[i].begin(), calls[i].end(), 0);
	}
	for (size_t i = 0; i < m; i++)
	{
		int caller = 0, receiver = 0, duration = 0;
		scanf("%d %d %d", &caller, &receiver, &duration);
		calls[caller][receiver] += duration;
	}
	for (size_t i = 0; i <= n; i++)
	{
		for (size_t j = 0; j <= n; j++)
		{
			if (calls[i][j] > 0 && calls[i][j] <= 5)
			{
				short_calls_num[i]++;
				if (calls[j][i] > 0)
				{
					short_call_callback_num[i]++;
				}
			}
		}
	}
	vector<int>suspects;
	map<int, int>father;
	for (size_t i = 0; i <= n; i++)
	{
		if (short_calls_num[i] > k &&  short_call_callback_num[i] * 5 <= short_calls_num[i])
		{
			suspects.push_back(i);
			father[i] = i;
		}
	}
	for (size_t i = 0; i < suspects.size(); i++)
	{
		for (size_t j = i + 1; j < suspects.size(); j++)
		{
			if (calls[suspects[i]][suspects[j]] > 0 && calls[suspects[j]][suspects[i]] > 0)
			{
				union_gang(suspects[i], suspects[j], father);
			}
		}
	}
	if (suspects.size() > 0)
	{
		//∞¥∞Ô≈… ‰≥ˆœ”“…»À
		vector<bool>has_print;
		has_print.resize(n + 1);
		fill(has_print.begin(), has_print.end(), false);
		for (size_t i = 0; i < suspects.size(); i++)
		{
			if (!has_print[suspects[i]])
			{
				has_print[suspects[i]] = true;
				set<int>print_suspects;
				print_suspects.insert(suspects[i]);
				for (size_t j = i + 1; j < suspects.size(); j++)
				{
					if (find_father(suspects[i], father) == find_father(suspects[j], father))
					{
						print_suspects.insert(suspects[j]);
						has_print[suspects[j]] = true;
					}
				}
				for (set<int>::iterator it = print_suspects.begin(); it != print_suspects.end(); it++)
				{
					if (it != print_suspects.begin())
					{
						printf(" ");
					}
					printf("%d", *it);
				}
				printf("\n");
			}
		}
	}
	else
	{
		printf("None");
	}
	return 0;
}