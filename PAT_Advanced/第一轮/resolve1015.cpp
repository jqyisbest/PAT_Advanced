#include "resolve1015.h"

/**
	翻转数字
	判断翻转前后数字是否为素数
*/
int resolve1015::resolve()
{
	vector<long long>num_check;
	while (true)
	{
		long long n = 0;
		int d = 0;
		cin >> n;
		if (n<0)
		{
			break;
		}
		cin >> d;
		num_check.push_back(n);
		num_check.push_back(d);
	}
	for (auto i = 0; i<num_check.size(); i+=2)
	{
		if (!is_prime(num_check[i]))
		{
			cout << "No" ;
		}
		else
		{
			long long n_reverse = change_to_radix_ten(change_from_radix_ten(num_check[i], num_check[i+1]), num_check[i + 1]);
			cout << (is_prime(n_reverse) ? "Yes" : "No");
		}
		if (i<(num_check.size()-2))
		{
			cout << endl;
		}
	}
	return 0;
}

bool resolve1015::is_prime(long long n)
{
	//!!!注意 1 不是素数，1号测试点就是测这个
	if (n <= 1) return false;
	for (long long j = 2; j <= sqrt(n);++j) {
		if (n%j == 0) {
			return false;
		}
	}
	return true;
}

int resolve1015::symbol_to_int(char digit)
{
	if (digit >= '0' && digit <= '9')
		return digit - '0';
	return digit - 'a' + 10;
}

long long resolve1015::change_to_radix_ten(string digits, long long radix)
{
	long long result = 0;
	for (int i = digits.size() - 1, j = 0; i >= 0; --i)
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

string resolve1015::change_from_radix_ten(long long digits, long long radix)
{
	//除基取余法
	string ans = "";
	//使用do{}while（）以防止输入为0的情况
	do {
		int t = digits%radix;
		if (t >= 0 && t <= 9) 
		{ 
			ans += t + '0'; 
		}
		else 
		{ 
			ans += t - 10 + 'a'; 
		}
		digits /= radix;
	} while (digits != 0);		
	//因为就是要求翻转，所以这里就不转了。
	//reverse(ans.begin(),ans.end());	
	return ans;
}
