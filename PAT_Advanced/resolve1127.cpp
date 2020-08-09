#include "resolve1127.h"
/*
	利用先序遍历递归从左至右访问每层的每个节点的特点，得到每一层的节点信息
	再按要求输出

	看了下柳神的思路，又是bfs又是dfs的，而且还不好理解。。
*/
int resolve1127::resolve()
{
	int n;
	scanf("%d", &n);
	vector<int> in_order(n);
	vector<int> post_order(n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &in_order[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &post_order[i]);
	}
	vector<vector<int>> level_node;
	get_pre_order(0, n - 1, 0, n - 1, 0, in_order, post_order, level_node);
	bool left_to_right = false, is_first = true;
	for (size_t i = 0; i < level_node.size(); i++)
	{
		vector<int> current_level = level_node[i];
		if (left_to_right)
		{
			for (size_t j = 0; j < current_level.size(); j++)
			{
				if (!is_first)
				{
					printf(" ");
				}
				printf("%d", current_level[j]);
				is_first = false;
			}
		}
		else
		{
			for (int j = current_level.size() - 1; j >= 0; --j)
			{
				if (!is_first)
				{
					printf(" ");
				}
				printf("%d", current_level[j]);
				is_first = false;
			}
		}
		left_to_right = !left_to_right;
	}
	return 0;
}

int resolve1127::get_index(int num, vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (num == v[i])
		{
			return i;
		}
	}
	return -1;
}

void resolve1127::get_pre_order(int in_order_l, int in_order_r, int post_order_l, int post_order_r, int level, vector<int>& in_order, vector<int>& post_order, vector<vector<int>>& level_node)
{
	if (in_order_l <= in_order_r)
	{
		if (level + 1 <= level_node.size())
		{
			level_node[level].push_back(post_order[post_order_r]);
		}
		else
		{
			vector<int> current_level;
			current_level.push_back(post_order[post_order_r]);
			level_node.push_back(current_level);
		}
		int root_index = get_index(post_order[post_order_r], in_order);
		int left_num = root_index - in_order_l;
		//左子树
		get_pre_order(in_order_l, root_index - 1, post_order_l, post_order_l + left_num - 1, level + 1, in_order, post_order, level_node);
		//右子树
		get_pre_order(root_index + 1, in_order_r, post_order_l + left_num, post_order_r - 1, level + 1, in_order, post_order, level_node);
	}
}