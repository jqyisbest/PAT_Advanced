#include "resolve1112.h"
/*
	先判断出那些字符是坏的，再输出的时候那些字符只输出一次
	判断字符时注意 每个字符，要么就一直有问题，要么就没有问题

	坏掉的字符一定是重复k次，不多，不少
*/
int resolve1112::resolve()
{
	map<char, int> is_stucked;
	for (int i = 0; i < 26; i++)
	{
		is_stucked[('a' + i)] = -1;
	}
	for (int i = 0; i < 10; i++)
	{
		is_stucked[('0' + i)] = -1;
	}
	is_stucked['_'] = -1;
	int k = 0, appear_times = 0;
	string s;
	cin >> k >> s;
	vector<char> stucked_char;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (i == 0)
		{
			appear_times = 1;
		}
		else
		{
			if (s[i] != s[i - 1])
			{
				//对i-1进行判断
				if (is_stucked[s[i - 1]] != 0)
				{
					//不是良民
					if (appear_times%k != 0)
					{
						//颁发永久良民证
						is_stucked[s[i - 1]] = 0;
					}
					else
					{
						if (is_stucked[s[i - 1]] != 1)
						{
							stucked_char.push_back(s[i - 1]);
						}
						//此次被认定为大大滴坏人，后面有机会做回良民;
						is_stucked[s[i - 1]] = 1;
					}
				}
				appear_times = 1;
			}
			else
			{
				appear_times++;
			}
		}
		if (i == s.size() - 1)
		{
			//对最后一组字符进行判断
			if (is_stucked[s[i]] != 0)
			{
				//不是良民
				if (appear_times%k != 0)
				{
					//颁发永久良民证
					is_stucked[s[i]] = 0;
				}
				else
				{
					if (is_stucked[s[i]] != 1)
					{
						stucked_char.push_back(s[i]);
					}
					//此次被认定为大大滴坏人，后面无机会做回良民;
					is_stucked[s[i]] = 1;
				}
			}
		}
	}
	for (vector<char>::iterator i = stucked_char.begin(); i != stucked_char.end(); i++)
	{
		if (is_stucked[*i] == 1)
		{
			cout << *i;
		}
	}
	cout << endl;
	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (is_stucked[s[i]] == 1)
		{
			i += k - 1;
		}
	}
	return 0;
}