#include "resolve1113.h"
/*
	这么简单25分吗0.0
	排序大的一堆小的一堆不就好了。。。
	个数差值要么0要么1，如果是1，大堆多一个就好了
*/
int resolve1113::resolve()
{
	int n = 0, n_half = 0, n_diff = 0;;
	scanf("%d", &n);
	n_half = n / 2;
	n_diff = n % 2;
	long long sum_1 = 0, sum_2 = 0;
	vector<long long>nums(n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%lld", &nums[i]);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n_half; i++)
	{
		sum_1 += nums[i];
	}
	for (int i = n_half; i < n; i++)
	{
		sum_2 += nums[i];
	}
	printf("%d %lld", n_diff, sum_2 - sum_1);
	return 0;
}