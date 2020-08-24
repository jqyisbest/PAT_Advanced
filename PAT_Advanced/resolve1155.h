#include"common.h"
namespace resolve1155
{
	int resolve();
	typedef struct node
	{
		int data;
		node *left, *right;
		node() {
			this->data = 0;
			this->left = nullptr;
			this->right = nullptr;
		}
	}node;
	void print_path(node *root, vector<int> &temp);
}