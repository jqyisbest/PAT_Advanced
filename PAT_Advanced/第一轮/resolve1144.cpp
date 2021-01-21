#include "resolve1144.h"
/*
	用自带排序的set存储所有出现的正整数
	然后遍历set，值和序号（从1开始）不一致的就输出序号并返回

	注意整个序列从1开始且中间没有间断的情况，此时应直接输出min_miss
*/
int resolve1144::resolve()
{
	set<int> all_positive;
	int n, min_miss = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num > 0)
		{
			all_positive.insert(num);
		}
	}
	for (set<int>::iterator it = all_positive.begin(); it != all_positive.end(); it++, min_miss++)
	{
		if ((*it) != min_miss)
		{
			break;
		}
	}
	cout << min_miss;
	return 0;
}