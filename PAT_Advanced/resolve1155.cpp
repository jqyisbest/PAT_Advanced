#include "resolve1155.h"
/*
	����1147������ʱ�ж���ʲô��
	��������1147�ǽ�������к������
	�����������Ҷ�ӽڵ��ȫ��·��
*/
int resolve1155::resolve()
{
	//-2δ�ж� -1���Ƕ� 0С���� 1�󶥶�
	int n, heap_type = -2;
	scanf("%d", &n);
	node *root = nullptr;
	vector<int> all_val, temp;
	map <int, node *> all_nodes;
	for (size_t i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);
		all_val.push_back(val);
		if (i != 1)
		{
			if (val < all_val[i / 2 - 1])
			{
				if (heap_type == -2)
				{
					heap_type = 1;
				}
				else if (heap_type == 0)
				{
					heap_type = -1;
				}
			}
			else
			{
				if (heap_type == -2)
				{
					heap_type = 0;
				}
				else if (heap_type == 1)
				{
					heap_type = -1;
				}
			}
			node *n = new node();
			n->data = val;
			all_nodes[val] = n;
			if (i % 2 == 0)
			{
				all_nodes[all_val[i / 2 - 1]]->left = n;
			}
			else
			{
				all_nodes[all_val[i / 2 - 1]]->right = n;
			}
		}
		else
		{
			root = new node();
			root->data = val;
			all_nodes[val] = root;
		}
	}
	print_path(root, temp);
	printf(heap_type == -1 ? "Not Heap\n" : heap_type == 0 ? "Min Heap\n" : "Max Heap\n");
	return 0;
}

void resolve1155::print_path(node * root, vector<int>& temp)
{
	if (root->left == nullptr&&root->right == nullptr)
	{
		//Ҷ�ӽڵ��ˣ����
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (i != 0)
			{
				printf(" ");
			}
			printf("%d", temp[i]);
		}
		printf(" %d\n", root->data);
	}
	else
	{
		temp.push_back(root->data);
		if (root->right != nullptr)
		{
			print_path(root->right, temp);
		}
		if (root->left != nullptr)
		{
			print_path(root->left, temp);
		}
		temp.pop_back();
	}
}