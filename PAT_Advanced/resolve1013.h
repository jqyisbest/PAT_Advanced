#include "common.h"
namespace resolve1013 {
	int resolve();
	typedef struct edge {
		int from;
		int to;
	}edge;
	typedef struct merge_set_info_node{
		//第一个连接至信息节点的节点编号
		int set_num;
	}merge_set_info;
	typedef struct merge_set_node {
		//节点编号
		int node_num;
		struct merge_set_info_node* set_info_node;
	}merge_set_node;
}