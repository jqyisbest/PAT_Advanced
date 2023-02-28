#include "round_3_resolve1168.h"

bool round_3_resolve1168::is_prime(int a)
{
	if (a < 2)
	{
		return false;
	}
	for (int i = 2; i < a / 2; i++)
	{
		if (a%i == 0)
		{
			return false;
		}
	}
	return true;
}

int round_3_resolve1168::resolve()
{
	string date;
	cin >> date;
	bool flag = true;
	while (date.length() != 0)
	{
		bool prime = is_prime(stoi(date));
		if (flag)
		{
			flag = prime;
		}
		cout << date << " " << (prime ? "Yes" : "No") << endl;
		date = date.substr(1, date.length() - 1);
	}
	if (flag)
	{
		cout << "All Prime!" << endl;
	}
	return 0;
}
