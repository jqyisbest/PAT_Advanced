#include "resolve1040.h"
/*
	�����ƽ� = =
*/
int resolve1040::resolve()
{
	int max_length = 0;
	string source;
	getline(cin, source);
	for (int i = 0; i<source.size(); ++i) {
		int j;
		for (j = 1; i - j >= 0 && i + j<source.size() && source[i + j] == source[i - j]; ++j);//�Ե�ǰ�ַ�Ϊ�������Ĳ���������Ӵ�
		max_length = max(max_length, 2 * j - 1);//���»����Ӵ���󳤶�
		for (j = 0; i - j >= 0 && i + j + 1<source.size() && source[i - j] == source[i + 1 + j]; ++j);//�Ե�ǰ�ַ�Ϊ������������ַ�����������Ӵ�
		max_length = max(max_length, 2 * j);//���»����Ӵ���󳤶�
	}
	cout << max_length;
	return 0;
}