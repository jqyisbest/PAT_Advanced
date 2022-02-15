#include "round_2_resolve1010.h"
using namespace round_2_resolve1010;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1010::char_to_int(char digit)
{
	if (digit >= '0' && digit <= '9')
		return digit - '0';
	return digit - 'a' + 10;
}
long long round_2_resolve1010::find_lowest_radix(string digits)
{
	long long max = -1;
	for (int i = 0; i < digits.size(); ++i) {
		int int_value = char_to_int(digits[i]);
		if (int_value != -1) {
			if (max < int_value || max == -1) {
				max = int_value;
			}
		}
	}
	return max + 1;
}
long long round_2_resolve1010::any_radix_to_ten(string a, long long radix)
{
	long long result = 0;
	for (int i = a.size() - 1, j = 0; i >= 0; --i)
	{
		long long int_value = char_to_int(a[i]);
		if (int_value != -1)
		{
			result += int_value*pow(radix, j);
			++j;
		}
	}
	return result;
}
int round_2_resolve1010::resolve()
{
	string a = "";
	string b = "";
	int tag = 0;
	long long radix_known = 0;
	cin >> a >> b >> tag >> radix_known;
	//已知进制的数
	string c;
	//未知进制的数
	string d;
	//将给定进制的数转为十进制值
	long long value_in_ten = 0;
	if (1 == tag)
	{
		c = a;
		d = b;
	}
	else
	{
		c = b;
		d = a;
	}
	value_in_ten = any_radix_to_ten(c, radix_known);
	//二分搜索，看看能否得到一样的十进制值
	long long radix_l, radix_r, radix_mid;
	radix_l = find_lowest_radix(d);
	radix_r = value_in_ten;
	while (radix_l <= radix_r)
	{
		radix_mid = (radix_l + radix_r) >> 1;
		long long value_unkown = any_radix_to_ten(d, radix_mid);
		if (value_unkown >= value_in_ten || value_unkown < 0)//此处有=,向左界偏以输出最小的那个
			radix_r = radix_mid - 1;
		else radix_l = radix_mid + 1;
	}
	if (any_radix_to_ten(d, radix_l) == value_in_ten)
	{
		cout << radix_l;
	}
	else
	{
		cout << "Impossible";
	}
	return 0;
}