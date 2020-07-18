#include "resolve1094.h"

/*
	从根节点递归遍历自己的孩子节点并更新层数信息
	找出个数最大的一层即可
*/
int resolve1094::resolve()
{
	int n = 0, m = 0, level_num[101], max_num = -1, max_level = 0;
	fill(level_num, level_num + 101, 0);
	vector<int> childs[101];
	scanf("%d %d", &n, &m);
	for (size_t i = 0; i < m; ++i)
	{
		int id = 0, k = 0, child = 0;
		scanf("%d %d", &id, &k);
		for (size_t j = 0; j < k; ++j)
		{
			scanf("%d", &child);
			childs[id].push_back(child);
		}
	}
	update_level(1, childs, 1, level_num);
	for (size_t i = 0; i < 101; ++i)
	{
		if (level_num[i] > max_num)
		{
			max_num = level_num[i];
			max_level = i;
		}
	}
	printf("%d %d", max_num, max_level);
	return 0;
}

void resolve1094::update_level(int start_node, vector<int>* childs, int current_level, int * level_num)
{
	level_num[current_level]++;
	for (int i = 0; i < childs[start_node].size(); ++i)
	{
		update_level(childs[start_node][i], childs, current_level + 1, level_num);
	}
}
