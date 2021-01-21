#include "resolve1138.h"
/*
	输出一个就停止，不用遍历了。
	50000个节点，不停怕是要超时==

	好吧，超时的关键不在递归，在于find函数，要用hash去存它

	经测试，提前结束递归亦有少许提升效果，但关键还是利用hash去除在中序序列中查找元素的过程
	对比柳神不使用hash的答案，使用hash于测试点4提升效果明显（524ms->45ms）
*/
int resolve1138::resolve()
{
	bool has_print = false;
	int n;
	scanf("%d", &n);
	vector<int> pre_order(n), in_order(n);
	map<int, int> in_order_index;
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &pre_order[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &in_order[i]);
		in_order_index[in_order[i]] = i;
	}
	post_order(0, n - 1, pre_order, 0, n - 1, in_order, in_order_index, has_print);
	return 0;
}

void resolve1138::post_order(int pre_l, int pre_r, vector<int>& pre_order, int in_l, int in_r, vector<int>& in_order, map<int, int>& in_order_index, bool & has_print)
{
	if (pre_l <= pre_r && !has_print)
	{
		int left_num = in_order_index[pre_order[pre_l]] - in_l;
		post_order(pre_l + 1, pre_l + left_num, pre_order, in_l, in_l + left_num - 1, in_order, in_order_index, has_print);
		post_order(pre_l + left_num + 1, pre_r, pre_order, in_l + left_num + 1, in_r, in_order, in_order_index, has_print);
		if (!has_print)
		{
			printf("%d", pre_order[pre_l]);
			has_print = true;
		}
	}
}