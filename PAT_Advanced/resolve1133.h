#include "common.h"
namespace resolve1133 {
	int resolve();
	typedef struct node {
		int add;
		int data;
		int next_add;
		node() {
			add = 0;
			data = 0;
			next_add = -1;
		}
	}node;
	node* get_node(int add, map<int, node*> &all_node);
}