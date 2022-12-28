#include <bits/stdc++.h>
using namespace std;
namespace round_2_resolve1162 {
	typedef struct node
	{
		string data;
		int left, right;
		node(string data, int left, int right) {
			this->data = data;
			this->left = left;
			this->right = right;
		}
	}node;
	string post_order(map<int, node*>& get_node, int root);
	int resolve();
}