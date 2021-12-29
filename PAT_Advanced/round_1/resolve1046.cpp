#include "resolve1046.h"
/*
	�ۼӺ��ٴ��С
	1 1+2 1+2+3 1+2+3+4 1+2+3+4+5
	2-4 = (1-4 - 1-2) �Ƿ�����̹��룿�����-(1-4 - 1-2):(1-4 - 1-2);
	0
	����ʱ����
	3 ms	508 KB
	1
	����ȷ
	4 ms	440 KB
	2
	����ȷ
	28 ms	896 KB
	..��ȻԽ�硣���Ҳ�������i=n��ʱ��accumulative_distance[i + 1]= accumulative_distance[i]+temp_1;Խ��

	��Ȼ����
	0
	����ȷ
	4 ms	352 KB
	1
	����ȷ
	4 ms	428 KB
	2
	����ȷ
	27 ms	868 KB
*/
int resolve1046::resolve()
{
	int n = 0, m = 0, temp_1 = 0, temp_2 = 0;
	scanf("%d", &n);
	//��1��ʼ���ۼ�·�� accumulative_distance[0]��ʾ��·��
	int* accumulative_distance = new int[n + 1];
	accumulative_distance[1] = 0;
	for (size_t i = 1; i <= n; i++)
	{
		scanf("%d", &temp_1);
		if (i == n)
		{
			accumulative_distance[0] = accumulative_distance[n] + temp_1;
		}
		else
		{
			accumulative_distance[i + 1] = accumulative_distance[i] + temp_1;
		}
	}
	scanf("%d", &m);
	for (size_t i = 0; i < m; ++i)
	{
		scanf("%d %d", &temp_1, &temp_2);
		if (temp_1 == temp_2)
		{
			printf("%d\n", 0);
		}
		else
		{
			int min_target = min(temp_1, temp_2), max_target = max(temp_1, temp_2);
			int distance = accumulative_distance[max_target] - accumulative_distance[min_target];
			printf("%d\n", distance > accumulative_distance[0] / 2 ? accumulative_distance[0] - distance : distance);
		}
	}
	return 0;
}
