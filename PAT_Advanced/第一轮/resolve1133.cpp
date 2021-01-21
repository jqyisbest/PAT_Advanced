#include "resolve1133.h"
/*
	想到一个偷鸡的办法嘻嘻嘻
	就是遍历这个链表，把各类元素分类至一个vector里
*/
int resolve1133::resolve()
{
	bool first = true;
	int first_add, node_num, k;
	scanf("%d %d %d", &first_add, &node_num, &k);
	map<int, node *> all_node;
	for (size_t i = 0; i < node_num; i++)
	{
		node *n = new node();
		scanf("%d %d %d", &n->add, &n->data, &n->next_add);
		all_node[n->add] = n;
	}
	vector<node *> negative_node, k_node, bigger_node;
	//输出负数
	node *current_node = get_node(first_add, all_node);
	while (current_node != nullptr)
	{
		if (current_node->data < 0)
		{
			negative_node.emplace_back(current_node);
		}
		else if (current_node->data <= k)
		{
			k_node.emplace_back(current_node);
		}
		else
		{
			bigger_node.emplace_back(current_node);
		}
		current_node = get_node(current_node->next_add, all_node);
	}
	for (size_t i = 0; i < negative_node.size(); i++)
	{
		current_node = negative_node[i];
		if (!first)
		{
			printf("%05d\n", current_node->add);
		}
		printf("%05d %d ", current_node->add, current_node->data);
		first = false;
	}
	for (size_t i = 0; i < k_node.size(); i++)
	{
		current_node = k_node[i];
		if (!first)
		{
			printf("%05d\n", current_node->add);
		}
		printf("%05d %d ", current_node->add, current_node->data);
		first = false;
	}
	for (size_t i = 0; i < bigger_node.size(); i++)
	{
		current_node = bigger_node[i];
		if (!first)
		{
			printf("%05d\n", current_node->add);
		}
		printf("%05d %d ", current_node->add, current_node->data);
		first = false;
	}
	printf("-1\n");
	return 0;
}

resolve1133::node * resolve1133::get_node(int add, map<int, node*> &all_node)
{
	if (add < 0)
	{
		return nullptr;
	}
	else
	{
		return all_node[add];
	}
}
