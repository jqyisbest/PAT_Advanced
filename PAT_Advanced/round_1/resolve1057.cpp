#include "resolve1057.h"
/*
	用vector模拟栈存储，用set做排序
	相当于一个数存两份，内存应该是够的==
	有可能超时。。

	/(ㄒoㄒ)/~~
	0
	答案正确
	4 ms	384 KB
	1
	运行超时
	--	0 KB
	2
	运行超时
	--	0 KB
	3
	运行超时
	--	0 KB
	4
	答案错误
	4 ms	512 KB

	利用key值为数字和迭代器的特性快速定位中值
	插入规律如下，
	插入值比当前中值大，且插入后size为奇数，中值迭代器应++
	插入值比当前中值小，且插入后size为偶数，中值迭代器应--
	简称 大奇右1，小偶左1
	删除规律如下，
	删除值刚好为中值：删除前size为奇数，中值迭代器应--；删除前size为偶数，中值迭代器应++
	删除值不等于中值时的规律恰好和插入规律相反：小奇右1，大偶左1

	果然效率高很多，但还是有两个错了
	段错误和最后一个答案错误应该是重复数的问题，set中无法存放重复数
	额外引入计数数组来统计每个数字出现的次数
	0
	答案正确
	3 ms	640 KB
	1
	答案正确
	33 ms	2300 KB
	2
	答案正确
	33 ms	2428 KB
	3
	段错误
	43 ms	2268 KB
	4
	答案错误
	3 ms	296 KB
	好像，set迭代器位移的办法解决不了重复数字的问题，即使能解决也很繁琐且容易出错,但还是挺有意思的想法，留着
	int resolve1057::resolve()
	{
	vector<int> keys;
	set<int> sorts;
	set<int>::iterator median;
	int num_of_ops = 0, key = 0, size = 0, num_count[100000]{ 0 };
	char ops[11];
	scanf("%d", &num_of_ops);
	for (int i = 0; i < num_of_ops; ++i)
	{
	scanf("%s", ops);
	if (strcmp(ops, "Push") == 0)
	{
	scanf("%d", &key);
	keys.push_back(key);
	sorts.insert(key);
	++num_count[key];
	++size;
	if (size == 1)
	{
	median = sorts.begin();
	}
	//调整中值迭代器
	if (*median < key&&size % 2 != 0)
	{
	++median;
	}
	else if (*median > key&&size % 2 == 0)
	{
	--median;
	}
	}
	else if (strcmp(ops, "Pop") == 0)
	{
	if (size > 0)
	{
	key = keys[keys.size() - 1];
	bool need_adjust_before_erase = key == *median;
	keys.pop_back();
	printf("%d\n", key);
	if (need_adjust_before_erase)
	{
	if (size % 2 == 0)
	{
	++median;
	}
	else
	{
	--median;
	}
	}
	sorts.erase(key);
	--size;
	if (!need_adjust_before_erase)
	{
	if (*median > key&&size % 2 != 0)
	{
	++median;
	}
	else if (*median < key&&size % 2 == 0)
	{
	--median;
	}
	}
	}
	else
	{
	printf("Invalid\n");
	}
	}
	else if (strcmp(ops, "PeekMedian") == 0)
	{
	if (size > 0)
	{
	printf("%d\n", *median);
	}
	else
	{
	printf("Invalid\n");
	}
	}
	}
	return 0;
	}
	转为用二分插入的办法实现一个有序vector吧

	终于。。二分法还是太生疏了/(ㄒoㄒ)/~~
	0
	答案正确
	4 ms	256 KB
	1
	答案正确
	42 ms	1148 KB
	2
	答案正确
	199 ms	1212 KB
	3
	答案正确
	122 ms	1428 KB
	4
	答案正确
	4 ms	296 KB

	注：二分法正确代码如下，可供参考
	k = (i + j) / 2;
	while (i <= j)
	{
	if (keys[k] < value)
	{
	i = k + 1;
	}
	else
	{
	j = k - 1;
	}
	k = (i + j) / 2;
	}
	k = i;
*/
int resolve1057::resolve()
{
	vector<int> keys;
	vector<int> keys_sort;
	int num_of_ops = 0, key = 0, size = 0;
	char ops[11];
	scanf("%d", &num_of_ops);
	for (int i = 0; i < num_of_ops; ++i)
	{
		scanf("%s", ops);
		if (strcmp(ops, "Push") == 0)
		{
			scanf("%d", &key);
			keys.push_back(key);
			insert_with_order(keys_sort, key);
			++size;
		}
		else if (strcmp(ops, "Pop") == 0)
		{
			if (size > 0)
			{
				key = keys[size - 1];
				keys.pop_back();
				printf("%d\n", key);
				erase_with_order(keys_sort, key);
				--size;
			}
			else
			{
				printf("Invalid\n");
			}
		}
		else if (strcmp(ops, "PeekMedian") == 0)
		{
			if (size > 0)
			{
				if (size % 2 == 0)
				{
					printf("%d\n", keys_sort[size / 2 - 1]);
				}
				else
				{
					printf("%d\n", keys_sort[(size + 1) / 2 - 1]);
				}
			}
			else
			{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}

vector<int>::iterator resolve1057::get_it_with_order(vector<int>& keys, int value)
{
	vector<int>::iterator it = keys.begin();
	if (it != keys.end())
	{
		int i = 0, j = keys.size() - 1, k = 0;
		if (keys[j] < value)
		{
			k = j + 1;
		}
		else if (keys[0] > value)
		{
			k = 0;
		}
		else
		{
			k = (i + j) / 2;
			while (i <= j)
			{
				if (keys[k] < value)
				{
					i = k + 1;
				}
				else
				{
					j = k - 1;
				}
				k = (i + j) / 2;
			}
			k = i;
		}
		it += k;
	}
	return it;
}

void resolve1057::insert_with_order(vector<int>& keys, int value)
{
	vector<int>::iterator it = get_it_with_order(keys, value);
	keys.insert(it, value);
}

void resolve1057::erase_with_order(vector<int>& keys, int value)
{
	vector<int>::iterator it = get_it_with_order(keys, value);
	keys.erase(it);
}
