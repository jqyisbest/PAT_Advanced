#include "resolve1043.h"
/*
	输入先序 根左右 or 根右左
	输出后序 左右根 or 右左根
	怎么由前序遍历转换为后序遍历呢？
	我们根据前序遍历的特点，第一个点作为根节点，后面所有的点可以分为两部分，左子树和右子树。
	如果是一颗二叉搜索树，那么出去第一个根节点后剩下的所有点中间一定可以找到一个分界线使左边的所有的点比根节点小，右边的大
	如：4 1 3 2 6 5 7
	第一个4为根，下标 i j 分别从1、7开始向中间走，当剩余点被分为两部分时，i-j=1
	再对每段进行递归划分操作，最后递归划分完成才将根节点存入队列中，相当于根节点最后被访问
	而如果不是一颗二叉搜索树，那么i j一定会提前停下并返回，最终导致后序遍历队列元素个数少于先序遍历队列元素个数
	对于镜像，可在一轮转换结束且不是二叉搜索树的情况下，按相反的元素比较方式再进行一轮转换即可得知是否为镜像
*/
int resolve1043::resolve()
{
	int node_num = 0;
	scanf("%d", &node_num);
	vector<int> pre_order;
	vector<int> post_order;
	pre_order.resize(node_num);
	for (size_t i = 0; i < node_num; ++i)
	{
		scanf("%d", &pre_order[i]);
	}
	get_post(false, 0, node_num - 1, pre_order, post_order);
	if (post_order.size() != node_num)
	{
		//不是二叉搜索树，看看是不是镜像
		get_post(true, 0, node_num - 1, pre_order, post_order);
	}
	if (post_order.size() == node_num)
	{
		//是一颗树，后序输出
		cout << "YES" << endl;
		node_num--;
		for (size_t i = 0; i < node_num; ++i)
		{
			printf("%d ", post_order[i]);
		}
		printf("%d", post_order[node_num]);
	}
	else
	{
		cout << "NO";
	}
	return 0;
}

void resolve1043::get_post(bool is_mirror, int pre_start, int pre_end, const vector<int>& pre_order, vector<int>& post_order)
{
	int i = pre_start + 1, j = pre_end;
	if (!is_mirror)
	{
		while (i <= pre_end && pre_order[pre_start] > pre_order[i]) i++;
		while (j > pre_start && pre_order[pre_start] <= pre_order[j]) j--;
	}
	else
	{
		while (i <= pre_end &&pre_order[pre_start] <= pre_order[i]) i++;
		while (j > pre_start && pre_order[pre_start] > pre_order[j]) j--;
	}
	if (i - j == 1) {
		//这是得到后序 左 右 根
		get_post(is_mirror, pre_start + 1, j, pre_order, post_order);
		get_post(is_mirror, i, pre_end, pre_order, post_order);
		post_order.push_back(pre_order[pre_start]);
	}
}
