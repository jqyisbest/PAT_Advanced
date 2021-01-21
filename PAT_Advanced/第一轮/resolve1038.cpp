#include "resolve1038.h"
/*
	将数字片段当作字符串，按字符大小从小到大排序
	当有部分相同前缀时，看多出的下一位是否比第一位小
	比如 321<32 3214>321 3214<32

	艹，跳0跳疯了把中间的0也跳了==

	。。奇怪，看答案的思路和我的差不多啊 为啥测试点5过不了 /(ㄒoㄒ)/~~
	不过它的比较函数好简单啊==；
	return s1+s2<s2+s1; ...

	果然是比较函数的问题。。
	我的比较函数过不了测试点5...
	bool cmp_s(const string& s1, const string& s2)
	{
	int index = 0;
	while (index < s1.length() || index < s2.length())
	{
	if (index < s1.length() && index < s2.length())
	{
	if (s1[index] < s2[index])
	{
	break;
	}
	else if (s1[index] > s2[index])
	{
	return false;
	}
	}
	else if (index < s1.length())
	{
	return s1[index] < s2[0];
	}
	else if (index < s2.length())
	{
	return s2[index] > s1[0];
	}
	++index;
	}
	return true;
	}

*/
int resolve1038::resolve()
{
	string* segments = nullptr;
	int num_of_segment = 0;
	cin >> num_of_segment;
	segments = new string[num_of_segment];
	for (size_t i = 0; i < num_of_segment; ++i)
	{
		//scanf("%s", segments[i].c_str());
		cin >> segments[i];
	}
	sort(segments, segments + num_of_segment, cmp_s);
	bool is_zero = true;
	for (size_t i = 0; i < num_of_segment; ++i)
	{
		for (size_t j = 0; j < segments[i].length(); ++j)
		{
			if (is_zero&&segments[i][j] == '0')
			{
				continue;
			}
			cout << segments[i][j];
			is_zero = false;
		}
	}
	if (is_zero)
	{
		cout << 0;
	}
	return 0;
}

bool resolve1038::cmp_s(const string& s1, const string& s2)
{
	return s1 + s2 < s2 + s1;
}
