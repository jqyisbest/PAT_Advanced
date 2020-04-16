#include "common.h"
namespace resolve1064 {
	int resolve();
	typedef struct root_node {
		int id;
		int start;
		int end;
	}root_node;
	root_node* get_BST_root(int start, int end);
}