#include "common.h"
namespace resolve1021 {
	vector<vector<int>> nodes;
	int resolve();
	void dfs(int root, int* visited);
	void dfs(int root, int* visited, int height, int* max_height, vector<int>* deepest_nodes);
}