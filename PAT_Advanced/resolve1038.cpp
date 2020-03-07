#include "resolve1038.h"
/*
	������Ƭ�ε����ַ��������ַ���С��С��������
	���в�����ͬǰ׺ʱ�����������һλ�Ƿ�ȵ�һλС
	���� 321<32 3214>321 3214<32

	ܳ����0�����˰��м��0Ҳ����==

	������֣����𰸵�˼·���ҵĲ�డ Ϊɶ���Ե�5������ /(��o��)/~~
	�������ıȽϺ����ü򵥰�==��
	return s1+s2<s2+s1; ...

	��Ȼ�ǱȽϺ��������⡣��
	�ҵıȽϺ��������˲��Ե�5...
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
