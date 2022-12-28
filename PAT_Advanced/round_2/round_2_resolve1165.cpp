#include "round_2_resolve1165.h"
using namespace round_2_resolve1165;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1165::resolve()
{
	int first = 0, n = 0, k = 0;
	cin >> first >> n >> k;
	map<int, int>datas, nexts;
	vector<vector<int>>groups;
	for (size_t i = 0; i < n; i++)
	{
		int add = 0, data = 0, next = 0;
		cin >> add >> data >> next;
		datas[add] = data;
		nexts[add] = next;
	}
	int k_i = 0;
	vector<int>group;
	while (first != -1)
	{
		if (k_i % k == 0 && group.size() > 0)
		{
			vector<int>g(group);
			groups.push_back(g);
			group.clear();
		}
		group.push_back(first);
		first = nexts[first];
		k_i++;
	}
	if (group.size() > 0)
	{
		vector<int>g(group);
		groups.push_back(g);
	}
	reverse(groups.begin(), groups.end());
	for (size_t i = 0; i < groups.size(); i++)
	{
		vector<int>g = groups[i];
		for (size_t j = 0; j < g.size(); j++)
		{
			if (k_i == 1)
			{
				printf("%05d %d -1", g[j], datas[g[j]]);
			}
			else
			{
				int next_add = 0;
				if (j != g.size() - 1)
				{
					next_add = g[j + 1];
				}
				else
				{
					next_add = groups[i + 1][0];
				}
				printf("%05d %d %05d\n", g[j], datas[g[j]], next_add);
			}
			k_i--;
		}
	}
	return 0;
}