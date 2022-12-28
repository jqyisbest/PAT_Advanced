#include "round_2_resolve1166.h"
using namespace round_2_resolve1166;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1166::resolve()
{
	int n = 0, m = 0, q = 0;
	cin >> n >> m;
	int **is_friend = new int*[n + 1];
	for (size_t i = 0; i < n + 1; i++)
	{
		is_friend[i] = new int[n + 1];
		fill(is_friend[i], is_friend[i] + n + 1, 0);
	}
	for (size_t i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		is_friend[a][b] = 1;
		is_friend[b][a] = 1;
	}
	cin >> q;
	for (size_t i = 1; i <= q; i++)
	{
		bool need_help = false, *has_join = new bool[n + 1];
		fill(has_join, has_join + n + 1, false);
		int seq = 0;
		cin >> seq;
		vector<int>current;
		for (size_t j = 0; j < seq; j++)
		{
			int head = 0;
			cin >> head;
			if (!need_help)
			{
				for (size_t k = 0; k < current.size(); k++)
				{
					if (!is_friend[current[k]][head])
					{
						printf("Area %d needs help.\n", i);
						need_help = true;
						break;
					}
				}
				current.push_back(head);
				has_join[head] = true;
			}
		}
		if (!need_help)
		{
			bool can_join = false;
			//判断是否可以加入更多人
			for (size_t j = 1; j <= n && !can_join; j++)
			{
				if (!has_join[j])
				{
					can_join = true;
					for (size_t k = 0; k < current.size() && can_join; k++)
					{
						if (!is_friend[current[k]][j])
						{
							can_join = false;
						}
					}
					if (can_join)
					{
						printf("Area %d may invite more people, such as %d.\n", i, j);
					}
				}
			}
			if (!can_join)
			{
				printf("Area %d is OK.\n", i);
			}
		}
	}
	return 0;
}