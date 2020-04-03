#include "common.h"
namespace resolve1052 {
	int resolve();
	typedef struct list_node {
		int key;
		int add;
		int next;
	}list_node;
	bool cmp_node(list_node* node_1, list_node* node_2);
}