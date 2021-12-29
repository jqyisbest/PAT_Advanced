#include "resolve1143.h"
/*
	map快速定位至需要查找的两个节点
	一路访问祖先节点并标记,第一个共同标记就是了

	嗯哼，三个测试点超时了。。
	0
	Accepted
	3 ms	384 KB
	1
	Accepted
	3 ms	432 KB
	2
	Accepted
	4 ms	488 KB
	3
	Time Limit Exceeded
	--	0 KB
	4
	Time Limit Exceeded
	--	0 KB
	5
	Time Limit Exceeded
	--	0 KB
	应该是恢复标记耗时太多了，改用map标记吧...

	天秀，这居然是有规律的。
	先序序列中第一个key值在uv之间（可等于）的节点就是lca
	想了半天才明白为何后面的一定不是，证明如下（反证法）：
	假设先序序列中存在两个节点A,B，其key值均在uv间且均不相等（相等了你说谁是不都一样么2333），B是uv的lca
	此时有两种情况：
		1、A是B的父节点
		   由于B的key值一定小于（或大于）A的key值，所以uv一定都小于（或大于）A的key值，与假设违背
		2、A是B的兄弟节点
		   同上，B的key值亦一定小于（或大于）A的key值
	综上，B（后面一个数）不可能是uv的lca，只有A（前面的数）是。
	又，在u，A，B，C，D，v的先序序列中，ABCD里肯定有一个是uv的公共父节点
	只能是在uv间的第一个数A了（其它的三个数BCD都违背了刚推出的结论）
	这也是这道题的窍门。。。
	typedef struct node {
	bool is_ancestor;
	int data;
	node *left, *right, *parent;
	node() {
	this->is_ancestor = false;
	this->data = 0;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	}
	}node;
	int resolve1143::resolve()
{
	map<int, node *>all_nodes;
	int m, n;
	scanf("%d %d", &m, &n);
	node *root = nullptr;
	for (size_t i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		insert(root, nullptr, val, all_nodes);
	}
	for (size_t i = 0; i < m; i++)
	{
		int k_1, k_2;
		scanf("%d %d", &k_1, &k_2);
		map<int, node *>::iterator it_1 = all_nodes.find(k_1);
		map<int, node *>::iterator it_2 = all_nodes.find(k_2);
		if (it_1 != all_nodes.end() && it_2 != all_nodes.end())
		{
			node *n_1 = it_1->second;
			vector<node *>ancestor_1;
			while (n_1 != nullptr)
			{
				n_1->is_ancestor = true;
				ancestor_1.push_back(n_1);
				n_1 = n_1->parent;
			}
			node *n_2 = it_2->second;
			while (n_2 != nullptr)
			{
				if (n_2->is_ancestor)
				{
					//找到啦！
					if (n_2 == it_1->second)
					{
						//u是v的祖先
						printf("%d is an ancestor of %d.", it_1->first, it_2->first);
					}
					else if (n_2 == it_2->second)
					{
						//v是u的祖先
						printf("%d is an ancestor of %d.", it_2->first, it_1->first);
					}
					else
					{
						//n_2是u和v的祖先
						printf("LCA of %d and %d is %d.", it_1->first, it_2->first, n_2->data);
					}
					break;
				}
				n_2 = n_2->parent;
			}
			//恢复被修改过的祖先标记
			for (size_t j = 0; j < ancestor_1.size(); j++)
			{
				ancestor_1[j]->is_ancestor = false;
			}
		}
		else if (it_1 != all_nodes.end())
		{
			printf("ERROR: %d is not found.", k_2);
		}
		else if (it_2 != all_nodes.end())
		{
			printf("ERROR: %d is not found.", k_1);
		}
		else
		{
			printf("ERROR: %d and %d are not found.", k_1, k_2);
		}
		printf("\n");
	}
	return 0;
}

void resolve1143::insert(node *& root, node * parent, int value, map<int, node*>& all_nodes)
{
	if (root == nullptr)
	{
		root = new node();
		root->data = value;
		all_nodes[value] = root;
		if (nullptr != parent)
		{
			root->parent = parent;
		}
	}
	else
	{
		if (value < root->data)
		{
			insert(root->left, root, value, all_nodes);
		}
		else
		{
			insert(root->right, root, value, all_nodes);
		}
	}
}
*/
int resolve1143::resolve()
{
	map<int, bool> mp;
	int m, n, u, v, a;
	scanf("%d %d", &m, &n);
	vector<int> pre(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
		mp[pre[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		for (int j = 0; j < n; j++) {
			a = pre[j];
			if ((a >= u && a <= v) || (a >= v && a <= u)) break;
		}
		if (mp[u] == false && mp[v] == false)
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (mp[u] == false || mp[v] == false)
			printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
		else if (a == u || a == v)
			printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
}