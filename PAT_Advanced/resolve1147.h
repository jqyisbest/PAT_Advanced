#include "common.h"
namespace resolve1147
{
	int resolve();
	typedef struct node {
		int data;
		node *left;
		node *right;
		node() {
			this->data = 0;
			this->left = nullptr;
			this->right = nullptr;
		}
	}node;
	void post_order(node *root, bool &is_first);
}