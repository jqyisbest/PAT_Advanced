#include "resolve1124.h"

int resolve1124::resolve()
{
	bool have_winner = false, should_choose = true;
	int m = 0, n = 0, s = 0;
	cin >> m >> n >> s;
	vector<string>candidate(m + 1);
	map<string, int>winner;
	for (size_t i = 1; i <= m; i++)
	{
		cin >> candidate[i];
		winner[candidate[i]] = 0;
	}
	int last_i = s;
	for (size_t i = s; i <= m; i++)
	{
		if (i - last_i == n)
		{
			should_choose = true;
		}
		if (should_choose)
		{
			if (winner[candidate[i]] == 0)
			{
				cout << candidate[i] << endl;
				winner[candidate[i]] = 1;
				last_i = i;
				should_choose = false;
				have_winner = true;
			}
		}
	}
	if (!have_winner)
	{
		cout << "Keep going...";
	}
	return 0;
}
