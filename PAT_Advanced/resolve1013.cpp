#include "resolve1013.h"
/**
	对于每个要检查的城市a以外的剩余城市节点进行并查集搜索
	最后有n个集合就意味着有n个连通子图，那么就需要修n-1条路

	艹，最后一个测试点超时了
	测试点	结果	耗时	内存
	0
	答案正确
	4 ms	352 KB
	1
	答案正确
	3 ms	384 KB
	2
	答案正确
	6 ms	2304 KB
	3
	答案正确
	8 ms	2304 KB
	4
	运行超时
	--	0 KB

	第一次优化
		将并查集的实现由数组替换为结构体并以此将一个集合的信息聚集在一个对象中，减少了合并两个集合时total_number_of_cities数量级的循环，还是超时
	第二次优化
		考虑并查集构建过程是基于边，故将邻接矩阵替换为边的数组，不存无效边,将点平方²数量级的循环改为边数量级的循环
		AC！！！ 说明第四个测试点是边稀疏的点密集型图，造成基于点数的邻接矩阵遍历超时。

*/
int resolve1013::resolve()
{
	int total_number_of_cities = 0, number_of_remaining_highways = 0, number_of_cities_check = 0;
	cin >> total_number_of_cities >> number_of_remaining_highways >> number_of_cities_check;
	//只存有效边
	edge* edges = new edge[number_of_remaining_highways];
	//输入图的信息
	for (int i = 0; i < number_of_remaining_highways; ++i)
	{
		int city_1 = 0, city_2 = 0;
		cin >> city_1 >> city_2;
		edges[i].from = city_1;
		edges[i].to = city_2;
	}
	//输入要检查的城市节点
	short* cities_check = new short[number_of_cities_check];
	for (int i = 0; i < number_of_cities_check; ++i)
	{
		cin >> cities_check[i];
	}
	//开始检查
	for (int i = 0; i < number_of_cities_check; ++i)
	{
		//独立集合数，除被检查城市
		int num_of_set = total_number_of_cities-1;
		//初始化并查集
		merge_set_node* merge_set = new merge_set_node[total_number_of_cities + 1];
		for (int j = 0; j < total_number_of_cities + 1; ++j)
		{
			merge_set[j].node_num = j;
			merge_set[j].set_info_node = nullptr;
		}
		//对除被检查城市外的剩余城市进行并查集搜索
		for (int n = 0; n < number_of_remaining_highways; ++n)
		{
			if (edges[n].from!= cities_check[i]&& edges[n].to != cities_check[i])
			{
				int j = edges[n].from, k = edges[n].to;
				if (merge_set[j].set_info_node == nullptr&&merge_set[k].set_info_node == nullptr)
				{
					//两个独立的点
					merge_set_info_node* info_node = new merge_set_info_node();
					info_node->set_num = j;
					merge_set[j].set_info_node = info_node;
					merge_set[k].set_info_node = info_node;
					--num_of_set;
				}
				else if (merge_set[k].set_info_node == nullptr)
				{
					//是个独立的点
					merge_set[k].set_info_node = merge_set[j].set_info_node;
					--num_of_set;
				}
				else if (merge_set[j].set_info_node == nullptr)
				{
					//是个独立的点
					merge_set[j].set_info_node = merge_set[k].set_info_node;
					--num_of_set;
				}
				else if (merge_set[k].set_info_node->set_num != merge_set[j].set_info_node->set_num)
				{
					//是另外一个集合，将k所属集合并入j
					merge_set[k].set_info_node->set_num = merge_set[j].set_info_node->set_num;
					--num_of_set;
				}
			}
		}
		//输出连通子图数（集合数）-1
		cout << (num_of_set-1);
		if (i!=(number_of_cities_check-1))
		{
			cout << endl;
		}
	}
	return 0;
}
