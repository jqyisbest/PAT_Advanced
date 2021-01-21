#include "resolve1152.h"
/*
	注意判定素数时要特判0和1
*/
int resolve1152::resolve()
{
	int l, k;
	string s;
	cin >> l >> k >> s;
	if (l < k)
	{
		cout << "404";
	}
	else
	{
		for (int i = 0; i <= l - k; i++)
		{
			string sub_s = s.substr(i, k);
			if (is_prime(stoi(sub_s)))
			{
				cout << sub_s;
				return 0;
			}
		}
		cout << "404";
	}
	return 0;
}

bool resolve1152::is_prime(int num)
{
	if (num == 0 || num == 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num% i == 0)
		{
			return false;
		}
	}
	return true;
}