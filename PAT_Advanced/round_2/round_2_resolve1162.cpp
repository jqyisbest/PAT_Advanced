#include "round_2_resolve1162.h"
using namespace round_2_resolve1162;
#include <bits/stdc++.h>
using namespace std;
string round_2_resolve1162::post_order(map<int, node*>& get_node, int root)
{
	if (root == -1)
	{
		return "";
	}
	node* t = get_node[root];
	int left = t->left, right = t->right;
	if (left == -1 && right != -1)
	{
		return "(" + t->data + post_order(get_node, right) + ")";

	}
	else
	{
		return"(" + post_order(get_node, left) + post_order(get_node, right) + t->data + ")";
	}
}
int round_2_resolve1162::resolve()
{
	int n = 0;
	scanf("%d", &n);
	bool *is_root = new bool[n];
	fill(is_root, is_root + n, true);
	map<int, node*> get_node;
	for (int i = 1; i <= n; i++)
	{
		string data;
		int left = 0, right = 0;
		cin >> data >> left >> right;
		node* p = new node(data, left, right);
		get_node[i] = p;
		if (left != -1)
		{
			is_root[left - 1] = false;
		}
		if (right != -1)
		{
			is_root[right - 1] = false;
		}
	}
	int root = -1;
	for (size_t i = 0; i < n; i++)
	{
		if (is_root[i])
		{
			root = i + 1;
			break;
		}
	}
	cout << post_order(get_node, root);
	return 0;
}