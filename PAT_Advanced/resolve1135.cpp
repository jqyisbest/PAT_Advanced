#include "resolve1135.h"
/*
	红黑树。。他来了
	这还只是红黑树的判定我就头皮发麻了==
	先建树,再遍历，判定是否符合要求

	卧槽，二叉查找树的先序遍历就是插入顺序，中序遍历就是从小到大

	虽然是OAC，但是根据先序生成树这块参考了柳神，还是再看看吧
*/
int resolve1135::resolve()
{
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int n, num_index = 1, black_num = -1;
		scanf("%d", &n);
		node *root = nullptr;
		for (int j = 0; j < n; j++)
		{
			int val;
			scanf("%d", &val);
			insert(root, val);
		}
		if (root->is_red)
		{
			printf("No\n");
			continue;
		}
		//dfs或者叫先序遍历进行判定
		printf(judge(nullptr, root, 0, black_num) ? "Yes\n" : "No\n");
	}
	return 0;
}

void resolve1135::insert(node *&root, int val)
{
	if (root == nullptr)
	{
		root = new node();
		root->data = abs(val);
		root->is_red = val < 0;
	}
	else
	{
		if (abs(val) <= root->data)
		{
			insert(root->left, val);
		}
		else
		{
			insert(root->right, val);
		}
	}
}

bool resolve1135::judge(node * parent, node * root, int black_num, int &another_num)
{
	if (root == nullptr)
	{
		if (another_num == -1)
		{
			another_num = black_num;
			return true;
		}
		else
		{
			return black_num == another_num;
		}
	}
	if (parent == nullptr || !parent->is_red || !root->is_red)
	{
		if (!root->is_red)
		{
			black_num++;
		}
		bool flag = judge(root, root->left, black_num, another_num);
		if (flag)
		{
			flag = judge(root, root->right, black_num, another_num);
		}
		return flag;
	}
	return false;
}