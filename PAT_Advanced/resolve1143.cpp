#include "resolve1143.h"
/*
	map���ٶ�λ����Ҫ���ҵ������ڵ�
	һ·�������Ƚڵ㲢���,��һ����ͬ��Ǿ�����

	�źߣ��������Ե㳬ʱ�ˡ���
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
	Ӧ���ǻָ���Ǻ�ʱ̫���ˣ�����map��ǰ�...

	���㣬���Ȼ���й��ɵġ�
	���������е�һ��keyֵ��uv֮�䣨�ɵ��ڣ��Ľڵ����lca
	���˰��������Ϊ�κ����һ�����ǣ�֤�����£���֤������
	�������������д��������ڵ�A,B����keyֵ����uv���Ҿ�����ȣ��������˵˭�ǲ���һ��ô2333����B��uv��lca
	��ʱ�����������
		1��A��B�ĸ��ڵ�
		   ����B��keyֵһ��С�ڣ�����ڣ�A��keyֵ������uvһ����С�ڣ�����ڣ�A��keyֵ�������Υ��
		2��A��B���ֵܽڵ�
		   ͬ�ϣ�B��keyֵ��һ��С�ڣ�����ڣ�A��keyֵ
	���ϣ�B������һ��������������uv��lca��ֻ��A��ǰ��������ǡ�
	�֣���u��A��B��C��D��v�����������У�ABCD��϶���һ����uv�Ĺ������ڵ�
	ֻ������uv��ĵ�һ����A�ˣ�������������BCD��Υ���˸��Ƴ��Ľ��ۣ�
	��Ҳ�����������š�����
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
					//�ҵ�����
					if (n_2 == it_1->second)
					{
						//u��v������
						printf("%d is an ancestor of %d.", it_1->first, it_2->first);
					}
					else if (n_2 == it_2->second)
					{
						//v��u������
						printf("%d is an ancestor of %d.", it_2->first, it_1->first);
					}
					else
					{
						//n_2��u��v������
						printf("LCA of %d and %d is %d.", it_1->first, it_2->first, n_2->data);
					}
					break;
				}
				n_2 = n_2->parent;
			}
			//�ָ����޸Ĺ������ȱ��
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