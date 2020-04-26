#include "resolve1066.h"
/*
	AVL����ģ��
	���ˣ�һ����д��ʮ��Сʱ�����Ե�4�δ��󣿣���

	ͨ�����Է�����ĳһ��r����ʱ��nlΪ�գ�����nl->right��NPE
	������Ȼnode_need_adjust���������һ�����������ж���û�и���

	���ڣ�����
	��ʵ��Ҫ���ڵĽڵ�����������һ��ƽ�����Ӳ���ȵĽڵ㣬�෴���ǵ�һ������ȵĽڵ�
	��Ȼ���Ż�����ʱ�������ж�Ҳ�Ǻõģ�����ȷ���߼�����
	0	
	����ȷ
	4 ms	384 KB
	1	
	����ȷ
	4 ms	348 KB
	2	
	����ȷ
	4 ms	384 KB
	3	
	����ȷ
	5 ms	384 KB
	4	
	����ȷ
	4 ms	384 KB
	5	
	����ȷ
	4 ms	384 KB
	6	
	����ȷ
	4 ms	384 KB
*/
int resolve1066::resolve()
{
	node *head = new node();
	int n = 0, temp = 0;
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		insert(head, temp);
	}
	printf("%d", head->left->key);
	return 0;
}

int resolve1066::get_height(node *root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return max(get_height(root->left), get_height(root->right)) + 1;
}

void resolve1066::l(node *n)
{
	node *nr = n->right;
	node *nrl = nr->left;
	//��nrl��Ϊn���Һ���
	if (nrl != nullptr)
	{
		//�Һ��ӵ����Ӳ�Ϊ��
		nrl->parent = n;
	}
	n->right = nrl;
	//��n��Ϊnr������
	//�޸�n�ĸ��ڵ�ָ��ĺ���
	n->parent->left == n ? n->parent->left = nr : n->parent->right = nr;
	nr->parent = n->parent;
	n->parent = nr;
	nr->left = n;
	//�޸ĸ߶�
	n->lh = get_height(n->left);
	n->rh = get_height(n->right);
	nr->lh = get_height(nr->left);
	nr->rh = get_height(nr->right);
	nr->parent->lh = get_height(nr->parent->left);
	nr->parent->rh = get_height(nr->parent->right);
}
void resolve1066::r(node *n)
{
	node *nl = n->left;
	node *nlr = nl->right;
	//��nlr��Ϊn������
	if (nlr != nullptr)
	{
		//���ӵ��Һ��Ӳ�Ϊ��
		nlr->parent = n;
	}
	n->left = nlr;
	//��n��Ϊnl���Һ���
	//�޸�n�ĸ��ڵ�ָ��ĺ���
	n->parent->left == n ? n->parent->left = nl : n->parent->right = nl;
	nl->parent = n->parent;
	n->parent = nl;
	nl->right = n;
	//�޸ĸ߶�
	//�޸ĸ߶�
	n->lh = get_height(n->left);
	n->rh = get_height(n->right);
	nl->lh = get_height(nl->left);
	nl->rh = get_height(nl->right);
	nl->parent->lh = get_height(nl->parent->left);
	nl->parent->rh = get_height(nl->parent->right);
}
void resolve1066::lr(node *n)
{
	l(n->left);
	r(n);
}
void resolve1066::rl(node *n)
{
	r(n->right);
	l(n);
}

/*
	��ƽ�����ڵ㣬
*/
void resolve1066::insert(node *head, int key)
{
	if (head->left == nullptr)
	{
		head->left = new node(key, head);
	}
	else
	{
		//��¼��һ����L����R
		bool is_first_left = true, is_second_left = true, is_second_record = false;
		node *node_need_adjust = nullptr, *current_node = head->left;
		while (true)
		{
			if (current_node->key < key)
			{
				//��������������
				//�ж��Ƿ�Ϊʧ��ڵ�
				if (node_need_adjust == nullptr && current_node->rh > current_node->lh)
				{
					//�ҵ����һ��Ҫ���ڵĵ�
					node_need_adjust = current_node;
				}
				if (current_node->right != nullptr)
				{
					current_node = current_node->right;
				}
				else
				{
					current_node->right = new node(key, current_node);
					current_node->rh = 1;
					if (current_node->left == nullptr)
					{
						//���߿��ܷ����˱仯��
						node *temp = current_node;
						while (temp != nullptr && temp->parent != head)
						{
							int &old_height = temp->parent->left == temp ? temp->parent->lh : temp->parent->rh;
							int new_height = get_height(temp);
							if (old_height == new_height)
							{
								//������Ӱ����һ������
								break;
							}
							old_height = new_height;
							temp = temp->parent;
						}
					}
					break;
				}
			}
			else if (current_node->key > key)
			{
				//��������������
				//�ж��Ƿ�Ϊʧ��ڵ�
				if (node_need_adjust == nullptr && current_node->rh < current_node->lh)
				{
					//�ҵ����һ��Ҫ���ڵĵ�
					node_need_adjust = current_node;
				}
				if (current_node->left != nullptr)
				{
					current_node = current_node->left;
				}
				else
				{
					current_node->left = new node(key, current_node);
					current_node->lh = 1;
					if (current_node->right == nullptr)
					{
						//���߿��ܷ����˱仯��
						node *temp = current_node;
						while (temp != nullptr && temp->parent != head)
						{
							int &old_height = temp->parent->left == temp ? temp->parent->lh : temp->parent->rh;
							int new_height = get_height(temp);
							if (old_height == new_height)
							{
								//������Ӱ����һ������
								break;
							}
							old_height = new_height;
							temp = temp->parent;
						}
					}
					break;
				}
			}
		}

		if (node_need_adjust != nullptr)
		{
			//ʧ�⣬��Ҫ����
			//�ж������ֵ�������
			if (key > node_need_adjust->key)
			{
				//��һ���ж�
				is_first_left = false;
				if (key > node_need_adjust->right->key)
				{
					//�ڶ����ж�
					is_second_left = false;
				}
			}
			else if (key > node_need_adjust->left->key)
			{
				//�ڶ����ж�
				is_second_left = false;
			}
			//��ʼ����
			if (is_first_left)
			{
				if (is_second_left)
				{
					//��������
					r(node_need_adjust);
				}
				else
				{
					//���ң�����������
					lr(node_need_adjust);
				}
			}
			else
			{
				if (!is_second_left)
				{
					//���ң�����
					l(node_need_adjust);
				}
				else
				{
					//��������������
					rl(node_need_adjust);
				}
			}
		}
	}
}