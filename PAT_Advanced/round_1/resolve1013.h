#include "common.h"
namespace resolve1013 {
	int resolve();
	typedef struct edge {
		int from;
		int to;
	}edge;
	typedef struct merge_set_info_node{
		//��һ����������Ϣ�ڵ�Ľڵ���
		int set_num;
	}merge_set_info;
	typedef struct merge_set_node {
		//�ڵ���
		int node_num;
		struct merge_set_info_node* set_info_node;
	}merge_set_node;
}