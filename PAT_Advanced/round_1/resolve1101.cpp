#include "resolve1101.h"
/*
	��¼������������ֵ����СֵML/MR
	���ML<X<MR��XΪ��ѡ
	ML�ɶ�̬����,MRʹ���������ά��

	�ðɣ���ʱ�ˡ���
	�����ÿռ任ʱ����

	mapĬ�ϻ��key����������

	���Ե�2Ϊ0����ѡֵ����ʱ������������У������ʽ����==
*/
int resolve1101::resolve()
{
	int n = 0;
	scanf("%d", &n);
	map<int, bool> exist_in_right;
	vector<int> original_nums(n);
	vector<int> candidate;
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &original_nums[i]);
		exist_in_right[original_nums[i]] = true;
	}
	//��ʼ�ж�ÿһ��ֵ�Ƿ�Ϊ��ѡֵ
	int m_l = 0, current_val = 0;
	map<int, bool>::iterator m_r = exist_in_right.begin();
	for (size_t i = 0; i < n; i++)
	{
		current_val = original_nums[i];
		exist_in_right[current_val] = false;
		if (current_val == m_r->first)
		{
			get_next_min(exist_in_right, m_r);
		}
		if (m_l < current_val && (m_r == exist_in_right.end() || current_val < m_r->first))
		{
			//�Ǻ�ѡֵ
			candidate.push_back(current_val);
		}
		//����m_l
		if (m_l < current_val)
		{
			m_l = current_val;
		}
	}
	sort(candidate.begin(), candidate.end());
	printf("%d\n", candidate.size());
	for (size_t i = 0; i < candidate.size(); ++i)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", candidate[i]);
	}
	printf("\n");
	return 0;
}

void resolve1101::get_next_min(map<int, bool>& exist_in_right, map<int, bool>::iterator & min)
{
	for (; min != exist_in_right.end() && !min->second; ++min)
	{
	}
}
