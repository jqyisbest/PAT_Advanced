#include <bits/stdc++.h>
using namespace std;
namespace round_2_resolve1167 {
	typedef struct node {
		int data;
		node* left, *right;
		node(int data) {
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
	}node;
	int get_min_index(vector<int>& in_order, int l, int r);
	node* get_node(vector<int>& in_order, int l, int r);
	int resolve();
}