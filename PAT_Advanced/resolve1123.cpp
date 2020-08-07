#include "resolve1123.h"
/*
	先插入，再遍历
	遍历过程中判断是否完全二叉树

	没想到效率还不错~ 但代码写的太复杂了，强烈推荐学习柳神的写法
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

	柳神答案中有以下几点值得学习：
	1、AVL左旋右旋操作，人家4行代码，我要十多行，思路还复杂容易写错，草（一种植物）
	2、在插入操作中融入高度计算和调整操作，而不该在插入完成后单独维护
	3、在判断是rr还是rl（lllr同理）时，拿当前插入值与右孩子的值进行比较，而不该重新计算右孩子的左右孩子的高度
	4、一种新的判断是否完全二叉树的逻辑：如果在缺孩子节点的后面又出现了有孩子的节点则不是完全二叉树！
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
				//出问题。。需要调整
				current_error_parent = inserted_node->parent;
				if (right_height > left_height)
				{
					//看是rr还是rl
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
					//看是ll还是lr
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
	//层序遍历这颗树
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
	//先将右孩子的左孩子挂在我的右孩子处
	node *right_child = root->right;
	root->right = right_child->left;
	//修改右孩子的左孩子的父亲节点信息
	if (root->right != nullptr)
	{
		root->right->parent = root;
	}
	//右孩子来取代我的位置
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
	//修改右孩子的父亲信息
	right_child->parent = root->parent;
	//我成为右孩子的左孩子
	right_child->left = root;
	//修改我的父亲节点信息
	root->parent = right_child;
}

void resolve1123::r(node * root, node *&tree_root)
{
	//先将左孩子的右孩子挂在我的左孩子处
	node *left_child = root->left;
	root->left = left_child->right;
	//修改左孩子的右孩子的父亲节点信息
	if (root->left != nullptr)
	{
		root->left->parent = root;
	}
	//左孩子取代我的位置
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
	//修改左孩子的父亲节点信息
	left_child->parent = root->parent;
	//我成为左孩子的右孩子
	left_child->right = root;
	//修改我的父亲节点信息
	root->parent = left_child;
}

void resolve1123::lr(node * root, node *&tree_root)
{
	//先对左孩子进行左旋，变为ll型
	l(root->left, tree_root);
	//再进行右旋
	r(root, tree_root);
}

void resolve1123::rl(node * root, node *&tree_root)
{
	//先对右孩子进行右旋，变为rr型
	r(root->right, tree_root);
	//再进行左旋
	l(root, tree_root);
}

int resolve1123::cal_height(node * root, map<node*, int> &node_height)
{
	if (root == nullptr)
	{
		return 0;
	}
	int left_height = 0, right_height = 0;
	//计算这个节点的最高高度
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
