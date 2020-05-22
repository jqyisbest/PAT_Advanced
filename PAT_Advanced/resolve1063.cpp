#include "resolve1063.h"
/*
	���ݷ�ΧΪlong
	��set��¼ÿһ�������˵���
	����һmap��¼ÿһ��set������set���ظ�����
	��ѯʱ����set_interaction ȡ����

	nice��OAC��ע����Ѱ��ÿ��set���ظ���ʱ��Ҫ��ȫ�ַ�Χ��Ѱ��
	0
	����ȷ
	4 ms	464 KB
	1
	����ȷ
	4 ms	352 KB
	2
	����ȷ
	4 ms	368 KB
	3
	����ȷ
	15 ms	384 KB
	4
	����ȷ
	115 ms	5888 KB

	��������ʱ��Ч�ʱ�����ı����ȶ�Ҫ��һЩ���Կռ任ʱ�䡣
	0
	����ȷ
	4 ms	424 KB
	1
	����ȷ
	4 ms	424 KB
	2
	����ȷ
	5 ms	512 KB
	3
	����ȷ
	14 ms	492 KB
	4
	����ȷ
	188 ms	2800 KB
*/
int resolve1063::resolve()
{
	//��¼ÿһ��set������
	vector<set<long>> sets;
	//��¼ÿһ��set���ظ���
	map<int, set<long>> same;
	//��¼ÿһ�����ֵ���
	map<long, int> num;
	//set������ÿ��set��Ԫ��������ѯ������ѯ����1����ѯ����2
	//50 10000 2000
	int n, m, k, q1, q2;
	long val;
	scanf("%d", &n);
	sets.resize(n + 1);
	for (size_t i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (size_t j = 0; j < m; j++)
		{
			scanf("%ld", &val);
			if (sets[i].insert(val).second)
			{
				if (num.count(val) == 0)
				{
					num[val] = 1;
				}
				else
				{
					++num[val];
				}
			}
		}
	}
	for (size_t i = 1; i <= n; i++)
	{
		set<long> num_set = sets[i];
		for (set<long>::iterator it = num_set.begin(); it != num_set.end(); it++)
		{
			if (num[*it] > 1)
			{
				//�ͱ�ļ������ظ�
				same[i].insert(*it);
			}
		}
	}
	//��ʼ�����ѯ����
	scanf("%d", &k);
	vector<long> inter_set;
	for (size_t i = 0; i < k; i++)
	{
		scanf("%d %d", &q1, &q2);
		set<long> same1 = same[q1];
		set<long> same2 = same[q2];
		inter_set.resize(same1.size() + same2.size());
		auto end = set_intersection(same1.begin(), same1.end(), same2.begin(), same2.end(), inter_set.begin());
		double nc = end - inter_set.begin(), nt = sets[q1].size() + sets[q2].size() - nc;
		printf("%.1f%%\n", nc * 100 / nt);
	}
	return 0;
}
