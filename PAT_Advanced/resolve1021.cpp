#include "resolve1021.h"
/**
	多轮DFS
	第一轮求深度。若第一轮结束，尚有未访问节点，则进入DFS，求连通子图个数K

	0
	答案正确
	5 ms	424 KB
	1
	答案正确
	5 ms	424 KB
	2
	答案正确
	64 ms	644 KB
	3
	运行超时
	--	0 KB
	4
	答案正确
	5 ms	512 KB
	5
	答案正确
	5 ms	424 KB

	又超时了== 上一次超时也是在图这里。。
	主循环：num_of_nodes*num_of_nodes*num_of_nodes 内层还有递归

	主循环改为：num_of_nodes*num_of_nodes + 内层dfs ，依旧超时
	看来问题出在连通图时需要num_of_nodes次dfs。

	为啥别人的答案里说，就两次深度优先搜索呢

	!!!明白了。对于一个无环连通图而言，最长的路径长度是唯一确定的（不是说路径唯一）
	那么，就有有限条最长的路径，比如 1->2->***->5 、1->3->***>6
	且对于最长的路径上的所有起止点，是可以互换的，比如肯定有 6->***->1
	所以：1、只要找到一个最长路径的起点，那么就找到了其它的最长路径的起点（所以没必要从每一个点出发去试）
	且    2、从任意一点出发，得到的局部最长路径的终点，一定是全局最长路径的起止点！！！（可以用反证法证明）
	综上述两点、只需先从任意一点A dfs一次，再从第一次的终点出发，即可得到其它全局最长路径的起止点（我感觉主要是判断A是不是起止点）
	而且度不唯1的节点一定不是最长路径的起止点！！！
	先试试用度来过滤能不能过吧。

	哦吼，用度是否为1去过滤还是超时。。看来测试点3是那种高度不高但分支贼多的，测试点2倒是快了十秒

	捣腾半天最后还是没逃脱别人的思路╮(╯▽╰)╭
	!!!还是超时 ，主循环2*num_of_nodes都超时吗？？？
	woc 两次dfs都超时？说实话有点难受
	0
	答案正确
	3 ms	400 KB
	1
	答案正确
	3 ms	424 KB
	2
	答案正确
	62 ms	512 KB
	3
	运行超时
	--	0 KB
	4
	答案正确
	4 ms	384 KB
	5
	答案正确
	4 ms	432 KB
*/
int resolve1021::resolve()
{
	int num_of_nodes = 0;
	cin >> num_of_nodes;
	if (1 == num_of_nodes)
	{
		cout << "1";
	}
	else {
		vector<vector<int>> nodes;
		nodes.resize(num_of_nodes + 1);
		for (size_t i = 0; i < num_of_nodes - 1; ++i)
		{
			int vertex_1 = 0, vertex_2 = 0;
			cin >> vertex_1 >> vertex_2;
			nodes[vertex_1].push_back(vertex_2);
			nodes[vertex_2].push_back(vertex_1);
		}
		//最深的深度、连通分量数
		int max_height=0,k= 0;
		int* visited = new int[num_of_nodes + 1];
		fill(visited, visited + num_of_nodes + 1, 0);
		//所处高度最深的节点
		set<int> deepest_nodes;
		vector<int> current_deepest_nodes;
		for (int i = 1; i < num_of_nodes+1; i++)
		{
			if (visited[i] == 0)
			{
				if (0==k)
				{
					dfs(i, visited, nodes, 1, &max_height, &current_deepest_nodes);
				}
				else
				{
					dfs(i, visited, nodes);
				}
				++k;
			}
		}
		if (k == 1)
		{
			for (size_t j = 0; j < current_deepest_nodes.size(); ++j)
			{
				deepest_nodes.insert(current_deepest_nodes[j]);
			}
			fill(visited, visited + num_of_nodes + 1, 0);
			dfs(*(deepest_nodes.begin()), visited, nodes, 1, &max_height, &current_deepest_nodes);
			for (size_t j = 0; j < current_deepest_nodes.size(); ++j)
			{
				deepest_nodes.insert(current_deepest_nodes[j]);
			}
			int i = 0;
			for (set<int>::iterator it = deepest_nodes.begin(); it != deepest_nodes.end(); it++)
			{
				cout << *it;
				if (i != deepest_nodes.size() - 1)
				{
					cout << endl;
					++i;
				}
			}
		}
		else
		{
			cout << "Error: " << k << " components";
		}
	}
	return 0;
}

void resolve1021::dfs(int root, int * visited, vector<vector<int>> nodes)
{
	visited[root] = 1;
	for (int i = 0; i < nodes[root].size(); ++i)
	{
		if (visited[nodes[root][i]] == 0)
		{
			dfs(nodes[root][i], visited, nodes);
		}
	}
}

void resolve1021::dfs(int root, int* visited, vector<vector<int>> nodes, int height, int* max_height, vector<int>* deepest_nodes)
{
	visited[root] = 1;
	if (height > (*max_height))
	{
		*(max_height) = height;
		deepest_nodes->clear();
		deepest_nodes->push_back(root);
	}
	else if (height == (*max_height))
	{
		deepest_nodes->push_back(root);
	}
	for (int i = 0; i < nodes[root].size(); ++i)
	{
		if (visited[nodes[root][i]] == 0)
		{
			dfs(nodes[root][i], visited, nodes, height + 1, max_height, deepest_nodes);
		}
	}
}