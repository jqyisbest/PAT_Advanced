#include"common.h"
namespace resolve1130 {
	int resolve();
	typedef struct node {
		int left_index, right_index;
		string data;
		node *left, *right;
		node() {
			this->left = nullptr;
			this->right = nullptr;
			this->left_index = 0;
			this->right_index = 0;
		}
	}node;
	void get_sequence(node *root, int left_or_right, string &result);
}