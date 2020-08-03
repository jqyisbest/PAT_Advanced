#include "resolve1112.h"
/*
	���жϳ���Щ�ַ��ǻ��ģ��������ʱ����Щ�ַ�ֻ���һ��
	�ж��ַ�ʱע�� ÿ���ַ���Ҫô��һֱ�����⣬Ҫô��û������

	�������ַ�һ�����ظ�k�Σ����࣬����
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
				//��i-1�����ж�
				if (is_stucked[s[i - 1]] != 0)
				{
					//��������
					if (appear_times%k != 0)
					{
						//�䷢��������֤
						is_stucked[s[i - 1]] = 0;
					}
					else
					{
						if (is_stucked[s[i - 1]] != 1)
						{
							stucked_char.push_back(s[i - 1]);
						}
						//�˴α��϶�Ϊ���λ��ˣ������л�����������;
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
			//�����һ���ַ������ж�
			if (is_stucked[s[i]] != 0)
			{
				//��������
				if (appear_times%k != 0)
				{
					//�䷢��������֤
					is_stucked[s[i]] = 0;
				}
				else
				{
					if (is_stucked[s[i]] != 1)
					{
						stucked_char.push_back(s[i]);
					}
					//�˴α��϶�Ϊ���λ��ˣ������޻�����������;
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