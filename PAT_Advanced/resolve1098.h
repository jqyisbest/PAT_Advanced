#include "common.h"
namespace resolve1098
{
	int resolve();
	int get_ordered_length(vector<int> &original_nums);
	void adjust_node(vector<int> &original_nums, int node_index, int end_index);
	void generate_heap(vector<int> &original_nums, int start_index, int end_index);
	void heap_sort(vector<int> &original_nums, int insert_index);
}
