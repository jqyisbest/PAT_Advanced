#include "resolve1129.h"
/*
	map �� vector �����ȡ�Ӿ�׼����

	�ðɣ���ʱ�ˡ�ÿ�ζ�ȫ������̫��ʱ�ˡ�
	��������Ȼ�����ǰk���ͺ��ˡ�

	�Լ�д��������ά��һ������Ҳ���ǲ��У�����������set.insert����������򵥡���
	ע�⿽����ʱ��������غ�����Ҫд�ڽṹ����
*/
int resolve1129::resolve()
{
	map<int, int>times;
	set <goods> all_goods;
	int n, k, g_index;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &g_index);
		if (i != 0)
		{
			printf("%d:", g_index);
			int print_num = 0;
			//��ȡ�Ƽ�
			for (set<goods>::iterator g = all_goods.begin(); g != all_goods.end() && print_num < k; g++, print_num++)
			{
				printf(" %d", g->index);
			}
			printf("\n");
		}
		//ע��ϸ�ڣ����η��ʲ�Ӱ�챾���Ƽ�
		goods g;
		g.index = g_index;
		map<int, int>::iterator time = times.find(g_index);
		if (time == times.end())
		{
			g.times = 1;
			all_goods.insert(g);
			times[g_index] = 1;
		}
		else
		{
			g.times = time->second;
			all_goods.erase(all_goods.find(g));
			g.times++;
			all_goods.insert(g);
			time->second++;
		}
	}
	return 0;
}
bool resolve1129::goods::operator < (const goods & g) const
{
	return this->times == g.times ? this->index<g.index : this->times>g.times;
}
