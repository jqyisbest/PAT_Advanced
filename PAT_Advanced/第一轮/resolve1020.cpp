#include "resolve1020.h"
/**
	在中序中分割节点范围，可知左右子树的节点个数
	根据中序得出的左右子树的节点个数，在后序中锁定中序分割出的左右子树的根节点
	可按这一思路得出先序，亦可将每个根节点的左右孩子入队形成层序
*/
int resolve1020::resolve()
{
	int node_num = 0;
	cin >> node_num;
	//左右根
	int* post_order = new int[node_num];
	//左根右
	int* in_order = new int[node_num];
	//输入后序中序
	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < node_num; ++j)
		{
			if (i == 0)
			{
				cin >> post_order[j];
			}
			else
			{
				cin >> in_order[j];
			}
		}
	}
	//层序队列
	vector<int> node_list;
	node_list.push_back(post_order[node_num - 1]);
	//记录每个节点的后左、后右，中左、中右边界索引
	vector<int> border_index_list;
	border_index_list.push_back(0);
	border_index_list.push_back(node_num - 1);
	border_index_list.push_back(0);
	border_index_list.push_back(node_num - 1);
	int current_root_index = 0;
	while (current_root_index != node_num - 1)
	{
		//找出当前根节点的左孩子和右孩子存入层序序列

		//当前这棵树在后序中序队列中的边界索引
		int post_order_left_index = border_index_list[current_root_index * 4], post_order_right_index = border_index_list[current_root_index * 4 + 1], in_order_left_index = border_index_list[current_root_index * 4 + 2], in_order_right_index = border_index_list[current_root_index * 4 + 3];
		//当前根节点在中序序列中的索引
		int root_index_in_inorder = locate_node(in_order, node_num, node_list[current_root_index]);

		//当前左子树节点个数
		int left_subtree_node_num = root_index_in_inorder - in_order_left_index;
		//当前右子树节点个数
		int right_subtree_node_num = in_order_right_index - root_index_in_inorder;

		if (left_subtree_node_num>0)
		{
			//左子树在后序序列中的左边界
			int left_subtree_left_index_in_postorder = post_order_left_index;
			//左子树在后序序列中的右边界
			int left_subtree_right_index_in_postorder = left_subtree_left_index_in_postorder + left_subtree_node_num - 1;
			//左子树在中序列中的左边界
			int left_subtree_left_index_in_inorder = in_order_left_index;
			//左子树在中序序列中的右边界
			int left_subtree_right_index_in_inorder = left_subtree_left_index_in_inorder + left_subtree_node_num - 1;
			//由于后序序列中左子树结构亦为左右根，故post_order[left_subtree_right_index_in_postorder]为左子树的根,同理右子树
			int left_subtree_root = post_order[left_subtree_right_index_in_postorder];
			node_list.push_back(left_subtree_root);
			border_index_list.push_back(left_subtree_left_index_in_postorder);
			border_index_list.push_back(left_subtree_right_index_in_postorder);
			border_index_list.push_back(left_subtree_left_index_in_inorder);
			border_index_list.push_back(left_subtree_right_index_in_inorder);
		}
		
		if (right_subtree_node_num>0)
		{
			//右子树在后序序列中的右边界
			int right_subtree_right_index_in_postorder = post_order_right_index - 1;
			//右子树在后序序列中的左边界
			int right_subtree_left_index_in_postorder = right_subtree_right_index_in_postorder- right_subtree_node_num +1;
			//右子树在中序序列中的左边界
			int right_subtree_left_index_in_inorder = root_index_in_inorder + 1;
			//右子树在中序序列中的右边界
			int right_subtree_right_index_in_inorder = right_subtree_left_index_in_inorder + right_subtree_node_num - 1;
			//由于后序序列中右子树结构亦为左右根，故post_order[right_subtree_right_index_in_postorder]为右子树的根,同理左子树
			int right_subtree_root = post_order[right_subtree_right_index_in_postorder];
			node_list.push_back(right_subtree_root);
			border_index_list.push_back(right_subtree_left_index_in_postorder);
			border_index_list.push_back(right_subtree_right_index_in_postorder);
			border_index_list.push_back(right_subtree_left_index_in_inorder);
			border_index_list.push_back(right_subtree_right_index_in_inorder);
		}

		++current_root_index;
	}
	for (size_t i = 0; i < node_num-1; ++i)
	{
		cout << node_list[i] << " ";
	}
	cout << node_list[node_num - 1];
	return 0;
}

int resolve1020::locate_node(int * node_array, int node_num, int val)
{
	for (int i = 0; i < node_num; ++i)
	{
		if (node_array[i] == val)
		{
			return i;
		}
	}
	return -1;
}