#include "resolve1010.h"
#include "common.h"
/*
	哭了，这次AC太过艰难。。
	总体思路和网上很多人的一样，暴力搜寻
	大致的坑有这么几个：
	1、上下界的限定
	2、搜寻二分法的使用（否则第七个测试点超时）
	3、longlong类型的使用
	下界是未知数中最大的一位+1
	上界是已知数
	开始用的++暴力搜寻然后下界计算函数还写的错了，求成了MIN，导致多个点报错
	百度之后改用longlong和二分，重视上下界的限定以后终于发现了。。━┳━　━┳━

*/
int resolve1010::resolve()
{
	string a="";
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
	value_in_ten = change_radix_ten(c, radix_known);
	//二分搜索，看看能否得到一样的十进制值
	long long radix_l, radix_r, radix_mid;
	radix_l = find_lowest_radix(d);
	radix_r = value_in_ten+1;
	while (radix_l<=radix_r)
	{
		radix_mid = (radix_l + radix_r) >> 1;
		long long value_unkown = change_radix_ten(d, radix_mid);
		//此处有=,向左界偏以输出最小的那个
		if (value_unkown >= value_in_ten || value_unkown < 0)
			radix_r = radix_mid - 1;
		else radix_l = radix_mid + 1;
	}
	if (change_radix_ten(d, radix_l)==value_in_ten)
	{
		cout << radix_l;
	}
	else
	{
		cout << "Impossible";
	}
	return 0;
}


int resolve1010::symbol_to_int(char digit)
{
	if (digit >= '0' && digit <= '9')
		return digit - '0';
	return digit - 'a' + 10;
}
long long resolve1010::find_lowest_radix(string digits) {
	long long max = -1;
	for (int i = 0; i<digits.size(); ++i) {
		int int_value = symbol_to_int(digits[i]);
		if (int_value != -1) {
			if (max<int_value || max == -1) {
				max = int_value;
			}
		}
	}
	return max+1;
}


long long resolve1010::change_radix_ten(string digits, long long  radix)
{
	long long result = 0;
	for (int i = digits.size()-1, j = 0; i >= 0; --i)
	{
		long long int_value = symbol_to_int(digits[i]);
		if (int_value != -1)
		{
			result += int_value*pow(radix, j);
			++j;
		}
	}
	return result;
}
