#include "resolve1050.h"
/*
	用一个数组标记哪些字符是不可输出的
	scanf读入空格：scanf("%[^\n]",&);
	scanf自定义结束符：scanf("%[^结束符]",&);
*/
int resolve1050::resolve()
{
	string str_1, str_2;
	str_1.resize(10001);
	str_2.resize(10001);
	bool *usable = new bool[256];
	//这句不能省！！！OJ上bool值不是默认为true==
	//如省略，除测试点2外均WA
	fill(usable, usable + 256, true);
	scanf("%[^\n]\n%[^\n]", &str_1[0], &str_2[0]);
	int char_index = -1;
	while (str_2[++char_index] != '\0')
	{
		usable[str_2[char_index]] = false;
	}
	char_index = -1;
	while (str_1[++char_index] != '\0')
	{
		if (usable[str_1[char_index]])
		{
			printf("%c", str_1[char_index]);
		}
	}
	return 0;
}
