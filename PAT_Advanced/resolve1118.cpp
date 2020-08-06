#include "resolve1118.h"
/*
	合并函数如果做一个节点数判断和统计就会出现段错误？？为啥啊这是。。
	if (father[a_father] < father[b_father])
	{
	//a合并至b
	father[b_father] += father[a_father];
	father[a_father] = b_father;
	}
	else
	{
	//b合并至a
	father[a_father] += father[b_father];
	father[b_father] = a_father;
	}
	直接写
		father[a_father] = b_father;
	就ac了
*/
int resolve1118::resolve()
{
	int n = 0, q = 0, total_tree = 0;
	scanf("%d", &n);
	map<int, int> father;
	for (size_t i = 0; i < n; i++)
	{
		int k = 0, first = -1;
		scanf("%d", &k);
		for (size_t j = 0; j < k; j++)
		{
			int bird = 0;
			scanf("%d", &bird);
			if (father.count(bird) == 0)
			{
				if (j == 0)
				{
					first = bird;
					father[bird] = -1;
					total_tree++;
				}
				else
				{
					father[bird] = first;
					father[first]--;
				}
			}
			else if (first != -1)
			{
				union_node(first, bird, father, total_tree);
			}
			else
			{
				first = find_father(bird, father);
			}
		}
	}
	printf("%d %d\n", total_tree, father.size());
	scanf("%d", &q);
	for (size_t i = 0; i < q; i++)
	{
		int bird_1 = 0, bird_2 = 0;
		scanf("%d %d", &bird_1, &bird_2);
		if (find_father(bird_1, father) == find_father(bird_2, father))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

int resolve1118::find_father(int a, map<int, int>& father)
{
	if (father[a] < 0)
	{
		return a;
	}
	else
	{
		//路径压缩
		return father[a] = find_father(father[a], father);
	}
}

void resolve1118::union_node(int a, int b, map<int, int>& father, int & diff_num)
{
	int a_father = find_father(a, father);
	int b_father = find_father(b, father);
	if (a_father == b_father)
	{
		return;
	}
	father[a_father] = b_father;
	//if (father[a_father] < father[b_father])
	//{
	//	//a合并至b
	//	father[b_father] += father[a_father];
	//	father[a_father] = b_father;
	//}
	//else
	//{
	//	//b合并至a
	//	father[a_father] += father[b_father];
	//	father[b_father] = a_father;
	//}
	diff_num--;
}