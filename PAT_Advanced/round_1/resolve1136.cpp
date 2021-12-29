#include "resolve1136.h"

int resolve1136::resolve()
{
	int times = 0;
	string a;
	cin >> a;
	bool ok = is_palindromic(a);
	while (!ok&&times < 10)
	{
		string b(a);
		reverse(a.begin(), a.end());
		cout << b << " + " << a << " = ";
		add(a, b);
		cout << a << endl;
		ok = is_palindromic(a);
		times++;
	}
	cout << (ok ? a + " is a palindromic number." : "Not found in 10 iterations.");
	return 0;
}

bool resolve1136::is_palindromic(string &num)
{
	for (int i = 0; i < num.size() / 2; i++)
	{
		if (num[i] != num[num.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}
void resolve1136::add(string & a, string & b)
{
	bool carry = false;
	int small_size = min(a.size(), b.size());
	for (int i = small_size - 1; i >= 0; i--)
	{
		int a_int = a[i] - '0';
		int b_int = b[i] - '0';
		a_int += b_int;
		if (carry)
		{
			a_int++;
		}
		carry = a_int > 9;
		a_int %= 10;
		a[i] = '0' + a_int;
	}
	if (a.size() > b.size())
	{
		//考虑多出的进位
		while (carry&&small_size < a.size())
		{
			int a_rest = a[small_size] - '0';
			a_rest++;
			carry = a_rest > 9;
			a_rest %= 10;
			a[small_size++] = '0' + a_rest;
		}
	}
	else if (a.size() < b.size())
	{
		//考虑多出的进位
		for (; small_size < b.size(); small_size++)
		{
			if (carry)
			{
				int b_int = b[small_size] - '0';
				b_int++;
				carry = b_int > 9;
				b_int %= 10;
				a.insert(0, 1, '0' + b_int);
			}
		}
	}
	//还他妈有进位
	if (carry)
	{
		a = "1" + a;
	}
}