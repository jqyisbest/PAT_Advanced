#include "resolve1116.h"

int resolve1116::resolve()
{
	int is_exist[10000];
	fill(is_exist, is_exist + 10000, 0);
	int n = 0, k = 0;
	map<int, int> rank;
	scanf("%d", &n);
	for (size_t i = 1; i <= n; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		is_exist[temp] = 1;
		rank[temp] = i;
	}
	scanf("%d", &k);
	for (size_t i = 0; i < k; i++)
	{
		int temp = 0;
		string award = "Are you kidding?";
		scanf("%d", &temp);
		if (is_exist[temp] == 1)
		{
			if (1 == rank[temp])
			{
				award = "Mystery Award";
			}
			else if (is_prime(rank[temp]))
			{
				award = "Minion";
			}
			else
			{
				award = "Chocolate";
			}
			is_exist[temp] = 2;
		}
		else if (is_exist[temp] == 2)
		{
			award = "Checked";
		}
		printf("%04d: %s\n", temp, award.c_str());
	}
	return 0;
}

bool resolve1116::is_prime(int k)
{
	if (1 == k)
	{
		return false;
	}
	for (int i = 2; i * i <= k; i++)
	{
		if (k%i == 0)
		{
			return false;
		}
	}
	return true;
}