#include "common.h"
namespace resolve1103 {
	int resolve();
	void dfs(int index, int temp_k, int temp_n, int temp_sum, int &max_sum, vector<int> &results, vector<int>& temp_results, vector<int>& nums, const int k, const int n);
}