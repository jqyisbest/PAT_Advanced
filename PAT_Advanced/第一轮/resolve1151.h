#include "common.h"
namespace resolve1151
{
	int resolve();
	typedef struct node {
		bool is_ancestor;
		int data;
		node *left, *right, *parent;
		node() {
			this->is_ancestor = false;
			this->data = 0;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}
	}node;
	void get_root(node *parent, node *&root, vector<int> &pre_order, int pre_l, int pre_r, vector<int> &in_order, int in_l, int in_r, map<int, int> &in_order_index, map<int, node *> &all_nodes);
}