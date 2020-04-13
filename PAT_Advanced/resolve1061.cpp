#include "resolve1061.h"
/*
	字符串比对
	前两个字符串分别找出前两个相同的字符，一个代表星期，一个代表时间
	后两个字符串找出第一个相同的字符的位置，代表分钟

	这都不是OAC？ 艹，前两个字符串分别找出前两个位置内容均相同的字符，应该都是双指针
	0
	答案正确
	5 ms	384 KB
	1
	答案错误
	4 ms	424 KB
	2
	答案正确
	5 ms	424 KB
	3
	答案正确
	5 ms	424 KB
	4
	答案错误
	4 ms	384 KB
	5
	答案正确
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
				//找第二个相同
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
