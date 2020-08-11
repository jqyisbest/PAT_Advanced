#include "resolve1132.h"
/*
	嗷，忘了考虑右半边为0的情况了
*/
int resolve1132::resolve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string num_s;
		cin >> num_s;
		int half = num_s.size() / 2;
		long long num = stoll(num_s), num_1 = stoll(num_s.substr(0, half)), num_2 = stoll(num_s.substr(half, half));
		if (num_1 != 0 && num_2 != 0 && num%num_1 == 0 && num / num_1%num_2 == 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
