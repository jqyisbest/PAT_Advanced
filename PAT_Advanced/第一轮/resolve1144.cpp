#include "resolve1144.h"
/*
	���Դ������set�洢���г��ֵ�������
	Ȼ�����set��ֵ����ţ���1��ʼ����һ�µľ������Ų�����

	ע���������д�1��ʼ���м�û�м�ϵ��������ʱӦֱ�����min_miss
*/
int resolve1144::resolve()
{
	set<int> all_positive;
	int n, min_miss = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num > 0)
		{
			all_positive.insert(num);
		}
	}
	for (set<int>::iterator it = all_positive.begin(); it != all_positive.end(); it++, min_miss++)
	{
		if ((*it) != min_miss)
		{
			break;
		}
	}
	cout << min_miss;
	return 0;
}