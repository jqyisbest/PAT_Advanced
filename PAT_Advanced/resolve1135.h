#include "common.h"
namespace resolve1135 {
	int resolve();
	typedef struct node {
		bool is_red;
		int data;
		node *left, *right;
		node() {
			data = 0;
			is_red = false;
			left = nullptr;
			right = nullptr;
		}
	}node;
	void insert(node *&root, int val);
	bool judge(node *parent, node *root, int black_num, int &another_num);
}