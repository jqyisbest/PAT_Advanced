#include "resolve1101.h"
/*
	记录左右两侧的最大值和最小值ML/MR
	如果ML<X<MR则X为候选
	ML可动态生成,MR使用链表进行维护

	好吧，超时了。。
	尝试用空间换时间了

	map默认会对key做升序排序！

	测试点2为0个候选值，此时需输出两个换行，否则格式错误==
*/
int resolve1101::resolve()
{
	int n = 0;
	scanf("%d", &n);
	map<int, bool> exist_in_right;
	vector<int> original_nums(n);
	vector<int> candidate;
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &original_nums[i]);
		exist_in_right[original_nums[i]] = true;
	}
	//开始判断每一个值是否为候选值
	int m_l = 0, current_val = 0;
	map<int, bool>::iterator m_r = exist_in_right.begin();
	for (size_t i = 0; i < n; i++)
	{
		current_val = original_nums[i];
		exist_in_right[current_val] = false;
		if (current_val == m_r->first)
		{
			get_next_min(exist_in_right, m_r);
		}
		if (m_l < current_val && (m_r == exist_in_right.end() || current_val < m_r->first))
		{
			//是候选值
			candidate.push_back(current_val);
		}
		//更新m_l
		if (m_l < current_val)
		{
			m_l = current_val;
		}
	}
	sort(candidate.begin(), candidate.end());
	printf("%d\n", candidate.size());
	for (size_t i = 0; i < candidate.size(); ++i)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", candidate[i]);
	}
	printf("\n");
	return 0;
}

void resolve1101::get_next_min(map<int, bool>& exist_in_right, map<int, bool>::iterator & min)
{
	for (; min != exist_in_right.end() && !min->second; ++min)
	{
	}
}
