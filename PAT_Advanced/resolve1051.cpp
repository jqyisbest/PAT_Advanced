#include "resolve1051.h"
/*
	ջ������ȳ���������������
	�Գ�ջ���е�ÿһ��Ԫ�� b ��ǰһ����ջԪ�� a ����Ϊ���������
	a>b������ȳ��������������ջ�е����ݣ�ͳ�����ǵڼ��� ���� ��ջ���������Ƿ��㹻
	a<b: �Ƚ��ȳ�����Ҫ��ǰ���Ԫ��b��ǰһ��Ԫ��b-1�Ѿ������

	Ŷ�𣬹��򲢲�����
	0
	����ȷ
	4 ms	384 KB
	1
	�𰸴���
	4 ms	368 KB
	2
	�𰸴���
	4 ms	384 KB
	3
	����ȷ
	5 ms	384 KB
	4
	����ȷ
	4 ms	384 KB
	5
	�𰸴���
	3 ms	384 KB

	໣������жϵ�һ������Ƿ�Ϸ���==    ûɶӰ�졣����
	int resolve1051::resolve()
	{
	int m = 0, n = 0, k = 0, last_print = 0, current_print = 0, print_count = 0;
	scanf("%d %d %d", &m, &n, &k);
	//��has_print[0]Ϊtrue����Ǹ���������
	bool *has_print = new bool[n + 1];
	for (int i = 0; i < k; ++i)
	{
	fill(has_print, has_print + n + 1, false);
	last_print = 0;
	print_count = 1;
	for (int j = 0; j < n; ++j)
	{
	scanf("%d", &current_print);
	has_print[current_print] = true;
	if (last_print == 0)
	{
	has_print[0] = current_print > m;
	}
	else if (!has_print[0])
	{
	if (last_print > current_print)
	{
	++print_count;
	if (print_count > m)
	{
	has_print[0] = true;
	}
	}
	else if (last_print < current_print)
	{
	if (!has_print[current_print - 1])
	{
	has_print[0] = true;
	}
	print_count = 1;
	}
	else
	{
	has_print[0] = true;
	}
	}
	last_print = current_print;
	}
	if (has_print[0])
	{
	printf("NO\n");
	}
	else
	{
	printf("YES\n");
	}
	}
	return 0;
	}

	����תΪ�ж��Ƿ�����
	���ˣ�תΪģ���/(��o��)/~~
	�����������
	������ջ˳��Ϊ1234��n����֪��ջ�е�Ԫ�ش�ջ����ջ��һ���ǰ��ϸ�ݼ����е�,����ÿ����i��ջ֮ǰ,��iС����һ���Ѿ���ջ�ˡ�����ֻ�뵽����һ����������
	���ԣ�
	��iС����Ҫ��Ȼ�Ѿ���ջ,Ҫ��Ȼ��ջ�У��������ջ����һ����i�����棬���ϸ�ݼ�����,��˿ɼ������iС��������ջ����һ����i֮�����,���������������i����ı�iС����һ�����ϸ�ݼ�����.�����ջϵ�в��Ϸ���

	NB
	0
	����ȷ
	3 ms	512 KB
	1
	����ȷ
	3 ms	384 KB
	2
	����ȷ
	3 ms	384 KB
	3
	����ȷ
	4 ms	424 KB
	4
	����ȷ
	4 ms	384 KB
	5
	����ȷ
	5 ms	360 KB

	������ջ����Ϊ��1234567...k...n��kΪ��ǰ��ջԪ�أ��Ҵ˿�ջ��һ������k,7,6,5,4,3,2,1�⼸��Ԫ��
	�����ٲ���k��Ԫ�أ����ջ����Ϊk...7654321
	��ʵ�ʳ�ջ���̿����Ϊ����k...7654321�������У��������k+1...n������Ԫ��
	���磬�ҿ������k�Ͳ�һ��k+1������Ҳ�������k...7���ٲ���k+1
	����������ô�壬���г�ջ����Ԫ��k...7654321�����λ�ò���䣡
	���ڳ�ջ�����У�����ȳ�����������ֱ�����Ϊ��
	1������ȳ������˿�k��ջ����ô��k���ջ�ұ�k�Ƚ�վ��Ԫ�ص����λ�ò���䣡�������м�Ϊ��k���ջ�ұ�kС����һ�����ϸ�ݼ������༴��k���ջ�ĵ������в����kС��
	2�������������ջ�����а��ݼ����е�����Ķ��������ջ�����У��������ݼ�����ĸ������ܴ����������
*/
int resolve1051::resolve()
{
	int m = 0, n = 0, k = 0, last_print = 0, current_print = 0, print_count = 0, max_print = 0;
	scanf("%d %d %d", &m, &n, &k);
	//��has_print[0]Ϊtrue����Ǹ���������
	bool *has_print = new bool[n + 1];
	for (int i = 0; i < k; ++i)
	{
		fill(has_print, has_print + n + 1, false);
		last_print = 0;
		max_print = 0;
		print_count = 1;
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &current_print);
			has_print[current_print] = true;
			if (last_print == 0)
			{
				has_print[0] = current_print > m;
			}
			else if (!has_print[0])
			{
				if (last_print > current_print)
				{
					++print_count;
					if (print_count > m)
					{
						has_print[0] = true;
					}
				}
				else if (last_print < current_print)
				{
					if (current_print < max_print)
					{
						//
						has_print[0] = true;
					}
					print_count = 1;
				}
				else
				{
					has_print[0] = true;
				}
			}
			last_print = current_print;
			if (max_print < current_print)
			{
				max_print = current_print;
			}
		}
		if (has_print[0])
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
