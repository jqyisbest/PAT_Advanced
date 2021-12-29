#include "resolve1108.h"

/*
	测试点23没过。。？

	百度之后可真是给爷整吐了。。。
	2、3测试点分别对应：
		1、注意题目只有一个元素的时候，要求输出的是 number而不是numbers（测试点2）
		2、小数点后面没有数字也是合法输入。比如 59. 是完全合法的。
	第一点有理有据，算我的，没看清题目。
	第二点是什么鬼？59.是合法的数？？？？？？？姥姥咋想的啊，这么写小学数学老师没扣你分吗？

	看参考答案里用sscanf/sprintf，直接就避开了第二点，值得学习！
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
	//第一位只能是数字或者负号
	if (is_num(s[0]) || (is_negative = s[0] == '-'))
	{
		is_legal = true;
		//第一位是负号第二位只能是数字
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
