#include "resolve1119.h"
/*
	先序后序转中序
	TLR,LRT
	不确定因素是一个节点来了不知道是左孩子还是右孩子
	总结：
		从遍历序列得出一棵树，关键在于如何找出根节点并分割左右子树
		不论是中序+前/后序定一颗树，还是前后序列推中序，虽然不能定一颗树

	？？？？？？？？？？？
	为什么结尾要输出一个换行？？？？？？？？？？？？？？？？
*/
int resolve1119::resolve()
{
	bool is_unique = true;
	int n = 0;
	scanf("%d", &n);
	vector<int> pre_order(n), post_order(n), in_order;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre_order[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post_order[i]);
	}
	get_inorder(is_unique, 0, n - 1, 0, n - 1, pre_order, post_order, in_order);
	printf("%s\n%d", is_unique ? "Yes" : "No", in_order[0]);
	for (int i = 1; i < n; i++)
	{
		printf(" %d", in_order[i]);
	}
	printf("\n");
	return 0;
}

void resolve1119::get_inorder(bool & is_unique, int pre_l, int pre_r, int post_l, int post_r, vector<int>& pre_order, vector<int>& post_order, vector<int>& in_order)
{
	if (pre_l == pre_r)
	{
		in_order.push_back(pre_order[pre_l]);
	}
	else if (pre_order[pre_l] == post_order[post_r])
	{
		//pre_order[pre_l]、post_order[post_r]为根节点
		//假设先序中下一个节点为左子树根节点，以此去后序中分割左右子树
		//若从后序分割出的右子树节点个数为0，则意味着此左子树根节点紧挨着根节点，无法判定此为左子树根节点还是右子树根节点

		int pre_left_root_index = pre_l + 1, post_left_root_index = post_r - 1;
		while (post_left_root_index >= post_l&&post_order[post_left_root_index] != pre_order[pre_left_root_index])
		{
			post_left_root_index--;
		}
		//遍历左子树
		get_inorder(is_unique, pre_left_root_index, pre_r - (post_r - post_left_root_index - 1), post_l, post_left_root_index, pre_order, post_order, in_order);
		//访问根节点
		in_order.push_back(post_order[post_r]);
		//遍历右子树
		if (post_r - post_left_root_index > 1)
		{
			get_inorder(is_unique, pre_r - (post_r - post_left_root_index - 1) + 1, pre_r, post_left_root_index + 1, post_r - 1, pre_order, post_order, in_order);
		}
		else
		{
			is_unique = false;
		}
	}
}