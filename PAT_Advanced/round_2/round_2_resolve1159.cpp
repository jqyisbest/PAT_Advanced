#include "round_2_resolve1159.h"
using namespace round_2_resolve1159;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1159::find_index(int val, vector<int>& order)
{
	for (size_t i = 0; i < order.size(); i++)
	{
		if (val == order[i])
		{
			return i;
		}
	}
	return -1;
}
void round_2_resolve1159::get_tree(int * post_order, int post_l, int post_r, int * in_order, int in_l, int in_r, int current_level, bool & is_full, node *& root, map<int, node*>& get_node)
{
	if (post_l > post_r || in_l > in_r)
	{
		return;
	}
	root = new node(post_order[post_r], current_level);
	get_node[root->val] = root;
	int root_index_in_inorder = 0;
	for (root_index_in_inorder = 0; in_order[root_index_in_inorder] != root->val; root_index_in_inorder++);
	int left_child_num = root_index_in_inorder - in_l;
	get_tree(post_order, post_l, post_l + left_child_num - 1, in_order, in_l, root_index_in_inorder - 1, current_level + 1, is_full, root->left, get_node);
	if (root->left != nullptr)
	{
		root->left->parent = root;
	}
	get_tree(post_order, post_l + left_child_num, post_r - 1, in_order, root_index_in_inorder + 1, in_r, current_level + 1, is_full, root->right, get_node);
	if (root->right != nullptr)
	{
		root->right->parent = root;
	}
	if (is_full)
	{
		if (root->left != nullptr)
		{
			is_full = root->right != nullptr;
		}
		else if (root->right != nullptr)
		{
			is_full = root->left != nullptr;
		}
	}
}
int round_2_resolve1159::resolve()
{
	int n = 0;
	scanf("%d", &n);
	int *post_order = new int[n], *in_order = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &post_order[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &in_order[i]);
	}
	bool is_full = true;
	node *root = nullptr;
	map<int, node*> get_node;
	get_tree(post_order, 0, n - 1, in_order, 0, n - 1, 1, is_full, root, get_node);
	int m = 0;
	scanf("%d\n", &m);
	for (size_t i = 0; i < m; i++)
	{
		string statement;
		getline(cin, statement);
		int a = 0, b = 0;
		node *node_a = nullptr, *node_b = nullptr;
		if (statement.find("root") != string::npos)
		{
			sscanf(statement.c_str(), "%d is the root", &a);
			if (get_node[a]->parent == nullptr)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		else if (statement.find("siblings") != string::npos)
		{
			sscanf(statement.c_str(), "%d and %d are siblings", &a, &b);
			node_a = get_node[a];
			node_b = get_node[b];
			if (node_a->parent != nullptr&&node_b->parent != nullptr&&node_a->parent->val == node_b->parent->val)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		else if (statement.find("parent") != string::npos)
		{
			sscanf(statement.c_str(), "%d is the parent of %d", &a, &b);
			node_b = get_node[b];
			if (node_b->parent != nullptr&&node_b->parent->val == a)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		else if (statement.find("left") != string::npos)
		{
			sscanf(statement.c_str(), "%d is the left child of %d", &a, &b);
			node* left_child = get_node[b]->left;
			if (left_child != nullptr&& left_child->val == a)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		else if (statement.find("right") != string::npos)
		{
			sscanf(statement.c_str(), "%d is the right child of %d", &a, &b);
			node* right_child = get_node[b]->right;
			if (right_child != nullptr&& right_child->val == a)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		else if (statement.find("level") != string::npos)
		{
			sscanf(statement.c_str(), "%d and %d are on the same level", &a, &b);
			if (get_node[a]->level == get_node[b]->level)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		else if (statement.find("full") != string::npos)
		{
			if (is_full)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}