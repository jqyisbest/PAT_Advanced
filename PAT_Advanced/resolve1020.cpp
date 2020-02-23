#include "resolve1020.h"
/**
	�������зָ�ڵ㷶Χ����֪���������Ľڵ����
	��������ó������������Ľڵ�������ں�������������ָ�������������ĸ��ڵ�
	�ɰ���һ˼·�ó�������ɽ�ÿ�����ڵ�����Һ�������γɲ���
*/
int resolve1020::resolve()
{
	int node_num = 0;
	cin >> node_num;
	//���Ҹ�
	int* post_order = new int[node_num];
	//�����
	int* in_order = new int[node_num];
	//�����������
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
	//�������
	vector<int> node_list;
	node_list.push_back(post_order[node_num - 1]);
	//��¼ÿ���ڵ�ĺ��󡢺��ң��������ұ߽�����
	vector<int> border_index_list;
	border_index_list.push_back(0);
	border_index_list.push_back(node_num - 1);
	border_index_list.push_back(0);
	border_index_list.push_back(node_num - 1);
	int current_root_index = 0;
	while (current_root_index != node_num - 1)
	{
		//�ҳ���ǰ���ڵ�����Ӻ��Һ��Ӵ����������

		//��ǰ������ں�����������еı߽�����
		int post_order_left_index = border_index_list[current_root_index * 4], post_order_right_index = border_index_list[current_root_index * 4 + 1], in_order_left_index = border_index_list[current_root_index * 4 + 2], in_order_right_index = border_index_list[current_root_index * 4 + 3];
		//��ǰ���ڵ������������е�����
		int root_index_in_inorder = locate_node(in_order, node_num, node_list[current_root_index]);

		//��ǰ�������ڵ����
		int left_subtree_node_num = root_index_in_inorder - in_order_left_index;
		//��ǰ�������ڵ����
		int right_subtree_node_num = in_order_right_index - root_index_in_inorder;

		if (left_subtree_node_num>0)
		{
			//�������ں��������е���߽�
			int left_subtree_left_index_in_postorder = post_order_left_index;
			//�������ں��������е��ұ߽�
			int left_subtree_right_index_in_postorder = left_subtree_left_index_in_postorder + left_subtree_node_num - 1;
			//���������������е���߽�
			int left_subtree_left_index_in_inorder = in_order_left_index;
			//�����������������е��ұ߽�
			int left_subtree_right_index_in_inorder = left_subtree_left_index_in_inorder + left_subtree_node_num - 1;
			//���ں����������������ṹ��Ϊ���Ҹ�����post_order[left_subtree_right_index_in_postorder]Ϊ�������ĸ�,ͬ��������
			int left_subtree_root = post_order[left_subtree_right_index_in_postorder];
			node_list.push_back(left_subtree_root);
			border_index_list.push_back(left_subtree_left_index_in_postorder);
			border_index_list.push_back(left_subtree_right_index_in_postorder);
			border_index_list.push_back(left_subtree_left_index_in_inorder);
			border_index_list.push_back(left_subtree_right_index_in_inorder);
		}
		
		if (right_subtree_node_num>0)
		{
			//�������ں��������е��ұ߽�
			int right_subtree_right_index_in_postorder = post_order_right_index - 1;
			//�������ں��������е���߽�
			int right_subtree_left_index_in_postorder = right_subtree_right_index_in_postorder- right_subtree_node_num +1;
			//�����������������е���߽�
			int right_subtree_left_index_in_inorder = root_index_in_inorder + 1;
			//�����������������е��ұ߽�
			int right_subtree_right_index_in_inorder = right_subtree_left_index_in_inorder + right_subtree_node_num - 1;
			//���ں����������������ṹ��Ϊ���Ҹ�����post_order[right_subtree_right_index_in_postorder]Ϊ�������ĸ�,ͬ��������
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