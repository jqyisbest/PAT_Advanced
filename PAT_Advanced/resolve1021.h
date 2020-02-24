#include "common.h"
namespace resolve1021 {
	int resolve();
	void dfs(int root, int* visited, vector<vector<int>> nodes);
	void dfs(int root, int* visited, vector<vector<int>> nodes, int height, int* max_height, vector<int>* deepest_nodes);
}