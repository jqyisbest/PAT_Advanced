#include "resolve1031.h"
/*
	23333好玩
*/
int resolve1031::resolve()
{
	string text;
	cin >> text;
	int n1_n3 = 0,length = text.length();
	//计算高
	for (int i = 3; i <= length; ++i)
	{
		int j = (length + 2 - i) >>1;
		if (j <=i&&j>n1_n3)
		{
			n1_n3 = j;
		}
	}
	//计算两列之间的空格数
	int blank_space_num = length - n1_n3 * 2;
	for (size_t i = 0; i < n1_n3-1; ++i)
	{
		cout << text[i];
		for (size_t j = 0; j < blank_space_num; ++j)
		{
			cout << ' ';
		}
		cout << text[length - 1 - i]<<endl;
	}
	blank_space_num += 1;
	for (int i = -1; i < blank_space_num; ++i)
	{
		cout << text[n1_n3 +i];
	}
	return 0;
}