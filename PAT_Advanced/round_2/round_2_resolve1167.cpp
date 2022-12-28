#include "round_2_resolve1167.h"
using namespace round_2_resolve1167;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1167::get_min_index(vector<int>& in_order, int l, int r)
{
	int min = 0, min_i = -1;
	for (size_t i = l; i <= r; i++)
	{
		if (min_i == -1 || min > in_order[i])
		{
			min = in_order[i];
			min_i = i;
		}
	}
	return min_i;
}
node * round_2_resolve1167::get_node(vector<int>& in_order, int l, int r)
{
	node* root = nullptr;
	if (l <= r)
	{
		int min_index = get_min_index(in_order, l, r);
		root = new node(in_order[min_index]);
		root->left = get_node(in_order, l, min_index - 1);
		root->right = get_node(in_order, min_index + 1, r);
	}
	return root;
}
int round_2_resolve1167::resolve()
{
	int n = 0;
	cin >> n;
	vector<int> in_order;
	in_order.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> in_order[i];
	}
	node *root = get_node(in_order, 0, n - 1);
	vector<int> level_order;
	list<node*> level_list;
	level_list.push_back(root);
	while (level_list.size() != 0)
	{
		node * p = level_list.front();
		level_order.push_back(p->data);
		if (p->left != nullptr)
		{
			level_list.push_back(p->left);
		}
		if (p->right != nullptr)
		{
			level_list.push_back(p->right);
		}
		level_list.pop_front();
	}
	for (size_t i = 0; i < n; i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << level_order[i];
	}
	return 0;
}