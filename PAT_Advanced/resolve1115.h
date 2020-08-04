#include "common.h"
namespace resolve1115 {
	int resolve();
	typedef struct node {
		int data;
		node *left;
		node *right;
		node() {
			data = 0;
			left = nullptr;
			right = nullptr;
		}
	}node;
	void insert(node *root, int data, int level, map<int, int> &level_node_num);
}