#include "resolve1040.h"
/*
	暴力破解 = =
*/
int resolve1040::resolve()
{
	int max_length = 0;
	string source;
	getline(cin, source);
	for (int i = 0; i<source.size(); ++i) {
		int j;
		for (j = 1; i - j >= 0 && i + j<source.size() && source[i + j] == source[i - j]; ++j);//以当前字符为回文中心查找最长回文子串
		max_length = max(max_length, 2 * j - 1);//更新回文子串最大长度
		for (j = 0; i - j >= 0 && i + j + 1<source.size() && source[i - j] == source[i + 1 + j]; ++j);//以当前字符为回文中心左侧字符查找最长回文子串
		max_length = max(max_length, 2 * j);//更新回文子串最大长度
	}
	cout << max_length;
	return 0;
}