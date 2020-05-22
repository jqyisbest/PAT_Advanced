#include "resolve1053.h"
/*
	类层序遍历树，统计记录每个叶子节点的权重和从根节点至其的路径
	OACo(*￣▽￣*)ブ
	0
	答案正确
	4 ms	356 KB
	1
	答案正确
	4 ms	384 KB
	2
	答案正确
	4 ms	424 KB
	3
	答案正确
	4 ms	384 KB
	4
	答案正确
	4 ms	384 KB
	5
	答案正确
	5 ms	424 KB
*/
namespace resolve1053 {

	int* original_weights = nullptr;

	int resolve1053::resolve()
	{
		int number_of_nodes = 0, number_of_nonleaf_nodes = 0;
		long long target_weight = 0;
		scanf("%d %d %lld", &number_of_nodes, &number_of_nonleaf_nodes, &target_weight);
		//保存节点权重和树结构
		vector<int> *tree = new vector<int>[number_of_nodes];
		vector<int> *paths = new vector<int>[number_of_nodes];
		original_weights = new int[number_of_nodes];
		long long *weights = new long long[number_of_nodes];
		for (int i = 0; i < number_of_nodes; ++i)
		{
			scanf("%lld", &weights[i]);
			original_weights[i] = weights[i];
			paths[i].push_back(i);
		}
		for (int i = 0; i < number_of_nonleaf_nodes; ++i)
		{
			int non_leaf_id = 0, num_of_child = 0, child_id = 0;
			scanf("%d %d", &non_leaf_id, &num_of_child);
			for (int j = 0; j < num_of_child; ++j)
			{
				scanf("%d", &child_id);
				tree[non_leaf_id].push_back(child_id);
			}
		}
		//层序遍历树结构算出从根节点至每一个节点的权重
		for (int node_id = 0; node_id < number_of_nodes; ++node_id)
		{
			//存在子节点，非叶节点
			if (tree[node_id].size() > 0)
			{
				//更新根节点至其子节点的路径和权重
				for (int i = 0; i < tree[node_id].size(); ++i)
				{
					int child_id = tree[node_id][i];
					weights[child_id] += weights[node_id];
					paths[child_id].insert(paths[child_id].end(), paths[node_id].begin(), paths[node_id].end());
				}
				//清除非叶节点的权重
				weights[node_id] = -1;
			}
		}
		//先排序，找到满足目标的就输出
		sort(paths, paths + number_of_nodes, cmp_path);
		for (size_t i = 0; i < number_of_nodes; ++i)
		{
			if (weights[paths[i][0]] == target_weight)
			{
				//符合要求，输出路径
				for (size_t j = paths[i].size() - 1; j > 0; --j)
				{
					printf("%d ", original_weights[paths[i][j]]);
				}
				printf("%d\n", original_weights[paths[i][0]]);
			}
		}
		return 0;
	}

	bool resolve1053::cmp_path(vector<int> &path_1, vector<int> &path_2)
	{
		int len_1 = path_1.size(), len_2 = path_2.size();
		for (size_t i = 0; i < len_1 && i < len_2; i++)
		{
			if (original_weights[path_1[len_1 - i - 1]] == original_weights[path_2[len_2 - i - 1]])
			{
				continue;
			}
			return original_weights[path_1[len_1 - i - 1]] > original_weights[path_2[len_2 - i - 1]];
		}
		return len_1 > len_2;
	}
}