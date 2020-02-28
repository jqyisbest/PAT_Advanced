#include "common.h"
namespace common {
	void print_array(int* a, int n) {
		for (int i = 0; i < n - 1; ++i)
		{
			cout << a[i] << ",";
		}
		cout << a[n - 1] << "\n";
	}

	void print_array(int** a, int m, int n) {
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				cout << a[i][j] << ",";
			}
			cout << a[i][n - 1] << "\n";
		}
	}
	void fill_array(int* a, int n,int val) {
		for (int i = 0; i < n; ++i)
		{
			a[i] = val;
		}
	}
	void fill_array(int** a, int m, int n, int val) {
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				a[i][j] = val;
			}
		}
	}

	bool is_prime(long long n)
	{
		if (n <= 1) return false;
		for (long long j = 2; j <= sqrt(n); ++j) {
			if (n%j == 0) {
				return false;
			}
		}
		return true;
	}

	bool sort_by_alphabetical_asc(string a, string b)
	{
		auto min_size = a.size() <= b.size() ? a.size() : b.size();
		for (auto i = 0; i <min_size; ++i)
		{
			if (a[i]!=b[i])
			{
				return a[i] < b[i];
			}
		}
		return min_size == a.size();
	}

	bool sort_by_alphabetical_desc(string a, string b)
	{
		auto min_size = a.size() >= b.size() ? a.size() : b.size();
		for (auto i = 0; i <min_size; ++i)
		{
			if (a[i] != b[i])
			{
				return a[i] > b[i];
			}
		}
		return min_size ==b.size();
	}

	int symbol_to_int(char digit)
	{
		if (digit >= '0' && digit <= '9')
			return digit - '0';
		return digit - 'a' + 10;
	}

	long long change_to_radix_ten(string digits, long long radix)
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

	string change_from_radix_ten(long long digits_in_radix_ten, long long target_radix)
	{
		//除基取余法
		string ans = "";
		//使用do{}while（）以防止输入为0的情况
		do {
			int t = digits_in_radix_ten%target_radix;
			if (t >= 0 && t <= 9)
			{
				ans += t + '0';
			}
			else
			{
				ans += t - 10 + 'a';
			}
			digits_in_radix_ten /= target_radix;
		} while (digits_in_radix_ten != 0);
		reverse(ans.begin(),ans.end());	
		return ans;
	}	
}