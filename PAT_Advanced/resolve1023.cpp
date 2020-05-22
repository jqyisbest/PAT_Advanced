#include "resolve1023.h"
/**
	比较double前后0-9的个数，若个数一致，则认为Yes

	必须用string或者int*来存，直接longlong 甚至 unsigned  longlong都是不够的

	嘻嘻嘻，第一次如此接近柳神的行数
*/
int resolve1023::resolve()
{
	string original_num, double_num;
	cin >> original_num;
	//0-9的位数
	int* num_of_digits = new int[10];
	fill(num_of_digits, num_of_digits + 10, 0);
	//进位标记
	bool flag = false;
	for (int i = original_num.length()-1; i >=0 ; --i)
	{
		int digit = original_num[i] - 48;
		++num_of_digits[digit];
		digit *= 2;
		int digit_result = flag ? (digit % 10 + 1) : (digit % 10);
		double_num.insert(0,1,digit_result + 48);
		--num_of_digits[digit_result];
		flag = digit > 9;
	}
	string result = "Yes";
	for (size_t i = 0; i < 10; ++i)
	{
		if (flag||num_of_digits[i] != 0)
		{
			result = "No";
			break;
		}
	}
	cout << result<<endl;
	//别忘了最后一位数的进位==
	flag ? cout << '1' << double_num : cout << double_num;
	return 0;
}
