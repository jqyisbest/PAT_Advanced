#include "resolve1103.h"
/*
	穷举..

	好吧，是dfs的应用。。
	dfs用于全排列暴力搜索
	那么这题就变成，在k个框里填数字，要满足一些要求的数字


*/
int resolve1103::resolve()
{
	int n = 0, k = 0, p = 0;
	scanf("%d %d %d", &n, &k, &p);
	//先准备全部可用的候选
	vector<int> nums;
	nums.push_back(0);
	for (size_t i = 1; ; ++i)
	{
		int res = pow(i, p);
		if (res <= n)
		{
			nums.push_back(res);
		}
		else
		{
			break;
		}
	}
	//dfs
	int  max_sum = -1;
	vector<int> temp_results, results;
	temp_results.resize(k);
	dfs(nums.size() - 1, 0, 0, 0, max_sum, results, temp_results, nums, k, n);
	if (max_sum == -1) {
		printf("Impossible");
		return 0;
	}
	printf("%d = ", n);
	for (int i = 0; i < results.size(); i++) {
		if (i != 0) printf(" + ");
		printf("%d^%d", results[i], p);
	}
	return 0;
}

void resolve1103::dfs(int index, int temp_k, int temp_n, int temp_sum, int & max_sum, vector<int>& results, vector<int>& temp_results, vector<int>& nums, const int k, const int n)
{
	if (temp_k == k)
	{
		//k个数字都填满了,看是否满足条件的新的最优解
		if (temp_n == n && temp_sum > max_sum)
		{
			results = temp_results;
			max_sum = temp_sum;
		}
	}
	else
	{
		//尚未选出k个数字填入
		while (index >= 1)
		{
			//选一个累和不会超过n的尽可能大的数字填入当前这个空位
			//1、累和不超过n，硬性要求
			//2、倒序以满足尽可能大，以满足最大序列的最优解
			if (temp_n + nums[index] <= n)
			{
				temp_results[temp_k] = index;
				//再选下一个数字
				dfs(index, temp_k + 1, temp_n + nums[index], temp_sum + index, max_sum, results, temp_results, nums, k, n);
			}
			index--;
		}
	}
}