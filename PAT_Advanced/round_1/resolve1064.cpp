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

	哎，答案和我思路一样，区别在于我是从end反推根节点，答案是从start加上左子树的个数，答案的更为稳定
	而且我不应该去考虑什么单枝问题，start==end时多算一次也无妨
	继续加油！
*/
int resolve1064::resolve()
{
	bool print_first = true;
	int n = 0;
	root_node *root = nullptr;
	vector<int> value;
	list<root_node*> root_list;
	scanf("%d", &n);
	value.resize(n);
	for (size_t i = 0; i < n; ++i)
	{
		scanf("%d", &value[i]);
	}
	sort(value.begin(), value.end());
	root = get_BST_root(0, n - 1);
	root_list.push_back(root);
	while (root_list.size() > 0)
	{
		root = root_list.front();
		if (!print_first)
		{
			printf(" ");
		}
		printf("%d", value[root->id]);
		print_first = false;
		if (root->start <= root->id - 1)
		{
			root_list.push_back(get_BST_root(root->start, root->id - 1));
		}
		if (root->id + 1 <= root->end)
		{
			root_list.push_back(get_BST_root(root->id + 1, root->end));
		}
		root_list.pop_front();
	}
	return 0;
}

resolve1064::root_node* resolve1064::get_BST_root(int start, int end)
{
	//height为除去最后一层的高度
	int n = end - start + 1, height = log(n + 1) / log(2), k = n + 1 - pow(2, height), root = start + (pow(2, height - 1) - 1) + min((int)pow(2, height - 1), k);
	root_node* node = new root_node();
	node->id = root;
	node->start = start;
	node->end = end;
	return node;
}
