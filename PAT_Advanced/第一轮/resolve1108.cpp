#include "resolve1108.h"

/*
	���Ե�23û��������

	�ٶ�֮������Ǹ�ү�����ˡ�����
	2��3���Ե�ֱ��Ӧ��
		1��ע����Ŀֻ��һ��Ԫ�ص�ʱ��Ҫ��������� number������numbers�����Ե�2��
		2��С�������û������Ҳ�ǺϷ����롣���� 59. ����ȫ�Ϸ��ġ�
	��һ�������оݣ����ҵģ�û������Ŀ��
	�ڶ�����ʲô��59.�ǺϷ�����������������������զ��İ�����ôдСѧ��ѧ��ʦû�������

	���ο�������sscanf/sprintf��ֱ�Ӿͱܿ��˵ڶ��㣬ֵ��ѧϰ��
*/
int resolve1108::resolve()
{
	int n = 0, num_count = 0;
	double sum = 0.0, num = 0.0;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (is_legal(s, num))
		{
			num_count++;
			sum += num;
		}
		else
		{
			cout << "ERROR: " << s << " is not a legal number" << endl;
		}
	}
	if (num_count == 0)
	{
		cout << "The average of 0 numbers is Undefined";
	}
	else if (num_count == 1)
	{
		printf("The average of 1 number is %.2lf", sum);
	}
	else
	{
		printf("The average of %d numbers is %.2lf", num_count, sum / (double)num_count);
	}
	return 0;
}

bool resolve1108::is_num(char c)
{
	return c >= '0'&&c <= '9';
}

bool resolve1108::is_legal(string s, double & num)
{
	bool is_negative = false, have_dot = false, is_legal = false;
	int decimal_places_count = 0;
	//��һλֻ�������ֻ��߸���
	if (is_num(s[0]) || (is_negative = s[0] == '-'))
	{
		is_legal = true;
		//��һλ�Ǹ��ŵڶ�λֻ��������
		if (is_negative)
		{
			if (!is_num(s[1]))
			{
				is_legal = false;
			}
		}
		for (int i = 1; i < s.size() && is_legal; i++)
		{
			if (s[i] == '.')
			{
				if (have_dot)
				{
					is_legal = false;
				}
				have_dot = true;
			}
			else if (is_num(s[i]))
			{
				if (have_dot)
				{
					decimal_places_count++;
					if (decimal_places_count > 2)
					{
						is_legal = false;
					}
				}
			}
			else
			{
				is_legal = false;
			}
		}
		/*if (is_legal&&have_dot&&decimal_places_count == 0)
		{
			is_legal = false;
		}*/
		if (is_legal)
		{
			num = stod(s);
			is_legal = (num <= 1000.0&&num >= -1000.0);
		}
	}
	return is_legal;
}
