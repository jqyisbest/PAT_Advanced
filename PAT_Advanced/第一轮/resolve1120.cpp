#include "resolve1120.h"
/*
	easy
*/
int resolve1120::resolve()
{
	int n = 0;
	set<int> id;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int total = 0;
		string num;
		cin >> num;
		for (size_t j = 0; j < num.size(); j++)
		{
			total += num[j] - '0';
		}
		id.insert(total);
	}
	cout << id.size() << endl;
	for (set<int>::iterator i = id.begin(); i != id.end(); i++)
	{
		if (i != id.begin())
		{
			cout << " ";
		}
		cout << *i;
	}
	return 0;
}