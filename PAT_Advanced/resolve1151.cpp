#include "resolve1151.h"
/*
	23333
	做1143的时候我没get到BST的LCA的规律，把它当作普通二叉树求解了
	结果这里真要我求普通二叉树的LCAhhhhh，还好保留了当时的代码
	只要改一下生成树的过程就好

	奇怪，这种做法也在200ms以内啊，1143给的时限200ms，为啥会说我超时？？？？？？
	而且普通树的生成过程还比BST要复杂一些，难道1143的树的形状很奇特导致了超时？还是说数据量比这题大很多？迷。
	0
	Accepted
	3 ms	384 KB
	1
	Accepted
	4 ms	356 KB
	2
	Accepted
	4 ms	384 KB
	3
	Accepted
	15 ms	2048 KB
	4
	Accepted
	166 ms	3884 KB
	5
	Accepted
	104 ms	3060 KB
*/
int resolve1151::resolve()
{
	map<int, node *> all_nodes;
	map<int, int> in_order_index;
	int m, n;
	scanf("%d %d", &m, &n);
	node *root = nullptr;
	vector<int> pre_order, in_order;
	for (size_t i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		in_order.emplace_back(val);
		in_order_index[val] = i;
	}
	for (size_t i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		pre_order.emplace_back(val);
	}
	get_root(nullptr, root, pre_order, 0, n - 1, in_order, 0, n - 1, in_order_index, all_nodes);
	for (size_t i = 0; i < m; i++)
	{
		int k_1, k_2;
		scanf("%d %d", &k_1, &k_2);
		map<int, node *>::iterator it_1 = all_nodes.find(k_1);
		map<int, node *>::iterator it_2 = all_nodes.find(k_2);
		if (it_1 != all_nodes.end() && it_2 != all_nodes.end())
		{
			node *n_1 = it_1->second;
			vector<node *>ancestor_1;
			while (n_1 != nullptr)
			{
				n_1->is_ancestor = true;
				ancestor_1.push_back(n_1);
				n_1 = n_1->parent;
			}
			node *n_2 = it_2->second;
			while (n_2 != nullptr)
			{
				if (n_2->is_ancestor)
				{
					//找到啦！
					if (n_2 == it_1->second)
					{
						//u是v的祖先
						printf("%d is an ancestor of %d.", it_1->first, it_2->first);
					}
					else if (n_2 == it_2->second)
					{
						//v是u的祖先
						printf("%d is an ancestor of %d.", it_2->first, it_1->first);
					}
					else
					{
						//n_2是u和v的祖先
						printf("LCA of %d and %d is %d.", it_1->first, it_2->first, n_2->data);
					}
					break;
				}
				n_2 = n_2->parent;
			}
			//恢复被修改过的祖先标记
			for (size_t j = 0; j < ancestor_1.size(); j++)
			{
				ancestor_1[j]->is_ancestor = false;
			}
		}
		else if (it_1 != all_nodes.end())
		{
			printf("ERROR: %d is not found.", k_2);
		}
		else if (it_2 != all_nodes.end())
		{
			printf("ERROR: %d is not found.", k_1);
		}
		else
		{
			printf("ERROR: %d and %d are not found.", k_1, k_2);
		}
		printf("\n");
	}
	return 0;
}

void resolve1151::get_root(node * parent, node *& root, vector<int>& pre_order, int pre_l, int pre_r, vector<int>& in_order, int in_l, int in_r, map<int, int>& in_order_index, map<int, node*>& all_nodes)
{
	//根据中序先序遍历序列生成树
	if (pre_l <= pre_r&&in_l <= in_r)
	{
		root = new node();
		root->data = pre_order[pre_l];
		root->parent = parent;
		all_nodes[root->data] = root;
		int left_num = in_order_index[root->data] - in_l;
		get_root(root, root->left, pre_order, pre_l + 1, pre_l + left_num, in_order, in_l, in_l + left_num - 1, in_order_index, all_nodes);
		get_root(root, root->right, pre_order, pre_l + left_num + 1, pre_r, in_order, in_l + left_num + 1, in_r, in_order_index, all_nodes);
	}
}