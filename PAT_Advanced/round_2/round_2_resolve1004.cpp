#include "round_2_resolve1004.h"
using namespace round_2_resolve1004;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1004::resolve()
{
	int n = 0, m = 0;
	scanf("%d", &n);
	if (n < 100 && n>0)
	{
		scanf("%d", &m);
		map<int, vector<int>> tree;
		for (size_t i = 0; i < m; i++)
		{
			int id = 0, child = 0, child_num = 0;
			scanf("%d %d", &id, &child_num);
			vector<int> childs;
			for (size_t j = 0; j < child_num; j++)
			{
				scanf("%d", &child);
				childs.push_back(child);
			}
			tree[id] = childs;
		}
		int last_level = 1, leaf_in_last_level = 0;
		map<int, int>levels;
		levels[1] = 1;
		queue<int> in_order_queue;
		in_order_queue.push(1);
		while (!in_order_queue.empty())
		{
			int id = in_order_queue.front();
			in_order_queue.pop();
			if (levels[id] > last_level)
			{
				//到下一层了，输出并重置上一层的统计信息
				if (last_level != 1)
				{
					printf(" ");
				}
				printf("%d", leaf_in_last_level);
				last_level = levels[id];
				leaf_in_last_level = 0;
			}
			if (tree[id].empty())
			{
				leaf_in_last_level++;
			}
			else
			{
				for (size_t i = 0; i < tree[id].size(); i++)
				{
					levels[tree[id][i]] = levels[id] + 1;
					in_order_queue.push(tree[id][i]);
				}
			}
		}
		//输出最后一层
		if (last_level != 1)
		{
			printf(" ");
		}
		printf("%d", leaf_in_last_level);
	}
	return 0;
}