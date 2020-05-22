#include "resolve1061.h"
/*
	�ַ����ȶ�
	ǰ�����ַ����ֱ��ҳ�ǰ������ͬ���ַ���һ���������ڣ�һ������ʱ��
	�������ַ����ҳ���һ����ͬ���ַ���λ�ã��������

	�ⶼ����OAC�� ܳ��ǰ�����ַ����ֱ��ҳ�ǰ����λ�����ݾ���ͬ���ַ���Ӧ�ö���˫ָ��
	0
	����ȷ
	5 ms	384 KB
	1
	�𰸴���
	4 ms	424 KB
	2
	����ȷ
	5 ms	424 KB
	3
	����ȷ
	5 ms	424 KB
	4
	�𰸴���
	4 ms	384 KB
	5
	����ȷ
	4 ms	384 KB
*/
int resolve1061::resolve()
{
	string str[4];
	string day_in_week[7]{ "MON","TUE","WED" ,"THU" ,"FRI" ,"SAT" ,"SUN" };
	bool is_second = false;
	for (size_t i = 0; i < 4; i++)
	{
		str[i].resize(61);
		scanf("%s", &str[i][0]);
	}
	for (size_t i = 0; i < 61; ++i)
	{
		char ch1 = str[0][i], ch2 = str[1][i];
		if ('\0' == ch1 || '\0' == ch2)
		{
			break;
		}
		if (ch1 == ch2)
		{
			if (is_second)
			{
				//�ҵڶ�����ͬ
				if (between('A', 'N', ch1))
				{
					printf("%d:", ch1 - 'A' + 10);
					break;
				}
				else if (between('0', '9', ch1))
				{
					printf("0%c:", ch1);
					break;
				}
			}
			else if (between('A', 'G', ch1))
			{
				printf("%s ", day_in_week[ch1 - 'A'].c_str());
				is_second = true;
			}
		}
	}
	for (size_t i = 0; i < 61; ++i)
	{
		char ch_1 = str[2][i], ch_2 = str[3][i];
		if ('\0' == ch_1 || '\0' == ch_2)
		{
			break;
		}
		if (ch_1 == ch_2 && (between('A', 'Z', ch_1) || between('a', 'z', ch_1)))
		{
			printf("%02d", i);
			break;
		}
	}
	return 0;
}

bool resolve1061::between(char begin, char end, char val)
{
	return val <= end&&val >= begin;
}
