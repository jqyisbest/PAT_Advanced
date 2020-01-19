#include "resolve1004.h"
#include "common.h"

namespace resolve1004 {
	/*typedef struct node_info {
		int id, k;
		node_info* childs;
	}node;*/
	const int INF = -1;
	int resolve()
	{
		int node_num = 0, non_leaf_node_num = 0;
		cin >> node_num >> non_leaf_node_num;
		if (node_num <= 0 || node_num >= 100) {
			return 0;
		}
		/*node* root = new node();
		root->id = 1;*/
		//ÿһ���ڵ�ĺ���ID���飬Ϊʹ��������ĿrootID(��01��)��Ӧ��tree��tree[1]��ʼ����ͬ
		int** tree = new int*[node_num + 1];
		//ÿһ���ڵ�ĺ��Ӹ�������
		int* child_num = new int[node_num + 1];
		fill(child_num, child_num + node_num + 1, 0);
		for (int i = 1; i < node_num + 1; ++i)
		{
			tree[i] = new int[node_num];
			fill(tree[i], tree[i] + node_num, INF);
		}
		for (int i = 0; i < non_leaf_node_num; ++i)
		{
			int parent_id = 0;
			cin >> parent_id;
			cin >> child_num[parent_id];
			for (int j = 0; j < child_num[parent_id]; ++j)
			{
				cin >> tree[parent_id][j];
			}
		}
		//���ݶ������
		int* result = new int[node_num];
		//���������ʼ
		//��¼��ǰ���
		int current_level = 0;
		int current_level_node_num = 0;
		int no_child_num = 0;
		int current_level_visited = 0;
		//��¼��һ������м����ڵ�
		int next_level_node_num = 0;
		//�ڵ����
		int* node_list = new int[node_num+1];
		fill(node_list, node_list + node_num, INF);
		int node_list_head_index = -1, node_list_tail_index = -1;
		//���ڵ����
		node_list_tail_index = (node_list_tail_index + 1) % node_num;
		node_list[node_list_tail_index] = 1;
		current_level_node_num = 1;
		while (node_list_tail_index != node_list_head_index)
		{
			//���зǿ�
			//ȡ���׽ڵ���ʣ������亢�ӽڵ����
			node_list_head_index = (node_list_head_index + 1) % node_num;
			int current_node = node_list[node_list_head_index];
			int current_node_child_num = 0;
			current_node_child_num = child_num[current_node];
			if (current_node_child_num == 0)
			{
				++no_child_num;
			}
			else
			{
				next_level_node_num += current_node_child_num;
				for (int i = 0; i < current_node_child_num; ++i)
				{
					node_list_tail_index = (node_list_tail_index + 1) % node_num;
					node_list[node_list_tail_index] = tree[current_node][i];
				}
			}
			++current_level_visited;
			//�ѷ����걾�� ��no_child_num��¼����
			if (current_level_node_num == current_level_visited)
			{
				result[current_level++] = no_child_num;
				current_level_node_num = next_level_node_num;
				current_level_visited = 0;
				no_child_num = 0;
				next_level_node_num = 0;
			}
		}
		//��¼���һ��
		//result[current_level] = no_child_num;
		for (int i = 0; i < current_level-1; ++i)
		{
			cout << result[i] << " ";
		}
		cout << result[current_level-1];
		return 0;
	}
}