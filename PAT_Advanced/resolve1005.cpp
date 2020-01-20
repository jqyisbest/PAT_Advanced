#include "resolve1005.h"
#include "common.h"

int resolve1005::resolve()
{	
	string* words = new string[10]{"zero","one","two","three","four","five","six","seven","eight","nine"};
	char* digts = new char[100];
	fill(digts, digts + 100, '\0');
	cin >> digts;
	int result = 0;
	for (int i = 0; i < 100;++i) {
		char digt = digts[i];
		if (digt=='\0')
		{
			break;
		}
		result += (int)digt-48;
	}
	int result_digt_num = 0;
	do
	{
		//从右开始最低位
		int lowest_digt = result % 10;
		digts[result_digt_num] = lowest_digt;
		result = result / 10;
		++result_digt_num;
	} while (result/10!=0);
	//保存大于10的数的最高位
	if (result!=0)
	{
		digts[result_digt_num] = result;
		++result_digt_num;
	}
	//逆序输出结果
	for (int i = result_digt_num-1; i > 0; --i)
	{
		int index = (int)digts[i];
		cout << words[index] << " ";
	}
	cout << words[(int)digts[0]];
	return 0;
}
