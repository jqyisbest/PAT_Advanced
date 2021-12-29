#include "resolve1063.h"
/*
	数据范围为long
	用set记录每一个出现了的数
	用另一map记录每一个set和其它set有重复的数
	查询时进行set_interaction 取交集

	nice，OAC，注意在寻找每个set的重复数时都要在全局范围内寻找
	0
	答案正确
	4 ms	464 KB
	1
	答案正确
	4 ms	352 KB
	2
	答案正确
	4 ms	368 KB
	3
	答案正确
	15 ms	384 KB
	4
	答案正确
	115 ms	5888 KB

	嘻嘻嘻，时间效率比柳神的暴力比对要高一些，以空间换时间。
	0
	答案正确
	4 ms	424 KB
	1
	答案正确
	4 ms	424 KB
	2
	答案正确
	5 ms	512 KB
	3
	答案正确
	14 ms	492 KB
	4
	答案正确
	188 ms	2800 KB
*/
int resolve1063::resolve()
{
	//记录每一个set的数字
	vector<set<long>> sets;
	//记录每一个set的重复数
	map<int, set<long>> same;
	//记录每一个出现的数
	map<long, int> num;
	//set个数，每个set的元素数，查询数，查询集合1，查询集合2
	//50 10000 2000
	int n, m, k, q1, q2;
	long val;
	scanf("%d", &n);
	sets.resize(n + 1);
	for (size_t i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (size_t j = 0; j < m; j++)
		{
			scanf("%ld", &val);
			if (sets[i].insert(val).second)
			{
				if (num.count(val) == 0)
				{
					num[val] = 1;
				}
				else
				{
					++num[val];
				}
			}
		}
	}
	for (size_t i = 1; i <= n; i++)
	{
		set<long> num_set = sets[i];
		for (set<long>::iterator it = num_set.begin(); it != num_set.end(); it++)
		{
			if (num[*it] > 1)
			{
				//和别的集合有重复
				same[i].insert(*it);
			}
		}
	}
	//开始处理查询请求
	scanf("%d", &k);
	vector<long> inter_set;
	for (size_t i = 0; i < k; i++)
	{
		scanf("%d %d", &q1, &q2);
		set<long> same1 = same[q1];
		set<long> same2 = same[q2];
		inter_set.resize(same1.size() + same2.size());
		auto end = set_intersection(same1.begin(), same1.end(), same2.begin(), same2.end(), inter_set.begin());
		double nc = end - inter_set.begin(), nt = sets[q1].size() + sets[q2].size() - nc;
		printf("%.1f%%\n", nc * 100 / nt);
	}
	return 0;
}
