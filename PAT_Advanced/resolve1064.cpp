#include "resolve1064.h"
/*
	作为一颗完全二叉搜索树，设其共有n+1个节点，层高h
	那么最后一层共有k个节点，k=n+2-2^(h-1)
	假设key为0-n
	其最后一层节点的key值为0 2 4 6 8...2(k-1)
	且（重点！！！）
	其根节点key为n/2+k/2-(k>2^(h-2)?k-2^(h-2):0)，推导过程如下：
	假设除去最后一层和根节点，按照完全二叉树的定义，两边子树剩余节点应相同，设为x
	则2*x+k+1=n+1 ==> 2*x+k=n ==> x=n/2-k/2
	最后一层本应有2^(h-1)个节点，左子树最后一层应有2^(h-2)个节点
	而此时，最后一层实际有k个节点
	故此时右子树共有 r 个节点，r=x+(k>2^(h-2)?k-2^(h-2):0)
	又根据完全二叉搜索树中序遍历即为有序序列的性质，即其右子树节点均比根节点大
	故可知根节点key值为n-r
	据此规律，即可递归求出每一层的节点key值

	回到题目来
	上述规律中key值0-n，最终输出顺序亦可为有序序列数组输出时的数组下标
	故此题解法：
	先根据输入数据个数n，得出最终的输出数组索引
	再将输入数据排序并按索引输出即可
*/
int resolve1064::resolve()
{
	int n = 0, h = 0, start=0, end=0;
	vector<int> value, result;
	scanf("%d", &n);
	h = ceil(log(n) / log(2));
	start = 0, end = n;
	while (h>0)
	{
		if (h == 1)
		{
			result.push_back(start);
			result.push_back(end);
		}
		else
		{
			int root = 0;
			//根
			root = get_BST_root(start, end, h);
			result.push_back(root);
			//左
			root = get_BST_root(start, root-1, h-1);
			result.push_back(root);
			//右
			root = get_BST_root(root+1, end, h-1);
			result.push_back(root);
			start+
		}
		h--;
	}
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", result[i]);
	}
	return 0;
}

int resolve1064::get_BST_root(int start, int end, int height)
{
	if (start < end)
	{
		//最后一层叶子节点数的一半
		int param = 2 << ((height - 3)>0 ? (height - 3) : 0);
		int n = end - start, k = n + 2 - param * 2, root = n - (n / 2 - k / 2 + (k > param ? k - param : 0));
		return root;
	}
}
