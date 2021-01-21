#include "resolve1129.h"
/*
	map 加 vector 随机存取加精准排序

	好吧，超时了。每次都全部排序太费时了。
	插入排序然后输出前k个就好了。

	自己写插入排序维护一个队列也不是不行，但答案里利用set.insert触发排序更简单。。
	注意拷贝答案时运算符重载函数需要写在结构体内
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
			//获取推荐
			for (set<goods>::iterator g = all_goods.begin(); g != all_goods.end() && print_num < k; g++, print_num++)
			{
				printf(" %d", g->index);
			}
			printf("\n");
		}
		//注意细节，本次访问不影响本次推荐
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
