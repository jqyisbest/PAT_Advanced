#include "resolve1147.h"
/*
	在建树的过程中判断出是否堆
	然后再来个后序遍历就可以了
*/
int resolve1147::resolve()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (size_t i = 0; i < m; i++)
	{
		bool is_heap = true;
		int max_min = 0;
		node *root = nullptr;
		vector<int>all_keys;
		map <int, node *> all_nodes;
		for (int j = 1; j <= n; j++)
		{
			int val;
			scanf("%d", &val);
			all_keys.emplace_back(val);
			if (j != 1)
			{
				if (is_heap)
				{
					//因为 题目保证n个distinct int 所以无需考虑相等而无法判断增减的情况
					if (all_keys[j / 2 - 1] < val)
					{
						if (max_min == 0)
						{
							max_min = -1;
						}
						else
						{
							is_heap = max_min == -1;
						}
					}
					else
					{
						if (max_min == 0)
						{
							max_min = 1;
						}
						else
						{
							is_heap = max_min == 1;
						}
					}
				}
				node *n = new node();
				n->data = val;
				all_nodes[val] = n;
				if (j % 2 == 0)
				{
					all_nodes[all_keys[j / 2 - 1]]->left = n;
				}
				else
				{
					all_nodes[all_keys[j / 2 - 1]]->right = n;
				}
			}
			else
			{
				root = new node();
				root->data = val;
				all_nodes[val] = root;
			}
		}
		if (is_heap)
		{
			printf((max_min == 1 ? "Max Heap" : "Min Heap"));
		}
		else
		{
			printf("Not Heap");
		}
		printf("\n");
		is_heap = true;
		post_order(root, is_heap);
		printf("\n");
	}
	return 0;
}

void resolve1147::post_order(node * root, bool &is_first)
{
	if (root != nullptr)
	{
		post_order(root->left, is_first);
		post_order(root->right, is_first);
		if (!is_first)
		{
			printf(" ");
		}
		printf("%d", root->data);
		is_first = false;
	}
}