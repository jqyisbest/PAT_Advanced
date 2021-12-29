#include "resolve1115.h"
/*
	注意测试点5只有一个节点的情况，我的OAC啊啊啊啊啊/(ㄒoㄒ)/~~
	n只保证为正，可以为1！/(ㄒoㄒ)/~~
*/
int resolve1115::resolve()
{
	int n = 0, data = 0;
	node * root = new node();
	map<int, int> level_node_num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		if (i == 0)
		{
			root->data = data;
			level_node_num[1] = 1;
		}
		else
		{
			insert(root, data, 1, level_node_num);
		}
	}
	printf("%d + %d = %d", level_node_num[level_node_num.size()], level_node_num.size() > 1 ? level_node_num[level_node_num.size() - 1] : 0, level_node_num[level_node_num.size()] + (level_node_num.size() > 1 ? level_node_num[level_node_num.size() - 1] : 0));
	return 0;
}

void resolve1115::insert(node * root, int data, int level, map<int, int>& level_node_num)
{
	if (data > root->data)
	{
		if (root->right == nullptr)
		{
			root->right = new node();
			root->right->data = data;
			if (level_node_num.count(level + 1) != 0)
			{
				level_node_num[level + 1]++;
			}
			else
			{
				level_node_num[level + 1] = 1;
			}
		}
		else
		{
			insert(root->right, data, level + 1, level_node_num);
		}
	}
	else
	{
		if (root->left == nullptr)
		{
			root->left = new node();
			root->left->data = data;
			if (level_node_num.count(level + 1) != 0)
			{
				level_node_num[level + 1]++;
			}
			else
			{
				level_node_num[level + 1] = 1;
			}
		}
		else
		{
			insert(root->left, data, level + 1, level_node_num);
		}
	}
}