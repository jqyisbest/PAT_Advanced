#include "common.h"
namespace resolve1118 {
	int resolve();
	int find_father(int a, map<int, int> &father);
	void union_node(int a, int b, map<int, int> &father, int &diff_num);
}