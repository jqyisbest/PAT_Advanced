#include "resolve1149.h"
/*
	��map<int,vector�洢ì����Ʒ
	��vector<bool�洢��ǰ�б����Ƿ���ĳ����Ʒ
*/
int resolve1149::resolve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, vector<int>>incompatible_goods;
	for (size_t i = 0; i < n; i++)
	{
		int g_1, g_2;
		scanf("%d %d", &g_1, &g_2);
		map<int, vector<int>>::iterator it_1 = incompatible_goods.find(g_1);
		map<int, vector<int>>::iterator it_2 = incompatible_goods.find(g_2);
		if (it_1 == incompatible_goods.end())
		{
			vector<int> v;
			v.emplace_back(g_2);
			incompatible_goods[g_1] = v;
		}
		else
		{
			it_1->second.emplace_back(g_2);
		}
		if (it_2 == incompatible_goods.end())
		{
			vector<int> v;
			v.emplace_back(g_1);
			incompatible_goods[g_2] = v;
		}
		else
		{
			it_2->second.emplace_back(g_1);
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		bool flag = true;
		int k;
		scanf("%d", &k);
		vector<bool> goods_in_list(100000, false);
		for (size_t j = 0; j < k; j++)
		{
			int id;
			scanf("%d", &id);
			map<int, vector<int>>::iterator it = incompatible_goods.find(id);
			for (size_t jj = 0; flag&&it != incompatible_goods.end() && jj < it->second.size(); jj++)
			{
				flag = !goods_in_list[it->second[jj]];
			}
			goods_in_list[id] = true;
		}
		printf(flag ? "Yes\n" : "No\n");
	}
	return 0;
}