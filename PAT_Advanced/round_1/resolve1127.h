#include "common.h"
namespace resolve1127 {
	int resolve();
	int get_index(int num, vector<int> &v);
	void get_pre_order(int in_order_l, int in_order_r, int post_order_l, int post_order_r, int level, vector<int> &in_order, vector<int> &post_order, vector<vector<int>> &level_node);
}