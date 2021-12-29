#include "resolve1029.h"

/**
	对小数组的每一个输入元素，先用二分查找在大数组中查找比它小的（或者等于它）有几个，再加上当前的i+1，就得到这是合并序列中的第几个数
	大量输入一定要用scanf！！！cin容易超时，为什么说是容易而不是一定呢。因为这跟OJ的状态有关，但就算过了也是险过，远不如scanf稳定。
	0
	答案正确
	4 ms	424 KB
	1
	答案正确
	2 ms	356 KB
	2
	答案正确
	2 ms	424 KB
	3
	答案正确
	2 ms	436 KB
	4
	答案正确
	3 ms	412 KB

	 cin（相同代码两次提交）                     scanf（连续输入替换为scanf）                scanf（全部采用scanf输入）
	5
	答案正确           运行超时              答案正确              答案正确                  答案正确
	104 ms	2472 KB    --	0 KB             61 ms	2432 KB        61 ms	2432 KB          31 ms	2404 KB
	6
	答案正确           答案正确              答案正确              答案正确                  答案正确
	103 ms	1792 KB    134 ms  1900 KB       44 ms	1792 KB        44 ms	1960 KB          43 ms	1792 KB
	7
	答案正确           答案正确              答案正确              答案正确                  答案正确
	129 ms	1960 KB	   139 ms  1920 KB       44 ms	1960 KB        44 ms	1892 KB          40 ms	1892 KB
	8
	答案正确           运行超时              答案正确              答案正确                  答案正确
	158 ms	3604 KB    --	0 KB             84 ms	3428 KB        85 ms	3428 KB          70 ms	3456 KB
*/
int resolve1029::resolve()
{
	int n1 = 0, n2 = 0;
	long *nums_1, *nums_2;
	// cin >> n1;
	scanf("%d", &n1);
	nums_1 = new long[n1];
	for (size_t i = 0; i < n1; ++i)
	{
		// cin >> nums_1[i];
		scanf("%ld", &nums_1[i]);
	}
	// cin >> n2;
	scanf("%d", &n2);
	nums_2 = new long[n2];
	for (size_t i = 0; i < n2; ++i)
	{
		// cin >> nums_2[i];
		scanf("%ld", &nums_2[i]);
	}

	int less_n = n1, bigger_n = n2;
	long *less_nums = nums_1, *more_nums = nums_2;
	if (n1 > n2)
	{
		less_n = n2;
		bigger_n = n1;
		less_nums = nums_2;
		more_nums = nums_1;
	}
	//第多少个数是所求中位数
	int mid_count = (n1 + n2) / 2 + (n1 + n2) % 2;
	int l = 0, r = n1 - 1, val_index_in_base = 0, current_count = 0;
	long current_val = 0;
	for (size_t i = 0; i < less_n; ++i)
	{
		//当前输入的值、在基准数组中的位置、在虚拟合并数组中的个数（第几个，用于和mid_count比较）
		current_val = less_nums[i];
		val_index_in_base = current_count = 0;
		if (current_val < more_nums[0])
		{
			val_index_in_base = 0;
		}
		else if (current_val > more_nums[bigger_n - 1])
		{
			val_index_in_base = bigger_n;
		}
		else
		{
			val_index_in_base = locate_by_binary_search(more_nums, l, r, current_val);
		}
		current_count = val_index_in_base + i + 1;
		if (current_count >= mid_count)
		{
			//current_count==mid_count：找到啦！！current_count>mid_count刚好过了且中位数在基准数组的[val_index_in_base-current_count+mid_count]处
			cout << (current_count == mid_count ? current_val : more_nums[val_index_in_base - current_count + mid_count]);
			break;
		}
		l = val_index_in_base;
	}
	if (current_count < mid_count)
	{
		//第二个数组都遍历完了还没找到中位数，辣鸡
		//看看还差几个，从基准数组里补
		cout << more_nums[val_index_in_base + mid_count - current_count - 1];
	}
	return 0;
}

int resolve1029::locate_by_binary_search(long * nums, int l, int r, long val)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (val >= nums[mid]) {
			l = mid + 1;
		}
		else if (val < nums[mid])
		{
			r = mid - 1;
		}
	}
	return (l + r) / 2 + 1;
}
