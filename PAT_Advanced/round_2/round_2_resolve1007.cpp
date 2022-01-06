#include "round_2_resolve1007.h"
using namespace round_2_resolve1007;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1007::resolve()
{
	//没想到什么好办法，唯一想到的规律是
	//最大子序列的头尾元素必是非负值 ！！注意此处不能认为是正值，测试点5为最大和为单个数0的情况，下方max的初始值同此理需设为-1
	int k = 0;
	scanf("%d", &k);
	int *nums = new int[k];
	vector<int>non_negative_index;
	for (size_t i = 0; i < k; i++)
	{
		scanf("%d", nums + i);
		if (nums[i] >= 0)
		{
			non_negative_index.push_back(i);
		}
	}
	if (non_negative_index.size() == 0)
	{
		//均为负数
		printf("0 %d %d", nums[0], nums[k - 1]);
	}
	else
	{
		//暴力遍历
		int a = 0, b = 0, max = -1;
		for (int i = 0; i < non_negative_index.size(); i++)
		{
			int current = 0, current_start = non_negative_index[i];
			for (int j = current_start; j <= non_negative_index[non_negative_index.size() - 1]; j++)
			{
				current += nums[j];
				if (current > max)
				{
					max = current;
					a = current_start;
					b = j;
				}
			}
		}
		printf("%d %d %d", max, nums[a], nums[b]);
	}
	return 0;
}