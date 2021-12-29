#include "resolve1102.h"
/*
	以层序（先加右子树）和中序（RTL）遍历原树
	注意此题未指定根节点
*/
int resolve1102::resolve()
{
	int n = 0, root = -1;
	scanf("%d", &n);
	bool *has_parent = new bool[n];
	fill(has_parent, has_parent + n, false);
	vector<int> *childs = new vector<int>[n];
	for (size_t i = 0; i < n; i++)
	{
		string l, r;
		l.resize(2);
		r.resize(2);
		scanf("%s %s", &l[0], &r[0]);
		if (l[0] == '-')
		{
			childs[i].push_back(-1);
		}
		else
		{
			childs[i].push_back(stoi(l));
			has_parent[stoi(l)] = true;
		}
		if (r[0] == '-')
		{
			childs[i].push_back(-1);
		}
		else
		{
			childs[i].push_back(stoi(r));
			has_parent[stoi(r)] = true;
		}
	}
	//找出根节点
	for (size_t i = 0; i < n; i++)
	{
		if (!has_parent[i])
		{
			root = i;
			break;
		}
	}
	//层序遍历开始
	queue<int>wait_visited;
	wait_visited.push(root);
	while (wait_visited.size() > 0)
	{
		int node = wait_visited.front();
		if (node != root)
		{
			printf(" ");
		}
		printf("%d", node);
		wait_visited.pop();
		for (int i = 1; i >= 0; --i)
		{
			if (childs[node][i] != -1)
			{
				wait_visited.push(childs[node][i]);
			}
		}
	}
	printf("\n");
	//中序（RTL）遍历开始
	int print_index = 0;
	in_order_invert(childs, root, print_index);
	return 0;
}

void resolve1102::in_order_invert(vector<int>* childs, int node, int & index)
{
	if (node != -1)
	{
		in_order_invert(childs, childs[node][1], index);
		if (index != 0)
		{
			printf(" ");
		}
		printf("%d", node);
		index++;
		in_order_invert(childs, childs[node][0], index);
	}
}