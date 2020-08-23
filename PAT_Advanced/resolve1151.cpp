#include "resolve1151.h"
/*
	23333
	��1143��ʱ����ûget��BST��LCA�Ĺ��ɣ�����������ͨ�����������
	���������Ҫ������ͨ��������LCAhhhhh�����ñ����˵�ʱ�Ĵ���
	ֻҪ��һ���������Ĺ��̾ͺ�

	��֣���������Ҳ��200ms���ڰ���1143����ʱ��200ms��Ϊɶ��˵�ҳ�ʱ������������
	������ͨ�������ɹ��̻���BSTҪ����һЩ���ѵ�1143��������״�����ص����˳�ʱ������˵�������������ܶࣿ�ԡ�
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
					//�ҵ�����
					if (n_2 == it_1->second)
					{
						//u��v������
						printf("%d is an ancestor of %d.", it_1->first, it_2->first);
					}
					else if (n_2 == it_2->second)
					{
						//v��u������
						printf("%d is an ancestor of %d.", it_2->first, it_1->first);
					}
					else
					{
						//n_2��u��v������
						printf("LCA of %d and %d is %d.", it_1->first, it_2->first, n_2->data);
					}
					break;
				}
				n_2 = n_2->parent;
			}
			//�ָ����޸Ĺ������ȱ��
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
	//�������������������������
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