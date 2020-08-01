#include "resolve1110.h"
/*
	操，没注意n<=20，index可能为两位数
*/
int resolve1110::resolve()
{
	int n = 0, root = 0;
	scanf("%d", &n);
	bool *is_child = new bool[n];
	fill(is_child, is_child + n, false);
	vector<vector<int>> childs;
	for (int i = 0; i < n; i++)
	{
		vector<int> child;
		string c1, c2;
		//index可能为两位数
		c1.resize(2);
		c2.resize(2);
		scanf("%s %s", &c1[0], &c2[0]);
		child.push_back(c1[0] == '-' ? -1 : stoi(c1));
		child.push_back(c2[0] == '-' ? -1 : stoi(c2));
		childs.push_back(child);
		if (c1[0] != '-')
		{
			is_child[stoi(c1)] = true;
		}
		if (c2[0] != '-')
		{
			is_child[stoi(c2)] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!is_child[i])
		{
			root = i;
			break;
		}
	}
	//层序遍历
	bool is_complete = true;
	int current_num = 1, node_index = 0;
	queue<int> wait_visited;
	wait_visited.push(root);
	while (wait_visited.size() > 0 && is_complete)
	{
		node_index = wait_visited.front();
		wait_visited.pop();
		for (int i = 0; i < 2; i++)
		{
			current_num++;
			if (childs[node_index][i] == -1)
			{
				is_complete = (current_num > n);
			}
			else
			{
				wait_visited.push(childs[node_index][i]);
			}
		}
	}
	if (is_complete)
	{
		printf("YES %d", node_index);
	}
	else
	{
		printf("NO %d", root);
	}
	return 0;
}