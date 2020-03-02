#include "common.h"
namespace resolve1030 {
	int resolve();
	typedef struct vertex_node{
		int city_1;
		int city_2;
		int distance;
		int cost;
	}highway_node;
	void copy_path(vector<int>& source, vector<int>& target, int target_num);
}