#include "resolve1051.h"
/*
	栈：后进先出，且有容量限制
	对出栈序列的每一个元素 b 看前一个出栈元素 a ，分为两种情况：
	a>b：后进先出，正在输出存在栈中的数据，统计这是第几次 连续 出栈，看容量是否足够
	a<b: 先进先出，则要求当前输出元素b的前一个元素b-1已经被输出

	哦吼，规则并不完善
	0
	答案正确
	4 ms	384 KB
	1
	答案错误
	4 ms	368 KB
	2
	答案错误
	4 ms	384 KB
	3
	答案正确
	5 ms	384 KB
	4
	答案正确
	4 ms	384 KB
	5
	答案错误
	3 ms	384 KB

	嗷，忘记判断第一个输出是否合法了==    没啥影响。。。
	int resolve1051::resolve()
	{
	int m = 0, n = 0, k = 0, last_print = 0, current_print = 0, print_count = 0;
	scanf("%d %d %d", &m, &n, &k);
	//用has_print[0]为true来标记该序列有误
	bool *has_print = new bool[n + 1];
	for (int i = 0; i < k; ++i)
	{
	fill(has_print, has_print + n + 1, false);
	last_print = 0;
	print_count = 1;
	for (int j = 0; j < n; ++j)
	{
	scanf("%d", &current_print);
	has_print[current_print] = true;
	if (last_print == 0)
	{
	has_print[0] = current_print > m;
	}
	else if (!has_print[0])
	{
	if (last_print > current_print)
	{
	++print_count;
	if (print_count > m)
	{
	has_print[0] = true;
	}
	}
	else if (last_print < current_print)
	{
	if (!has_print[current_print - 1])
	{
	has_print[0] = true;
	}
	print_count = 1;
	}
	else
	{
	has_print[0] = true;
	}
	}
	last_print = current_print;
	}
	if (has_print[0])
	{
	printf("NO\n");
	}
	else
	{
	printf("YES\n");
	}
	}
	return 0;
	}

	尝试转为判断是否连续
	算了，转为模拟吧/(ㄒoㄒ)/~~
	试下这个规则：
	假设入栈顺序为1234…n，可知在栈中的元素从栈顶到栈底一定是按严格递减排列的,而且每个数i进栈之前,比i小的数一定已经进栈了。（我只想到了这一步。。。）
	所以：
	比i小的数要不然已经出栈,要不然在栈中，如果还在栈中则一定在i的下面，按严格递减排列,如此可见如果比i小的数还在栈中则一定在i之后输出,所以输出序列中在i后面的比i小的数一定按严格递减排列.否则出栈系列不合法。

	NB
	0
	答案正确
	3 ms	512 KB
	1
	答案正确
	3 ms	384 KB
	2
	答案正确
	3 ms	384 KB
	3
	答案正确
	4 ms	424 KB
	4
	答案正确
	4 ms	384 KB
	5
	答案正确
	5 ms	360 KB

	假设入栈过程为：1234567...k...n，k为当前入栈元素，且此刻栈中一定存在k,7,6,5,4,3,2,1这几个元素
	若不再插入k后元素，则出栈序列为k...7654321
	则实际出栈过程可理解为：在k...7654321的序列中，任意插入k+1...n的任意元素
	比如，我可以输出k就插一个k+1进来，也可以输出k...7后再插入k+1
	但！不论怎么插，现有出栈序列元素k...7654321的相对位置不会变！
	故在出栈序列中，后进先出、最大容量分别体现为：
	1、后进先出：若此刻k出栈，那么在k后出栈且比k先进站的元素的相对位置不会变！（此题中即为，k后出栈且比k小的数一定按严格递减排序，亦即在k后出栈的递增序列不会比k小）
	2、最大容量：出栈序列中按递减序列的输出的都是在输出栈中序列，故连续递减输出的个数不能大于最大容量
*/
int resolve1051::resolve()
{
	int m = 0, n = 0, k = 0, last_print = 0, current_print = 0, print_count = 0, max_print = 0;
	scanf("%d %d %d", &m, &n, &k);
	//用has_print[0]为true来标记该序列有误
	bool *has_print = new bool[n + 1];
	for (int i = 0; i < k; ++i)
	{
		fill(has_print, has_print + n + 1, false);
		last_print = 0;
		max_print = 0;
		print_count = 1;
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &current_print);
			has_print[current_print] = true;
			if (last_print == 0)
			{
				has_print[0] = current_print > m;
			}
			else if (!has_print[0])
			{
				if (last_print > current_print)
				{
					++print_count;
					if (print_count > m)
					{
						has_print[0] = true;
					}
				}
				else if (last_print < current_print)
				{
					if (current_print < max_print)
					{
						//
						has_print[0] = true;
					}
					print_count = 1;
				}
				else
				{
					has_print[0] = true;
				}
			}
			last_print = current_print;
			if (max_print < current_print)
			{
				max_print = current_print;
			}
		}
		if (has_print[0])
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
