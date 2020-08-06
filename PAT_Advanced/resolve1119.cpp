#include "resolve1119.h"
/*
	�������ת����
	TLR,LRT
	��ȷ��������һ���ڵ����˲�֪�������ӻ����Һ���
	�ܽ᣺
		�ӱ������еó�һ�������ؼ���������ҳ����ڵ㲢�ָ���������
		����������+ǰ/����һ����������ǰ��������������Ȼ���ܶ�һ����

	����������������������
	Ϊʲô��βҪ���һ�����У�������������������������������
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
		//pre_order[pre_l]��post_order[post_r]Ϊ���ڵ�
		//������������һ���ڵ�Ϊ���������ڵ㣬�Դ�ȥ�����зָ���������
		//���Ӻ���ָ�����������ڵ����Ϊ0������ζ�Ŵ����������ڵ�����Ÿ��ڵ㣬�޷��ж���Ϊ���������ڵ㻹�����������ڵ�

		int pre_left_root_index = pre_l + 1, post_left_root_index = post_r - 1;
		while (post_left_root_index >= post_l&&post_order[post_left_root_index] != pre_order[pre_left_root_index])
		{
			post_left_root_index--;
		}
		//����������
		get_inorder(is_unique, pre_left_root_index, pre_r - (post_r - post_left_root_index - 1), post_l, post_left_root_index, pre_order, post_order, in_order);
		//���ʸ��ڵ�
		in_order.push_back(post_order[post_r]);
		//����������
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