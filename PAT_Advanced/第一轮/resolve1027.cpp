#include "resolve1027.h"

int resolve1027::resolve()
{
	int r = 0, g = 0, b = 0;
	cin >> r >> g >> b;
	string* color_digit=new string[3];
	color_digit[0] = change_from_radix_ten(r);
	color_digit[1] = change_from_radix_ten(g);
	color_digit[2] = change_from_radix_ten(b);
	cout << "#";
	for (size_t i = 0; i < 3; i++)
	{
		if (color_digit[i].length()==1)
		{
			color_digit[i].insert(0, 1, '0');
		}
		cout << color_digit[i];
	}
	return 0;
}

string resolve1027::change_from_radix_ten(long long digits_in_radix_ten)
{
	//除基取余法
	string ans = "";
	//使用do{}while（）以防止输入为0的情况
	do {
		int t = digits_in_radix_ten%13;
		if (t >= 0 && t <= 9)
		{
			ans += t + '0';
		}
		else
		{
			ans += t - 10 + 'A';
		}
		digits_in_radix_ten /= 13;
	} while (digits_in_radix_ten != 0);
	reverse(ans.begin(), ans.end());
	return ans;
}
