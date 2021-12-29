#include "common.h"
namespace resolve1138 {
	int resolve();
	void post_order(int pre_l, int pre_r, vector<int> &pre_order, int in_l, int in_r, vector<int> &in_order, map<int, int> &in_order_index, bool &has_print);
}