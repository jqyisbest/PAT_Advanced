#include "resolve1050.h"
/*
	��һ����������Щ�ַ��ǲ��������
	scanf����ո�scanf("%[^\n]",&);
	scanf�Զ����������scanf("%[^������]",&);
*/
int resolve1050::resolve()
{
	string str_1, str_2;
	str_1.resize(10001);
	str_2.resize(10001);
	bool *usable = new bool[256];
	//��䲻��ʡ������OJ��boolֵ����Ĭ��Ϊtrue==
	//��ʡ�ԣ������Ե�2���WA
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
