//#include<bits/stdc++.h>
//using namespace std;
//typedef struct node {
//	int val, level;
//	node *left, *right;
//	node() {
//		this->val = 0;
//		this->level = 0;
//		this->left = nullptr;
//		this->right = nullptr;
//	}
//}node;
//void get_tree(int level, node *&root, vector<int>& in_order, int in_l, int in_r, vector<int>& pre_order, int pre_l, int pre_r, map<int, int>&in_order_index) {
//	if (in_l <= in_r&&pre_l <= pre_r)
//	{
//		root = new node();
//		root->val = pre_order[pre_l];
//		root->level = level;
//		int left_num = in_order_index[pre_order[pre_l]] - in_l;
//		get_tree(level + 1, root->left, in_order, in_l, in_l + left_num - 1, pre_order, pre_l + 1, pre_l + left_num, in_order_index);
//		get_tree(level + 1, root->right, in_order, in_l + left_num + 1, in_r, pre_order, pre_l + left_num + 1, pre_r, in_order_index);
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	map<int, int>in_order_index;
//	vector<int> in_order(n, 0), pre_order(n, 0);
//	for (size_t i = 0; i < n; i++)
//	{
//		scanf("%d", &in_order[i]);
//		in_order_index[in_order[i]] = i;
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		scanf("%d", &pre_order[i]);
//	}
//	node *root = nullptr, *last_view = nullptr;
//	get_tree(1, root, in_order, 0, n - 1, pre_order, 0, n - 1, in_order_index);
//	queue<node *>wait_visited;
//	wait_visited.push(root);
//	while (wait_visited.size() > 0)
//	{
//		node *n = wait_visited.front();
//		if (n->left != nullptr)
//		{
//			wait_visited.push(n->left);
//
//		}
//		if (n->right != nullptr)
//		{
//			wait_visited.push(n->right);
//		}
//		if (n == root)
//		{
//			printf("%d", n->val);
//		}
//		else if (n->level != last_view->level)
//		{
//			printf(" %d", n->val);
//		}
//		last_view = n;
//		wait_visited.pop();
//	}
//	system("pause");
//	return 0;
//}