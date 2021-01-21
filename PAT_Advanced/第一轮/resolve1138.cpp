#include "resolve1138.h"
/*
	���һ����ֹͣ�����ñ����ˡ�
	50000���ڵ㣬��ͣ����Ҫ��ʱ==

	�ðɣ���ʱ�Ĺؼ����ڵݹ飬����find������Ҫ��hashȥ����

	�����ԣ���ǰ�����ݹ�������������Ч�������ؼ���������hashȥ�������������в���Ԫ�صĹ���
	�Ա�����ʹ��hash�Ĵ𰸣�ʹ��hash�ڲ��Ե�4����Ч�����ԣ�524ms->45ms��
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