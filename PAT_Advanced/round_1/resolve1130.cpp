#include "resolve1130.h"
/*
	二叉树中序遍历

    测试点3、4RA，单枝树的情况没处理好，应该由根节点控制括号的添加，而不是叶节点
	例如：-1
	2
	- -1 2
	1 -1 -1
*/
int resolve1130::resolve()
{
	int n, root_index = 0;
	cin >> n;
	vector<int>parent(n + 1);
	vector<node *> all_node;
	for (size_t i = 1; i <= n; i++)
	{
		node *n = new node();
		cin >> n->data >> n->left_index >> n->right_index;
		all_node.push_back(n);
		if (n->left_index != -1)
		{
			parent[n->left_index] = i;
		}
		if (n->right_index != -1)
		{
			parent[n->right_index] = i;
		}
	}
	for (size_t i = 1; i <= n; i++)
	{
		if (parent[i] == 0)
		{
			root_index = i;
		}
		if (all_node[i - 1]->left_index != -1)
		{
			all_node[i - 1]->left = all_node[all_node[i - 1]->left_index - 1];
		}
		if (all_node[i - 1]->right_index != -1)
		{
			all_node[i - 1]->right = all_node[all_node[i - 1]->right_index - 1];
		}
	}
	node *root = all_node[root_index - 1];
	string result;
	get_sequence(root, 0, result);
	cout << result << endl;
	return 0;
}

void resolve1130::get_sequence(node * root, int left_or_right, string & result)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left != nullptr && root->right != nullptr)
	{
		if (left_or_right != 0)
		{
			result += "(";
		}
		get_sequence(root->left, -1, result);
		result += root->data;
		get_sequence(root->right, 1, result);
		if (left_or_right != 0)
		{
			result += ")";
		}
	}
	else if (root->left == nullptr && root->right == nullptr)
	{
		result += root->data;
	}
	else if (root->left == nullptr)
	{
		if (left_or_right != 0)
		{
			result += "(";
		}
		result += root->data;
		get_sequence(root->right, 1, result);
		if (left_or_right != 0)
		{
			result += ")";
		}
	}
	else if (root->right == nullptr)
	{
		if (left_or_right != 0)
		{
			result += "(";
		}
		get_sequence(root->left, -1, result);
		result += root->data;
		if (left_or_right != 0)
		{
			result += ")";
		}
	}
}