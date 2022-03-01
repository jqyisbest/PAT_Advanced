#include "round_2_resolve1161.h"
using namespace round_2_resolve1161;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1161::resolve()
{
	vector<node*>a, b;
	map<int, node*>get_node;
	int a_first = 0, b_first = 0, n = 0;
	scanf("%d %d %d", &a_first, &b_first, &n);
	for (size_t i = 0; i < n; i++)
	{
		int add = 0, data = 0, next = 0;
		scanf("%d %d %d", &add, &data, &next);
		node* p = new node(add, data, next);
		get_node[add] = p;
	}
	while (a_first != -1)
	{
		node* p = get_node[a_first];
		a.push_back(p);
		a_first = p->next;
	}
	while (b_first != -1)
	{
		node* p = get_node[b_first];
		b.push_back(p);
		b_first = p->next;
	}
	if (a.size() < b.size())
	{
		swap(a, b);
	}
	reverse(b.begin(), b.end());
	vector<node*> ans;
	int i = 0, j = 0;
	while (j < b.size())
	{
		ans.push_back(a[i++]);
		ans.push_back(a[i++]);
		ans.push_back(b[j++]);
	}
	while (i < a.size())
	{
		ans.push_back(a[i++]);
	}
	for (int i = 0; i < ans.size() - 1; i++)
	{
		printf("%05d %d %05d\n", ans[i]->add, ans[i]->data, ans[i + 1]->add);
	}
	printf("%05d %d -1\n", ans.back()->add, ans.back()->data);
	return 0;
}