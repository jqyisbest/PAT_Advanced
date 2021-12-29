#include "resolve1066.h"
/*
	AVL操作模拟
	吐了，一道题写了十个小时，测试点4段错误？？？

	通过测试发现在某一个r操作时，nl为空，导致nl->right抛NPE
	发现虽然node_need_adjust是最靠近的那一个，但类型判定并没有跟上

	终于！！！
	其实需要调节的节点根本不是最后一个平衡因子不相等的节点，相反，是第一个不相等的节点
	当然，优化调整时的树形判定也是好的，这样确保逻辑不乱
	0	
	答案正确
	4 ms	384 KB
	1	
	答案正确
	4 ms	348 KB
	2	
	答案正确
	4 ms	384 KB
	3	
	答案正确
	5 ms	384 KB
	4	
	答案正确
	4 ms	384 KB
	5	
	答案正确
	4 ms	384 KB
	6	
	答案正确
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
	//将nrl作为n的右孩子
	if (nrl != nullptr)
	{
		//右孩子的左孩子不为空
		nrl->parent = n;
	}
	n->right = nrl;
	//将n作为nr的左孩子
	//修改n的父节点指向的孩子
	n->parent->left == n ? n->parent->left = nr : n->parent->right = nr;
	nr->parent = n->parent;
	n->parent = nr;
	nr->left = n;
	//修改高度
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
	//将nlr作为n的左孩子
	if (nlr != nullptr)
	{
		//左孩子的右孩子不为空
		nlr->parent = n;
	}
	n->left = nlr;
	//将n作为nl的右孩子
	//修改n的父节点指向的孩子
	n->parent->left == n ? n->parent->left = nl : n->parent->right = nl;
	nl->parent = n->parent;
	n->parent = nl;
	nl->right = n;
	//修改高度
	//修改高度
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
	自平衡插入节点，
*/
void resolve1066::insert(node *head, int key)
{
	if (head->left == nullptr)
	{
		head->left = new node(key, head);
	}
	else
	{
		//记录第一个是L还是R
		bool is_first_left = true, is_second_left = true, is_second_record = false;
		node *node_need_adjust = nullptr, *current_node = head->left;
		while (true)
		{
			if (current_node->key < key)
			{
				//即将进入右子树
				//判断是否为失衡节点
				if (node_need_adjust == nullptr && current_node->rh > current_node->lh)
				{
					//找到最后一个要调节的点
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
						//树高可能发生了变化！
						node *temp = current_node;
						while (temp != nullptr && temp->parent != head)
						{
							int &old_height = temp->parent->left == temp ? temp->parent->lh : temp->parent->rh;
							int new_height = get_height(temp);
							if (old_height == new_height)
							{
								//不会再影响上一层树了
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
				//即将进入左子树
				//判断是否为失衡节点
				if (node_need_adjust == nullptr && current_node->rh < current_node->lh)
				{
					//找到最后一个要调节的点
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
						//树高可能发生了变化！
						node *temp = current_node;
						while (temp != nullptr && temp->parent != head)
						{
							int &old_height = temp->parent->left == temp ? temp->parent->lh : temp->parent->rh;
							int new_height = get_height(temp);
							if (old_height == new_height)
							{
								//不会再影响上一层树了
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
			//失衡，需要调节
			//判定是那种调节类型
			if (key > node_need_adjust->key)
			{
				//第一层判定
				is_first_left = false;
				if (key > node_need_adjust->right->key)
				{
					//第二层判定
					is_second_left = false;
				}
			}
			else if (key > node_need_adjust->left->key)
			{
				//第二层判定
				is_second_left = false;
			}
			//开始调节
			if (is_first_left)
			{
				if (is_second_left)
				{
					//左左，右旋
					r(node_need_adjust);
				}
				else
				{
					//左右，左旋后右旋
					lr(node_need_adjust);
				}
			}
			else
			{
				if (!is_second_left)
				{
					//右右，左旋
					l(node_need_adjust);
				}
				else
				{
					//右左，右旋后左旋
					rl(node_need_adjust);
				}
			}
		}
	}
}