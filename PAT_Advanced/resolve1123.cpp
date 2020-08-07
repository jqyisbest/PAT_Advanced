#include "resolve1123.h"
/*
	�Ȳ��룬�ٱ���
	�����������ж��Ƿ���ȫ������

	û�뵽Ч�ʻ�����~ ������д��̫�����ˣ�ǿ���Ƽ�ѧϰ�����д��
	Case	Result	Run Time	Memory
	0
	Accepted
	3 ms	424 KB
	1
	Accepted
	4 ms	380 KB
	2
	Accepted
	4 ms	508 KB
	3
	Accepted
	4 ms	512 KB
	4
	Accepted
	4 ms	508 KB
	5
	Accepted
	4 ms	484 KB
	6
	Accepted
	4 ms	384 KB
	7
	Accepted
	4 ms	384 KB

	������������¼���ֵ��ѧϰ��
	1��AVL���������������˼�4�д��룬��Ҫʮ���У�˼·����������д���ݣ�һ��ֲ�
	2���ڲ������������߶ȼ���͵����������������ڲ�����ɺ󵥶�ά��
	3�����ж���rr����rl��lllrͬ��ʱ���õ�ǰ����ֵ���Һ��ӵ�ֵ���бȽϣ����������¼����Һ��ӵ����Һ��ӵĸ߶�
	4��һ���µ��ж��Ƿ���ȫ���������߼��������ȱ���ӽڵ�ĺ����ֳ������к��ӵĽڵ�������ȫ��������
*/
int resolve1123::resolve()
{
	int n = 0;
	scanf("%d", &n);
	node* tree_root = nullptr;
	map<node*, int> node_height;
	for (size_t i = 0; i < n; i++)
	{
		int data = 0;
		scanf("%d", &data);
		node* inserted_node = insert_node(nullptr, tree_root, data);
		cal_height(tree_root, node_height);
		while (inserted_node != nullptr)
		{
			int left_height = 0, right_height = 0;
			if (inserted_node->right != nullptr)
			{
				right_height = node_height[inserted_node->right];
			}
			if (inserted_node->left != nullptr)
			{
				left_height = node_height[inserted_node->left];
			}
			node *current_error_parent = nullptr;
			if (abs(right_height - left_height) > 1)
			{
				//�����⡣����Ҫ����
				current_error_parent = inserted_node->parent;
				if (right_height > left_height)
				{
					//����rr����rl
					int child_left_height = 0, child_right_height = 0;
					if (inserted_node->right->right != nullptr)
					{
						child_right_height = node_height[inserted_node->right->right];
					}
					if (inserted_node->right->left != nullptr)
					{
						child_left_height = node_height[inserted_node->right->left];
					}
					if (child_right_height > child_left_height)
					{
						//rr
						l(inserted_node, tree_root);
					}
					else
					{
						//rl
						rl(inserted_node, tree_root);
					}
				}
				else
				{
					//����ll����lr
					int child_left_height = 0, child_right_height = 0;
					if (inserted_node->left->right != nullptr)
					{
						child_right_height = node_height[inserted_node->left->right];
					}
					if (inserted_node->left->left != nullptr)
					{
						child_left_height = node_height[inserted_node->left->left];
					}
					if (child_right_height > child_left_height)
					{
						//lr
						lr(inserted_node, tree_root);
					}
					else
					{
						//ll
						r(inserted_node, tree_root);
					}
				}
				if (current_error_parent != nullptr)
				{
					cal_height(current_error_parent, node_height);
				}
				else
				{
					cal_height(tree_root, node_height);
				}
			}
			if (current_error_parent != nullptr)
			{
				inserted_node = current_error_parent;
			}
			else
			{
				inserted_node = inserted_node->parent;
			}
		}
	}
	//������������
	bool is_complete = true;
	int visited_num = 1;
	queue<node*> wait_visited;
	wait_visited.push(tree_root);
	while (wait_visited.size() > 0)
	{
		node* current_node = wait_visited.front();
		wait_visited.pop();
		if (current_node != tree_root)
		{
			printf(" ");
		}
		printf("%d", current_node->data);
		visited_num++;
		if (current_node->left != nullptr)
		{
			wait_visited.push(current_node->left);
		}
		else if (is_complete)
		{
			is_complete = visited_num > n;
		}
		visited_num++;
		if (current_node->right != nullptr)
		{
			wait_visited.push(current_node->right);
		}
		else if (is_complete)
		{
			is_complete = visited_num > n;
		}
	}
	printf(is_complete ? "\nYES" : "\nNO");
	return 0;
}

void resolve1123::l(node * root, node *&tree_root)
{
	//�Ƚ��Һ��ӵ����ӹ����ҵ��Һ��Ӵ�
	node *right_child = root->right;
	root->right = right_child->left;
	//�޸��Һ��ӵ����ӵĸ��׽ڵ���Ϣ
	if (root->right != nullptr)
	{
		root->right->parent = root;
	}
	//�Һ�����ȡ���ҵ�λ��
	if (root->parent != nullptr)
	{
		if (root->parent->right == root)
		{
			root->parent->right = right_child;
		}
		else
		{
			root->parent->left = right_child;
		}
	}
	else
	{
		tree_root = right_child;
	}
	//�޸��Һ��ӵĸ�����Ϣ
	right_child->parent = root->parent;
	//�ҳ�Ϊ�Һ��ӵ�����
	right_child->left = root;
	//�޸��ҵĸ��׽ڵ���Ϣ
	root->parent = right_child;
}

void resolve1123::r(node * root, node *&tree_root)
{
	//�Ƚ����ӵ��Һ��ӹ����ҵ����Ӵ�
	node *left_child = root->left;
	root->left = left_child->right;
	//�޸����ӵ��Һ��ӵĸ��׽ڵ���Ϣ
	if (root->left != nullptr)
	{
		root->left->parent = root;
	}
	//����ȡ���ҵ�λ��
	if (root->parent != nullptr)
	{
		if (root->parent->right == root)
		{
			root->parent->right = left_child;
		}
		else
		{
			root->parent->left = left_child;
		}
	}
	else
	{
		tree_root = left_child;
	}
	//�޸����ӵĸ��׽ڵ���Ϣ
	left_child->parent = root->parent;
	//�ҳ�Ϊ���ӵ��Һ���
	left_child->right = root;
	//�޸��ҵĸ��׽ڵ���Ϣ
	root->parent = left_child;
}

void resolve1123::lr(node * root, node *&tree_root)
{
	//�ȶ����ӽ�����������Ϊll��
	l(root->left, tree_root);
	//�ٽ�������
	r(root, tree_root);
}

void resolve1123::rl(node * root, node *&tree_root)
{
	//�ȶ��Һ��ӽ�����������Ϊrr��
	r(root->right, tree_root);
	//�ٽ�������
	l(root, tree_root);
}

int resolve1123::cal_height(node * root, map<node*, int> &node_height)
{
	if (root == nullptr)
	{
		return 0;
	}
	int left_height = 0, right_height = 0;
	//��������ڵ����߸߶�
	if (root->left != nullptr)
	{
		left_height = cal_height(root->left, node_height);
	}
	if (root->right != nullptr)
	{
		right_height = cal_height(root->right, node_height);
	}
	node_height[root] = max(left_height, right_height) + 1;
	return node_height[root];
}

resolve1123::node * resolve1123::insert_node(node * old_root, node *&root, int data)
{
	if (root == nullptr)
	{
		root = new node();
		root->data = data;
		root->parent = old_root;
		return root;
	}
	else
	{
		if (data > root->data)
		{
			return insert_node(root, root->right, data);
		}
		else
		{
			return insert_node(root, root->left, data);
		}
	}
}
