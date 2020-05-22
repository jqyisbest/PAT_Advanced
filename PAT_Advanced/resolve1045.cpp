#include "resolve1045.h"
/*
	利用熵的概念做贪心
	此题可以理解为，用尽可能小的代价（删去某个颜色）让每个颜色的熵值为0（符合顺序）
	对stripe中的每个颜色计算其熵值
	每轮删去熵值最大（最为混乱/无序）的颜色并重新计算熵值直至每个颜色的熵值均为0
	妈的只过了一个测试点 这思路问题很大啊==；
	int resolve1045::resolve()
	{
	int num_of_colors = 0, length_of_order = 0, length_of_stripe = 0;
	scanf("%d\n%d", &num_of_colors, &length_of_order);
	//记录每个颜色的后面可以出现哪些颜色
	bool** order_map = new bool*[num_of_colors + 1];
	for (size_t i = 0; i < num_of_colors + 1; ++i)
	{
	//此处利用bool默认为true的特性，取反
	order_map[i] = new bool[num_of_colors + 1];
	}
	int int_temp = 0;
	vector<int> vec_order;
	for (size_t i = 0; i < length_of_order; ++i)
	{
	scanf("%d", &int_temp);
	vec_order.push_back(int_temp);
	for (size_t j = 0; j < vec_order.size(); ++j)
	{
	order_map[vec_order[j]][int_temp] = false;
	}
	}
	vector<int> stripe;
	scanf("%d", &length_of_stripe);
	stripe.reserve(length_of_stripe);
	for (size_t i = 0; i < length_of_stripe; ++i)
	{
	scanf("%d", &int_temp);
	if (!order_map[int_temp][int_temp])
	{
	//先把不在序列里的值过滤掉
	//stripe_node* node = new stripe_node();
	//node->color = int_temp;
	//node->entropy = 0;
	//stripe.push_back(node);
	stripe.push_back(int_temp);
	}
	}
	stripe_node_iterator max_entropy_it = find_max_entropy(stripe, order_map);
	while (max_entropy_it != stripe.end())
	{
	stripe.erase(max_entropy_it);
	max_entropy_it = find_max_entropy(stripe, order_map);
	}
	cout << stripe.size();
	return 0;
	}

	resolve1045::stripe_node_iterator resolve1045::find_max_entropy(vector<int>& stripe, bool ** order_map)
	{
	stripe_node_iterator result = stripe.end();
	int color = 0;
	int max_entropy = 0;
	int current_entropy = 0;
	for (stripe_node_iterator it = stripe.begin(); it != stripe.end(); ++it)
	{
	color = (*(it));
	current_entropy = 0;
	for (stripe_node_iterator it_temp = it + 1; it_temp != stripe.end() && order_map[color][(*(it_temp))]; ++it_temp)
	{
	//若不符合顺序则计算要删去多少个颜色才能让其符合顺序，即熵值
	++current_entropy;
	}
	if (current_entropy > max_entropy)
	{
	result = it;
	max_entropy = current_entropy;
	}
	}
	return result;
	}

	看来删去当前熵值最大的颜色，并不一定能得到全局最优的解
	去了解下最大不降子序列
	
	答案的思路：和之前的最短路径有点像 最短路径是考虑向后组成新路径
	考虑带子上的每一个颜色i 和i前面的每一个颜色j组成一根带子
	若颜色顺序 j i 符合order（从j可以抵达i）
	那么得到一条长度为length[j]+1的包含第j个颜色和第i个颜色的stripe（得到一条长度为length[j]+1的从1经过j至i的路径）
	和已有的包含第i个颜色的stripe的最长长度length[i]比较，判断是否为更长的一条带子 （和已有路径长度比较，判断是否为新的等长路径或更短路径）
	以此类推每一个颜色，从而求得最长的带子的长度是多少
	
	答案本身并没有求带子所包含的颜色，但应该可以参照最短路径那样去记录路径节点
	
	话说答案是怎么理解到order里的颜色不会重复的==

	
*/
int resolve1045::resolve()
{
	int num_of_colors = 0, length_of_order = 0, length_of_stripe = 0;
	scanf("%d\n%d", &num_of_colors, &length_of_order);
	//记录每个颜色的位序
	int* color_order = new int[num_of_colors + 1];
	fill(color_order, color_order + num_of_colors+1,0);
	int int_temp = 0;
	vector<int> vec_order;
	for (size_t i = 1; i <= length_of_order; ++i)
	{
		scanf("%d", &int_temp);
		color_order[int_temp]=i;
	}
	vector<stripe_node*> stripe;
	scanf("%d", &length_of_stripe);
	stripe.reserve(length_of_stripe);
	for (size_t i = 0; i < length_of_stripe; ++i)
	{
		scanf("%d", &int_temp);
		if (color_order[int_temp])
		{
			//先把不在序列里的值过滤掉
			stripe_node* node = node = new stripe_node();
			node->color = int_temp;
			node->length = 0;
			stripe.push_back(node);
		}
	}
	int max_length = 0;
	for (size_t i = 0; i < stripe.size(); ++i)
	{
		stripe[i]->length = 1;
		for (size_t j = 0; j < i; j++)
		{
			if (color_order[stripe[j]->color]<=color_order[stripe[i]->color])
			{
				//符合顺序，可以组成一根带子
				stripe[i]->length = max(stripe[i]->length, stripe[j]->length + 1);
			}
		}
		max_length=max(max_length, stripe[i]->length);
	}
	cout << max_length;
	return 0;
}