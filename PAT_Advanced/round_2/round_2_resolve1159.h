#include <bits/stdc++.h>
using namespace std;
namespace round_2_resolve1159 {
	typedef struct tree_node
	{
		int val, level;
		tree_node *parent, *left, *right;
		tree_node(int val, int level)
		{
			this->val = val;
			this->level = level;
			this->parent = nullptr;
			this->left = nullptr;
			this->right = nullptr;
		}
	}node;
	int find_index(int val, vector<int>& order);
	void get_tree(int* post_order, int post_l, int post_r, int* in_order, int in_l, int in_r, int current_level, bool &is_full, node*& root, map<int, node*>& get_node);
	int resolve();
}