#include "round_2_resolve1001.h"
using namespace round_2_resolve1001;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1001::resolve()
{
	int a = 0, b = 0, c = 0, d = 0;
	scanf("%d %d", &a, &b);
	c = a + b;
	if (c == 0)
	{
		printf("0");
	}
	else
	{
		if (c < 0)
		{
			printf("-");
			c = 0 - c;
		}
		vector<char> nums;
		while (c != 0)
		{
			if (d == 3)
			{
				nums.push_back(',');
				d = 0;
			}
			int e = c % 10;
			nums.push_back(e + 48);
			c = c / 10;
			d++;
		}
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			printf("%c", nums[i]);
		}
	}
	return 0;
}