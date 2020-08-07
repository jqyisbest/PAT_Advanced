#include"common.h"
namespace resolve1123 {
	int resolve();
	typedef struct node {
		int data;
		node *parent;
		node *left;
		node *right;
		node() {
			data = 0;
			parent = nullptr;
			left = nullptr;
			right = nullptr;
		}
	}node;
	void l(node *root, node *&tree_root);
	void r(node *root, node *&tree_root);
	void lr(node *root, node *&tree_root);
	void rl(node *root, node *&tree_root);
	int cal_height(node *root, map<node *, int> &node_height);
	node *insert_node(node *old_root, node *&root, int data);
}