#include "resolve1043.h"
/*
	�������� ������ or ������
	������� ���Ҹ� or �����
	��ô��ǰ�����ת��Ϊ��������أ�
	���Ǹ���ǰ��������ص㣬��һ������Ϊ���ڵ㣬�������еĵ���Է�Ϊ�����֣�����������������
	�����һ�Ŷ�������������ô��ȥ��һ�����ڵ��ʣ�µ����е��м�һ�������ҵ�һ���ֽ���ʹ��ߵ����еĵ�ȸ��ڵ�С���ұߵĴ�
	�磺4 1 3 2 6 5 7
	��һ��4Ϊ�����±� i j �ֱ��1��7��ʼ���м��ߣ���ʣ��㱻��Ϊ������ʱ��i-j=1
	�ٶ�ÿ�ν��еݹ黮�ֲ��������ݹ黮����ɲŽ����ڵ��������У��൱�ڸ��ڵ���󱻷���
	���������һ�Ŷ�������������ôi jһ������ǰͣ�²����أ����յ��º����������Ԫ�ظ������������������Ԫ�ظ���
	���ھ��񣬿���һ��ת�������Ҳ��Ƕ���������������£����෴��Ԫ�رȽϷ�ʽ�ٽ���һ��ת�����ɵ�֪�Ƿ�Ϊ����
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
		//���Ƕ����������������ǲ��Ǿ���
		get_post(true, 0, node_num - 1, pre_order, post_order);
	}
	if (post_order.size() == node_num)
	{
		//��һ�������������
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
		//���ǵõ����� �� �� ��
		get_post(is_mirror, pre_start + 1, j, pre_order, post_order);
		get_post(is_mirror, i, pre_end, pre_order, post_order);
		post_order.push_back(pre_order[pre_start]);
	}
}
